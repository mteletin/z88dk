//-----------------------------------------------------------------------------
// zlink - linker interface
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef LINKER_H_
#define LINKER_H_

#include "fwd.h"
#include "object.h"
#include "module.h"
#include "section.h"
#include "symbol.h"

// Library of object files
class Library {
public:
	Library();
	virtual ~Library();
};

#endif // ndef LINKER_H_
