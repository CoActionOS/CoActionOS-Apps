/*
 * xml_test.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: tgil
 */


#include "tests.h"
#include "Test.hpp"

#include <applib/Xml.hpp>

//create an XML file
static int create_test_file();
static int value_test();


int xml_test(void){
	Timer::wait_msec(500);

	if( create_test_file() < 0 ){ return -1; }
	if( value_test() < 0 ){ return -1; }
	return 0;
}


int value_test(){
	Xml xml;
	Test t;
	String str;
	String key;
	String cmp;
	int i,j;

	cmp.setformat(String::DECIMAL, 8);
	str.setformat(String::DECIMAL, 8);

	t.start("open (readonly)");
	if( xml.init("/media/xml_test.xml", Xml::READONLY) < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("empty value");
	if( xml.value(str, "") == 0 ){ t.failed("should have failed"); return -1; } t.passed();

	t.start("value");
	for(i=0; i < 10; i++){
		for(j=0; j < 10; j++){
			key.clear();
			key << "xml.data[" << i << "].array[" << j << "]";
			if( xml.value(str, key) < 0 ){
				t.failed("failed to find desc");
				printf("didn't find %s\n", key.c_str());
				return -1;
			}
			t.update();
			cmp.clear(); cmp << (i*10+j);
			if( str != cmp ){
				t.failed("compare failed");
				printf("%s != %s\n", str.c_str(), cmp.c_str());
				return -1;
			}
		}
	}
	t.passed();

	t.start("find value");
	if( xml.find("xml") < 0 ){
		t.failed("failed xml");
		return -1;
	}
	for(i=0; i < 10; i++){
		for(j=0; j < 10; j++){
			key.clear();
			key << "data[" << i << "].array[" << j << "]";
			if( xml.value(str, key) < 0 ){
				t.failed("failed to find desc");
				printf("didn't find %s\n", key.c_str());
				return -1;
			}
			t.update();
			cmp.setformat(String::DECIMAL, 8);
			cmp.clear(); cmp << (i*10+j);
			if( str != cmp ){ t.failed("compare failed"); return -1; }
		}
	}
	t.passed();

	t.start("find value array");
	for(i=0; i < 10; i++){
		key.clear();
		key << "xml.data[" << i << "]";
		if( xml.find(key) < 0 ){
			t.failed("failed xml");
			return -1;
		}
		for(j=0; j < 10; j++){
			key.clear();
			key << "array[" << j << "]";
			if( xml.value(str, key) < 0 ){
				t.failed("failed to find desc");
				printf("didn't find %s\n", key.c_str());
				return -1;
			}
			t.update();
			cmp.clear(); cmp << (i*10+j);
			if( str != cmp ){ t.failed("compare failed"); return -1; }
		}
	}
	t.passed();

	t.start("close readonly"); if( xml.close() < 0 ){ t.failed("failed"); return -1; } t.passed();
	t.start("open readwrite"); if( xml.init("/media/xml_test.xml", Xml::READWRITE) < 0 ){ t.failed("failed"); return -1; } t.passed();

	t.start("set value");
	for(i=0; i < 10; i++){
		key.clear();
		key << "xml.data[" << i << "]";
		if( xml.find(key) < 0 ){
			t.failed("failed xml");
			return -1;
		}
		for(j=0; j < 10; j++){
			key.clear();
			key << "array[" << j << "]";
			str.clear();
			str << (99-(i*10+j));
			if( xml.setvalue(str, key) < 0 ){ t.failed("failed to setvalue()"); return -1; }
			t.update();
		}
	}
	t.passed();
	t.start("close (readwrite)"); if( xml.close() < 0 ){ t.failed("failed"); return -1; } t.passed();

	t.start("open (readonly)");
	if( xml.init("/media/xml_test.xml", Xml::READONLY) < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("find value array");
	for(i=0; i < 10; i++){
		key.clear();
		key << "xml.data[" << i << "]";
		if( xml.find(key) < 0 ){
			t.failed("failed xml");
			return -1;
		}
		for(j=0; j < 10; j++){
			key.clear();
			key << "array[" << j << "]";
			if( xml.value(str, key) < 0 ){
				t.failed("failed to find desc");
				printf("didn't find %s\n", key.c_str());
				return -1;
			}
			t.update();
			cmp.clear(); cmp << (99 - (i*10+j));
			if( str != cmp ){
				t.failed("compare failed");
				printf("%s != %s\n", str.c_str(), cmp.c_str());
				return -1;
			}
		}
	}
	t.passed();

	t.start("close readonly"); if( xml.close() < 0 ){ t.failed("failed"); return -1; } t.passed();
	return 0;
}

int create_test_file(){
	Test t;
	Xml xml;
	int i, j;
	String str;

	t.start("create test file");

	Xml::remove("/media/xml_test.xml");

	if( xml.init("/media/xml_test.xml", Xml::WRITEONLY) < 0 ){
		t.failed("failed to create test file");
		perror("failed to open");
		return -1;
	}
	t.passed();

	t.start("write data");
	if( xml.write_start_tag("xml") < 0 ){ t.failed("failed xml start"); return -1; } t.update();
	for(i=0; i < 10; i++){
		if( xml.write_start_tag("data") < 0 ){ t.failed("failed data start"); return -1; } t.update();
		for(j=0; j < 10; j++){
			str.clear();
			str.setformat(String::DECIMAL, 8);
			str << i*10 + j;
			if( xml.write_element("array", str.c_str()) < 0 ){ t.failed("failed array"); return -1; } t.update();
		}
		if( xml.write_end_tag("data") < 0 ){ t.failed("failed data end"); return -1; } t.update();
	}
	if( xml.write_end_tag("xml") < 0 ){ t.failed("failed xml end"); return -1; } t.update();
	t.passed();

	t.start("xml close");
	if( xml.close() < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	return 0;
}
