//-----------------------------------------------------------------------------
// zlink - object file
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef OBJECT_H_
#define OBJECT_H_

#include "fwd.h"
#include "store.h"
#include <string>
#include <vector>

class Object {
public:
	Object(const std::string& name = "");
	virtual ~Object();

	Module* module();									// return current module

	unsigned add_source(const std::string& filename);	// add source if not yet seen, return ID

private:
	std::string		name_;								// object name, normally source file base name
	MK_GET_SET(const std::string&, name);

	std::vector<Module*>	modules_;					// list of modules
#if 0
	Store					sources_;					// list of source files
#endif
};

#endif // ndef OBJECT_H_
