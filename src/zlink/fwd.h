//-----------------------------------------------------------------------------
// zlink - forward declarations
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef FWD_H_
#define FWD_H_

class Expr;
class Library;
class Module;
class Object;
class Reader;
class Section;
class Symbol;
class Symtab;
class Writer;

#define MK_GET(T, N)		public: T N() const { return N##_; }	private:
#define MK_SET(T, N)		public:	void set_##N(T N) { N##_ = N; }	private:
#define MK_GET_SET(T, N)	MK_GET(T, N); MK_SET(T, N);

#endif // ndef FWD_H_
