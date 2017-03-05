//-----------------------------------------------------------------------------
// zlink - object module
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef MODULE_H_
#define MODULE_H_

#include "fwd.h"
#include "symbol.h"
#include <string>

class Module {
public:
	Module(const std::string& name = "");
	virtual ~Module();

private:
	std::string		name_;				// module name
	Symtab			symtab_;

	MK_GET_SET(const std::string&, name);
};

#endif // ndef MODULE_H_
