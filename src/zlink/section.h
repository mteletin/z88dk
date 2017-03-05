//-----------------------------------------------------------------------------
// zlink - section of code/data
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef SECTION_H_
#define SECTION_H_

#include "fwd.h"
#include <string>

class Section {
public:
	Section(const std::string& name = "");
	virtual ~Section();

private:
	std::string		name_;				// module name

	MK_GET_SET(const std::string&, name);
};
#endif // ndef SECTION_H_
