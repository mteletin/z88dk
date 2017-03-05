//-----------------------------------------------------------------------------
// zlink - linker symbol tables
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "symbol.h"
#include "expr.h"

Symbol::Symbol(unsigned id, const std::string& name)
	: id_(id), name_(name), value_(new UndefExpr), eval_count_(0)
	, variable_(false), defined_(false), external_(false), exported_(false) {}

Symbol::~Symbol() {
	delete value_;
}

Expr* Symbol::value() {
	return value_;
}

void Symbol::set_value(Expr* value) {
	delete value_;
	value_ = value;
}

Result Symbol::eval() {
	if (eval_count_ > 0)
		return Result(0, Result::RECURSIVE);
	
	++eval_count_;
	Result r = value_->eval();
	--eval_count_;

	return r;
}


Symtab::Symtab() {}

Symtab::~Symtab() {
#if 0
	for (std::vector<Symbol*>::iterator it = symbols_.begin(); it != symbols_.end(); ++it)
		delete *it;
	symbols_.clear();
#endif
}
