//-----------------------------------------------------------------------------
// Unit tests
// Copyright (c) Paulo Custodio, 2015-2016
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "../memcheck.h"
#include "../linker.h"
#include "taptest.h"

int main() {
	START_TESTING();

	Object* obj;

	// object name
	obj = new Object;
	IS(obj->name(), "");
	obj->set_name("test");
	IS(obj->name(), "test");
	delete obj;

	// object module name
	obj = new Object("test");
	IS(obj->name(), "test");
	IS(obj->module()->name(), "");
	obj->module()->set_name("module1");
	IS(obj->module()->name(), "module1");
	delete obj;

	// source files
	obj = new Object("test");
	IS(obj->add_source("f1.asm"), 0);
	IS(obj->add_source("f2.asm"), 1);
	IS(obj->add_source("f3.asm"), 2);
	IS(obj->add_source("f1.asm"), 0);
	IS(obj->add_source("f2.asm"), 1);
	IS(obj->add_source("f3.asm"), 2);
	delete obj;
	
	DONE_TESTING();
}
