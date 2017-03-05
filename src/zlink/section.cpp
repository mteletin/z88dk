//-----------------------------------------------------------------------------
// zlink - section of code/data
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "section.h"

Section::Section(const std::string& name)
	: name_(name) {}

Section::~Section() {}
