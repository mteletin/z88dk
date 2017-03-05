//-----------------------------------------------------------------------------
// zlink - writer to a file
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "writer.h"
#include "ieee695.h"

#include <cassert>

Writer::Writer(std::ostream& ofs)
	: ofs_(ofs) {
	start_pos_ = ofs_.tellp();
}

Writer::~Writer() {}

void Writer::write_byte(int byte) {
	ofs_.put(static_cast<unsigned char>(byte));
}

void Writer::write_number(int number) {
	if (number >= 0 && number < 128) {
		write_byte(number);
	}
	else {
		// build string
		unsigned char bytes[sizeof(int)];		
		for (unsigned i = 0; i < sizeof(int); i++)
			bytes[i] = ((number >> (8 * i)) & 0xFF);

		// check number of significant bytes
		int nbytes = 4;
		if (number >= 0) {
			while (nbytes > 1 && bytes[nbytes - 1] == 0 && (bytes[nbytes - 2] & 0x80) == 0)
				--nbytes;
		}
		else {
			while (nbytes > 1 && bytes[nbytes - 1] == 0xFF && (bytes[nbytes - 2] & 0x80) == 0x80)
				--nbytes;
		}

		write_byte(REC_NUMBER + nbytes);
		for (int i = nbytes - 1; i >= 0; --i)
			write_byte(bytes[i]);
	}
}

void Writer::write_string(const std::string& text) {
	int len = text.length();
	if (len < 0x80) {
		write_byte(len);
	}
	else if (len < 0x100) {
		write_byte(REC_SHORT_STR);
		write_byte(len);
	}
	else {
		assert(len < 0x10000);
		write_byte(REC_LONG_STR);
		write_byte((len >> 8) & 0xFF);
		write_byte(len & 0xFF);
	}

	ofs_.write(text.c_str(), len);
}
