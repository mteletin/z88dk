//-----------------------------------------------------------------------------
// zlink - reader from file
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "reader.h"
#include "ieee695.h"
#include <vector>

Reader::Reader(std::istream& ifs)
	: ifs_(ifs) {
	start_pos_ = ifs_.tellg();
}

Reader::~Reader() {}

bool Reader::read_byte(int& byte) {
	byte = ifs_.get();
	if (byte < 0) {		// end of file
		byte = 0;
		return false;
	}
	else {
		return true;
	}
}

bool Reader::read_number(int& number) {
	int byte, count;
	std::streampos pos = ifs_.tellg();

	if (!read_byte(byte))
		goto error;

	// small number
	if (byte < 0x80) {
		number = byte;
		return true;
	}

	// number too big
	if (byte > 0x88) 
		goto error;

	// count + list of bytes
	count = byte & 0x7F;
	if (count == 0) {
		number = 0;
		return true;
	}
	
	// get most significant byte, contains sign
	if (!read_byte(byte))
		goto error;
	
	if (byte & 0x80)
		number = ~0;		// negative, set to all 1s
	else
		number = 0;			// positive, set to all 0s

	// shift input bytes from right to left
	number = (number << 8) | (byte & 0xFF);
	for (int i = 1; i < count; ++i) {
		if (!read_byte(byte))
			goto error;
		number = (number << 8) | (byte & 0xFF);
	}

	return true;

error:
	number = 0;
	ifs_.seekg(pos);
	return false;
}

bool Reader::read_string(std::string& text) {
	std::streampos pos = ifs_.tellg();
	std::vector<char> bytes;

	int len;
	int byte;
	if (!read_byte(byte))
		goto error;

	if (byte < 0x80) {
		len = byte;
	}
	else if (byte == REC_SHORT_STR) {
		if (!read_byte(byte))
			goto error;
		len = byte;			// up to 256
	}
	else if (byte == REC_LONG_STR) {
		if (!read_byte(byte))
			goto error;
		len = byte << 8;

		if (!read_byte(byte))
			goto error;
		len += byte;
	}
	else {
		goto error;
	}
	
	// read bytes
	text.clear();
	if (len != 0) {
		bytes.resize(len, 0);
		ifs_.read(&bytes[0], len);
		if (!ifs_.good())
			goto error;

		text.append(&bytes[0], len);
	}
	return true;

error:
	text.clear();
	ifs_.seekg(pos);
	return false;
}
