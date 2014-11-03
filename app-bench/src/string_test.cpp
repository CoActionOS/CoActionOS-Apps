/*
 * string_test.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: tgil
 */


#include <applib/String.hpp>
#include <applib/Timer.hpp>
#include <limits.h>
#include "Test.hpp"
#include "tests.h"

int string_test(void){
	Test t;
	int i;
	t.start("assign cdata");

	String str;
	String other;

	str = "hello";
	t.update();
	if( str != "hello" ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("assign String");
	other = "hello";
	str = other;
	t.update();
	if( str != "hello" ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("is empty");
	str.clear(); t.update();
	if( !str.empty() ){ t.failed("not empty"); return -1; }
	t.update();
	str = "hello";
	if( str.empty() ){ t.failed("shoudn't be empty"); return -1; }
	t.passed();

	t.start("append cdata");
	str = "he"; t.update();
	str << "llo"; t.update();
	if( str != "hello" ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("append String");
	other = "llo";
	str = "he"; t.update();
	str << other; t.update();
	if( str != "hello" ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("append char");
	str = "hell"; t.update();
	str << 'o'; t.update();
	if( str != "hello" ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("== String");
	other = "hello";
	str = "hello"; t.update();
	if( !(str == other) ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("!= String");
	other = "hello";
	str = "hello"; t.update();
	if( (str != other) ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("== cdata");
	str = "hello"; t.update();
	if( !(str == "hello") ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("!= cdata");
	str = "hello"; t.update();
	if( (str != "hello") ){ t.failed("failed"); return -1; }
	t.passed();


	t.start("insert cdata");
	str = "hlo";
	str.insert(1, "el");
	if( (str != "hello") ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("insert String");
	other = "el";
	str = "hlo";
	str.insert(1, other);
	if( (str != "hello") ){ t.failed("failed"); return -1; }
	t.passed();


	t.start("erase");
	str = "helloworld";
	str.erase(strlen("hello"));
	if( (str != "hello") ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("erase len");
	str = "helworldlo";
	str.erase(strlen("hel"), strlen("world"));
	if( (str != "hello") ){ t.failed("failed"); return -1; }
	t.passed();


	t.start("at");
	str = "hello"; t.update(); t.update(); t.update();
	if(
			(str.at(0) != 'h') ||
			(str.at(1) != 'e') ||
			(str.at(2) != 'l') ||
			(str.at(3) != 'l') ||
			(str.at(4) != 'o') ){
		t.failed("failed"); return -1;
	}
	t.passed();

	t.start("at beyond");
	str = "hello";
	if( str.at(10) != 0 ){ t.failed("failed"); return -1; }
	t.passed();


	t.start("at empty");
	str = "";
	if( str.at(10) != 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("size empty");
	str = "";
	if( str.size() != 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("size");
	str = "hello";
	if( str.size() != strlen("hello") ){ t.failed("failed"); return -1; }
	t.passed();


	t.start("copy");
	other.resize(17);
	other.clear();
	str.copy(other.cdata(), 17);
	if( other != "hello" ){ t.failed("failed"); return -1; }
	str = "xhello"; t.update();
	str.copy(other.cdata(), 17, 1);
	if( other != "hello" ){ t.failed("failed"); return -1; }
	if( str.copy(other.cdata(), 17, str.size()) != 0 ) {
		t.failed("should have been zero"); return -1;
	}
	t.passed();

	t.start("find");
	str = "hello";
	if( str.find("llo") != 2 ){ t.failed("failed llo"); return -1; } t.update();
	if( str.find("x") != (size_t)String::npos ){ t.failed("failed x"); return -1; } t.update();
	if( str.find("he") != 0 ){ t.failed("failed he"); return -1; } t.update();
	if( str.find("lo", 1, str.size()) != 3 ){ t.failed("failed lo"); return -1; } t.update();
	if( str.find("ellx", 1, 3) != 1 ){ t.failed("failed ellx"); return -1; } t.update();
	if( str.find("hellx", 1, 3) != (size_t)String::npos ){ t.failed("failed hellx"); return -1; } t.update();
	t.passed();


	t.start("rfind");
	str = "hello";
	if( str.rfind("llo") != 2 ){ t.failed("failed llo"); return -1; } t.update();
	if( str.rfind("x") != (size_t)String::npos ){
		t.failed("failed x");
		printf("%d\n", str.rfind("x"));
		return -1;
	}
	t.update();
	if( str.rfind("he") != 0 ){ t.failed("failed he"); return -1; } t.update();
	if( str.rfind("lo", 1, str.size()) != 3 ){ t.failed("failed lo"); return -1; } t.update();
	if( str.rfind("ellx", 1, 3) != 1 ){ t.failed("failed ellx"); return -1; } t.update();
	if( str.rfind("hellx", 1, 3) != (size_t)String::npos ){ t.failed("failed hellx"); return -1; } t.update();
	t.passed();



	t.start("compare");
	str = "hello";
	other = "helloworld";
	if( str.compare("hello") != 0 ){ t.failed("failed hello"); return -1; } t.update();
	if( str.compare("a") >= 0 ){ t.failed("failed a"); return -1; } t.update();
	if( str.compare("z") <= 0 ){ t.failed("failed z"); return -1; } t.update();
	if( str.compare("hel") >= 0 ){ t.failed("failed hel"); return -1; } t.update();
	if( str.compare("hellox") <= 0 ){ t.failed("failed hellox"); return -1; } t.update();
	if( str.compare(2, 3, "llo") != 0 ){ t.failed("failed llo"); return -1; } t.update();
	if( str.compare(2, 4, "llo") != 0 ){ t.failed("failed llo (2)"); return -1; } t.update();
	if( str.compare(2, 4, "hello") <= 0 ){ t.failed("failed llo (2)"); return -1; } t.update();
	if( str.compare(other) <= 0 ){ t.failed("other"); return -1; } t.update();
	if( str.compare(0, str.size(), "helloworld") != 0 ){ t.failed("helloworld"); return -1; } t.update();
	if( str.compare(0, str.size(), other, 0, other.size()) <= 0 ){ t.failed("other"); return -1; } t.update();
	if( str.compare(0, str.size()-1, other, 0, str.size()) <= 0 ){ t.failed("other sizes"); return -1; } t.update();
	t.passed();

	StringTiny str_tiny;

	t.start("tiny");
	if( str_tiny.capacity() != 16 ){ t.failed("capacity"); return -1; } t.update();
	if( str_tiny.size() != 0 ){ t.failed("capacity"); return -1; } t.update();
	if( str_tiny.resize(32) == 0 ){ t.failed("should have failed resize"); return -1; } t.update();
	t.passed();

	t.start("append int");
	printf(" ");
	str.clear();
	str << INT_MAX;
	if( str.atoi() != INT_MAX){ t.failed("INT_MAX failed"); return -1; }

	for(i=INT_MIN; i < INT_MAX-1000000; i+=813501){
		str.clear();
		str << i; t.update();
		if( str.atoi() != i ){
			t.failed("failed");
			printf("failed at %d %s != %d\n", i, str.c_str(), i);
			return -1;
		}
	}
	t.passed();
	return 0;
}

