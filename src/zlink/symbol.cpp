//-----------------------------------------------------------------------------
// zlink - linker symbol tables
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "symbol.h"
#include "expr.h"

Symbol::Symbol(const std::string& name)
	: id_(0), name_(name), value_(new UndefExpr), eval_count_(0)
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


//-----------------------------------------------------------------------------
Symbols::Symbols() {}

Symbols::~Symbols() {
	FOREACH_VECTOR(it, Symbol*, symbols_)
		delete *it;
}

Symbol* Symbols::add(Symbol* symbol) {
	unsigned id = symbols_.size();
	symbol->set_id(id);
	symbols_.push_back(symbol);
	return symbol;
}

Symbols::SymbolsList::iterator Symbols::begin() {
	return symbols_.begin();
}

Symbols::SymbolsList::iterator Symbols::end() {
	return symbols_.end();
}

//-----------------------------------------------------------------------------
Symtab::Symtab() {
	enter_scope();
}

Symtab::~Symtab() {
	FOREACH_VECTOR(it, SymbolsMap*, list_)
		delete *it;
}

void Symtab::enter_scope() {
	list_.push_back(new SymbolsMap);
}

void Symtab::exit_scope() {
	if (scope_level() > 0) {			// must keep at least one map
		delete list_.back();
		list_.pop_back();
	}
}

unsigned Symtab::scope_level() {
	return list_.size() - 1;
}

Symbol* Symtab::search(const std::string& name) {
	FOREACH_VECTOR_REVERSE(it, SymbolsMap*, list_) {
		SymbolsMap* cur_scope = *it;
		std::map<std::string, Symbol*>::iterator found = cur_scope->find(name);
		if (found != cur_scope->end())
			return found->second;
	}
	return NULL;		// not found
}

Symbol* Symtab::add(Symbol* symbol) {
	const std::string& name = symbol->name();
	SymbolsMap* cur_scope = list_.back();
	std::map<std::string, Symbol*>::iterator found = cur_scope->find(name);
	if (found == cur_scope->end()) {
		// new symbol
		cur_scope->insert(std::pair<std::string, Symbol*>(name, symbol));
	}
	else {
		// replace symbol
		found->second = symbol;
	}
	return symbol;
}
