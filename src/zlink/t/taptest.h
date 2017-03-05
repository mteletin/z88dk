//-----------------------------------------------------------------------------
// taptest.h -- Macros to implement TAP tests
// NOTE: defines global variables, must be included only in main module
// Copyright (c) Paulo Custodio, 2015-2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef T_TAPTEST_H_
#define T_TAPTEST_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdio>
#include <sys/stat.h>

static int failed_nr = 0;
static int test_nr = 0;

#define DIAG(out) std::cout << "# " << out << std::endl

#define _OK(cond, has_diag, diag) \
    if (cond) \
        std::cout << "ok " << (++test_nr) << std::endl; \
    else { \
        failed_nr++; \
        std::cout << "not ok " << (++test_nr) << std::endl; \
        DIAG("  Failed test at " << __FILE__ << " line " << __LINE__ << "."); \
        if (has_diag) DIAG(diag); \
    }

#define OK(cond)        _OK((cond),     0, "")
#define NOK(cond)       _OK(!(cond),    0, "")
#define IS(a, b)        _OK((a) == (b), 1, (a))
#define ISNT(a, b)      _OK((a) != (b), 1, (a))
#define PASS()          _OK(true,       0, "")
#define FAIL()          _OK(false,      0, "")

#define T_STR(a, b) { \
		std::string sa(a); \
		std::string sb(b); \
		OK(sa == sb); \
		if (sa != sb) { DIAG("<<<"); DIAG(sa); DIAG(">>>"); DIAG(sb); DIAG("---"); } \
	}

#define START_CAPTURE() \
		{	std::ostringstream strout, strerr; \
			opts.set_out_err(strout, strerr)

#define END_CAPTURE(out_, err_) \
			opts.set_out_err(); \
			T_STR(out_, strout.str()); \
			T_STR(err_, strerr.str()); \
		}

#define START_TESTING() \
	try { \

#define DONE_TESTING() \
		PASS(); \
	} catch(std::exception&) { \
		FAIL(); \
	} \
	std::cout << "1.." << test_nr << std::endl; \
	if (failed_nr == 0) { \
		return 0; \
	} else { \
		DIAG("Looks like you failed " << failed_nr << " test" << \
				(failed_nr > 1 ? "s" : "") << " of " << test_nr << "."); \
		return 1; \
	}

// create test file
inline void create_test_file(const char* filename, const char* text)
{
	std::ofstream file(filename, std::ios::binary);
	if (!file.good()) {
		std::perror(filename);
		FAIL();
	}
	else {
		PASS();
		file << text;
		file.close();
	}
}

// delete test file
inline void delete_test_file(const char* filename)
{
	struct stat status;
	if (stat(filename, &status) == 0) {		// file exists
		if (std::remove(filename) != 0) {	// remove failed
			std::perror(filename);
			FAIL();
		}
	}
}

#endif // T_TAPTEST_H_
