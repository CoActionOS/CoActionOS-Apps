/*
 * settings_test.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: tgil
 */


#include <applib/Settings.hpp>
#include <applib/Timer.hpp>
#include <limits.h>
#include "Test.hpp"
#include "tests.h"


static int create_test(void);
static int update_test(void);

int settings_test(void){
	if( create_test() < 0 ){
		return -1;
	}

	if( update_test() < 0 ){
		return -1;
	}

	return 0;
}


int create_test(void){
	Test t;
	Settings sett;

	uint32_t value_u32;
	int32_t value_i32;
	uint16_t value_u16;
	int16_t value_i16;
	uint8_t value_u8;
	int8_t value_i8;
	float fvalue = 127.0;
	String str;
	Key key;

	unlink("/home/test.set");
	t.start("create settings");
	if( sett.open("/home/test.set", File::TRUNC | File::CREAT | File::APPEND | File::READWRITE) < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("append test");
	value_u32 = 127;
	value_i32 = 127;
	value_u16 = 127;
	value_i16 = 127;
	value_u8 = 127;
	value_i8 = 127;
	str = "this is string data";
	if( sett.append_key(Key("uint32_t"), Settings::U32, &value_u32) < 0 ){ t.failed("uin32_t failed"); return -1; }
	if( sett.append_key(Key("int32_t"), Settings::I32, &value_u32) < 0 ){ t.failed("int32_t failed"); return -1; }
	if( sett.append_key(Key("uint16_t"), Settings::U16, &value_u32) < 0 ){ t.failed("uint16_t failed"); return -1; }
	if( sett.append_key(Key("int16_t"), Settings::I16, &value_u32) < 0 ){ t.failed("int16_t failed"); return -1; }
	if( sett.append_key(Key("uint8_t"), Settings::U8, &value_u32) < 0 ){ t.failed("uint8_t failed"); return -1; }
	if( sett.append_key(Key("int8_t"), Settings::I8, &value_u32) < 0 ){ t.failed("int8_t failed"); return -1; }
	if( sett.append_key(Key("float"), Settings::FLOAT, &fvalue) < 0 ){ t.failed("float failed"); return -1; }
	if( sett.append_key(Key("string"), Settings::STRING, str.c_str(), str.capacity()) < 0 ){ t.failed("string failed"); return -1; }
	t.passed();


	t.start("close settings");
	if( sett.close() < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	//read back the values that were just set
	t.start("open settings");
	if( sett.open("/home/test.set", File::READONLY) < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("read values");
	str.clear();
	if( sett.value(Key("uint32_t"), value_u32) == false ){ t.failed("failed to load uint32_t"); return -1; }
	if( value_u32 != 127 ){ t.failed("uint32_t is not 127"); return -1; }
	if( sett.value(Key("int32_t"), value_i32) == false ){ t.failed("failed to load int32_t"); return -1; }
	if( value_i32 != 127 ){ t.failed("int32_t is not 127"); return -1; }
	if( sett.value(Key("uint16_t"), value_u16) == false ){ t.failed("failed to load uint16_t"); return -1; }
	if( value_u16 != 127 ){ t.failed("uint16_t is not 127"); return -1; }
	if( sett.value(Key("int16_t"), value_i16) == false ){ t.failed("failed to load int16_t"); return -1; }
	if( value_i16 != 127 ){ t.failed("int16_t is not 127"); return -1; }
	if( sett.value(Key("uint8_t"), value_u8) == false ){ t.failed("failed to load uint8_t"); return -1; }
	if( value_u8 != 127 ){ t.failed("uint8_t is not 127"); return -1; }
	if( sett.value(Key("int8_t"), value_i8) == false ){ t.failed("failed to load int8_t"); return -1; }
	if( value_i8 != 127 ){ t.failed("int8_t is not 127"); return -1; }
	fvalue = 0.0;
	if( sett.value(Key("float"), fvalue) == false ){ t.failed("failed to load float"); return -1; }
	if( fvalue != 127.0 ){ t.failed("float is not 127.0"); return -1; }
	str.clear();
	if( sett.value(Key("string"), str.cdata(), str.capacity()) == false ){ t.failed("failed to load string"); return -1; }
	if( str !=  "this is string data" ){ t.failed("string is not right"); return -1; }
	t.passed();


	t.start("close readonly settings");
	if( sett.close() < 0 ){ t.failed("failed"); return -1; }
	t.passed();


	return 0;
}

int update_test(void){
	Test t;
	Settings sett;

	uint32_t value_u32;
	int32_t value_i32;
	uint16_t value_u16;
	int16_t value_i16;
	uint8_t value_u8;
	int8_t value_i8;
	float fvalue = 127.0;
	String str;

	t.start("open settings (read/write)");
	if( sett.open("/home/test.set", File::READWRITE) < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	t.start("set values");
	value_u32 = 100;
	value_i32 = 100;
	value_u16 = 127;
	value_i16 = 127;
	value_u8 = 127;
	value_i8 = 127;
	if( sett.set(Key("uint32_t"), value_u32) < 0 ){ t.failed("failed to set uint32_t"); return -1; };
	if( sett.set(Key("int32_t"), value_i32) < 0 ){ t.failed("failed to set int32_t"); return -1; };

	t.passed();

	t.start("close settings");
	if( sett.close() < 0 ){ t.failed("failed"); return -1; }
	t.passed();

	//read back the values that were just set
	t.start("open settings");
	if( sett.open("/home/test.set", File::READONLY) < 0 ){ t.failed("failed"); return -1; }
	t.passed();


	t.start("read values");
	str.clear();
	if( sett.value(Key("uint32_t"), value_u32) == false ){ t.failed("failed to load uint32_t"); return -1; }
	if( value_u32 != 100 ){ t.failed("uint32_t is not 100"); printf("%ld != 100\n", value_u32); return -1; }
	if( sett.value(Key("int32_t"), value_i32) == false ){ t.failed("failed to load int32_t"); return -1; }
	if( value_i32 != 100 ){ t.failed("int32_t is not 127"); return -1; }
	if( sett.value(Key("uint16_t"), value_u16) == false ){ t.failed("failed to load uint16_t"); return -1; }
	if( value_u16 != 127 ){ t.failed("uint16_t is not 127"); return -1; }
	if( sett.value(Key("int16_t"), value_i16) == false ){ t.failed("failed to load int16_t"); return -1; }
	if( value_i16 != 127 ){ t.failed("int16_t is not 127"); return -1; }
	if( sett.value(Key("uint8_t"), value_u8) == false ){ t.failed("failed to load uint8_t"); return -1; }
	if( value_u8 != 127 ){ t.failed("uint8_t is not 127"); return -1; }
	if( sett.value(Key("int8_t"), value_i8) == false ){ t.failed("failed to load int8_t"); return -1; }
	if( value_i8 != 127 ){ t.failed("int8_t is not 127"); return -1; }
	fvalue = 0.0;
	if( sett.value(Key("float"), fvalue) == false ){ t.failed("failed to load float"); return -1; }
	if( fvalue != 127.0 ){ t.failed("float is not 127.0"); return -1; }

	str.mincapacity(32); //give str some memory
	if( sett.value(Key("string"), str.cdata(), str.capacity()) == false ){ t.failed("failed to load string"); return -1; }
	if( str != "this is string data" ){
		t.failed("string is not right");
		printf("-%s-\n", str.c_str());
		return -1;
	}
	t.passed();


	t.start("close readonly settings");
	if( sett.close() < 0 ){ t.failed("failed"); return -1; }
	t.passed();


	return 0;
}
