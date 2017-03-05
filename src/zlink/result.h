//-----------------------------------------------------------------------------
// zlink - expression result
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef RESULT_H_
#define RESULT_H_

#include "fwd.h"

struct Result {
	// error masks
	static const unsigned OK = 0;
	static const unsigned DIVIDE_ZERO = 1;	// division or modulo by zero
	static const unsigned UNDEFINED = 2;	// used symbol or address not defined
	static const unsigned EXTERNAL = 4;		// depends on external symbol
	static const unsigned RECURSIVE = 8;	// symbol refers back to itself

	// data
	int			value;
	unsigned	error;	// bit-mask

	// constructor
	Result(int value = 0, unsigned error = OK)
		: value(value), error(error) {}
};

#endif // ndef RESULT_H_
