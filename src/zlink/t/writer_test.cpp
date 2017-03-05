//-----------------------------------------------------------------------------
// Unit tests
// Copyright (c) Paulo Custodio, 2015-2016
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "../memcheck.h"
#include "../writer.h"
#include "../reader.h"
#include "taptest.h"

int main() {
	START_TESTING();

	{
		std::ofstream ofs("test.o", std::ofstream::binary);
		Writer wrt(ofs);

#define T(func, in, nbytes, data, var, out)	wrt.write_##func(in);
#include "writer_test.def"
#undef T
	}
	{
		std::ifstream ifs("test.o", std::ofstream::binary);
		
#define T(func, in, nbytes, data, var, out)	for (int i=0; i<nbytes; ++i) \
											IS(ifs.get(), static_cast<unsigned char>(data[i]));
#include "writer_test.def"
#undef T
	}
	{
		int num;
		std::string text;
		
		std::ifstream ifs("test.o", std::ofstream::binary);
		Reader rdr(ifs);

#define T(func, in, nbytes, data, var, out)	OK(rdr.read_##func(var)); IS(var, out);
#include "writer_test.def"
#undef T
	}

	// test errors
	create_test_file("test.o", "");
	{
		int num;
		
		std::ifstream ifs("test.o", std::ofstream::binary);
		Reader rdr(ifs);

		num = -1; 
		OK(!rdr.read_byte(num)); 
		IS(num, 0); 
	}
	
	create_test_file("test.o", "\x81");
	{
		int num;
		
		std::ifstream ifs("test.o", std::ofstream::binary);
		Reader rdr(ifs);

		num = -1; 
		OK(!rdr.read_number(num)); 
		IS(num, 0); 
	}
	
	create_test_file("test.o", "\x90");
	{
		int num;
		std::string text;
		std::streampos pos1, pos2;
		
		std::ifstream ifs("test.o", std::ofstream::binary);
		Reader rdr(ifs);

		num = -1; 
		pos1 = ifs.tellg();
		OK(!rdr.read_number(num)); 
		pos2 = ifs.tellg();
		IS(num, 0); 
		IS(pos1, pos2);

		text = "???";
		pos1 = ifs.tellg();
		OK(!rdr.read_string(text));
		pos2 = ifs.tellg();
		IS(text, "");
		IS(pos1, pos2);
	}
	
	create_test_file("test.o", "\x88\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF");
	{
		int num;
		std::string text;

		std::ifstream ifs("test.o", std::ofstream::binary);
		Reader rdr(ifs);

		num = 0;
		OK(rdr.read_number(num));
		IS(num, -1);
	}


	//delete_test_file("test.o");

	DONE_TESTING();
}
