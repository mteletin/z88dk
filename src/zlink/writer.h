//-----------------------------------------------------------------------------
// zlink - writer to a file
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef WRITER_H_
#define WRITER_H_

#include "fwd.h"
#include <iostream>

class Writer {
public:
	Writer(std::ostream& ofs);
	virtual ~Writer();

	void write_byte(int byte);
	void write_number(int number);
	void write_string(const std::string& text);

private:
	std::ostream&	ofs_;
	std::streampos	start_pos_;
};

#endif // ndef WRITER_H_
