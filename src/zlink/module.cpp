//-----------------------------------------------------------------------------
// zlink - object module
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "module.h"
#include "ieee695.h"
#include "writer.h"

Module::Module(const std::string& name)
	: name_(name) {}

Module::~Module() {}
