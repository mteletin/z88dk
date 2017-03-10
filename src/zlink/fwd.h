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

#define FOREACH_VECTOR(it_, type_, name_) \
			for (std::vector<type_>::iterator it_ = name_.begin(); it_ != name_.end(); ++it_)

#define FOREACH_VECTOR_REVERSE(it_, type_, name_) \
			for (std::vector<type_>::reverse_iterator it_ = name_.rbegin(); it_ != name_.rend(); ++it_)

#endif // ndef FWD_H_
