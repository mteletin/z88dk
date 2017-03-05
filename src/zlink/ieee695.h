//-----------------------------------------------------------------------------
// zlink - IEEE-695 definitions
// Copyright (c) Paulo Custodio, 2017
// Based on pyObjUtils (C) 2010-2016 by Christoph Schueler <github.com/Christoph2, cpu12.gems@googlemail.com>
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef IEEE695_H_
#define IEEE695_H_

#include <cctype>

enum RecordTypes {
	REC_NUMBER = 0x80,		// number prefix
	REC_MB = 0xE0,			// module begin
	REC_AS = 0xE2,			// variable assign
	REC_AD = 0xEC,			// address descriptor
	REC_SHORT_STR = 0xDE,	// byte-length string
	REC_LONG_STR = 0xDF,	// word-length string
};

inline int REC_LETTER(char letter) { return toupper(letter) - 'A' + 0xC1; }

#endif // ndef IEEE695_H_
