//-----------------------------------------------------------------------------
// zlink - object file
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "object.h"
#include "store.h"
#include "module.h"

Object::Object(const std::string& name) 
	: name_(name) {
	// create default module
	Module* module = new Module("");
	modules_.push_back(module);
}

Object::~Object() {
	for (std::vector<Module*>::iterator it = modules_.begin(); it != modules_.end(); ++it)
		delete *it;
	modules_.clear();
}

Module* Object::module() {
	return modules_.back();
}

unsigned Object::add_source(const std::string& filename) {
#if 0
	return sources_.add(filename);
#else
	return 0;
#endif
}

