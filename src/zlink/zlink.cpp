//-----------------------------------------------------------------------------
// zlink - z80 linker
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "module.h"
#include "writer.h"
#include <iostream>
#include <fstream>

int main() {
#if 0
	Module module("test");
	std::ofstream ofs("test.o", std::ofstream::binary);

	if (!ofs.good()) {
		std::perror("test.o");
		exit(1);
	}

	module.write(ofs);
#endif
}