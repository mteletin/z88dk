//-----------------------------------------------------------------------------
// zlink - reader from file
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef READER_H_
#define READER_H_

#include "fwd.h"
#include <iostream>

class Reader {
public:
	Reader(std::istream& ifs);
	virtual ~Reader();

	bool read_byte(int& byte);
	bool read_number(int& number);
	bool read_string(std::string& text);

private:
	std::istream&	ifs_;
	std::streampos	start_pos_;
};

#endif // ndef READER_H_
