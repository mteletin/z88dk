//-----------------------------------------------------------------------------
// zlink - linker symbol tables
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "fwd.h"
#include "store.h"
#include "result.h"
#include <string>
#include <vector>

// one symbol
class Symbol {
public:
	Symbol(const std::string& name);
	virtual ~Symbol();

	Expr* value();
	void set_value(Expr* value);

	Result eval();

private:
	unsigned		id_;					// id
	std::string		name_;					// symbol name
	Expr*			value_;					// symbol value
	int				eval_count_;			// check for recursive evals

	bool			variable_;				// true if value can be changed
	bool			defined_;				// true if defined
	bool			external_;				// true if defined elsewhere
	bool			exported_;				// true if exported out

	MK_GET(const std::string&, name);

	MK_GET_SET(unsigned, id);
	MK_GET_SET(bool, variable);
	MK_GET_SET(bool, defined);
	MK_GET_SET(bool, external);
	MK_GET_SET(bool, exported);
};


// Holds all symbols in an object file
class Symbols {
public:
	typedef std::vector<Symbol*> SymbolsList;	// holds objects

	Symbols();
	virtual ~Symbols();

	Symbol* add(Symbol* symbol);				// sets symbol->id, adds to list, returns itself
	SymbolsList::iterator begin();				// iterator
	SymbolsList::iterator end();

private:
	SymbolsList	symbols_;
};


// holds stack of scopes, each scope is a map of name to weak Symbol*
class Symtab {
public:
	typedef std::map<std::string, Symbol*>	SymbolsMap;	// weak pointers
	typedef std::vector<SymbolsMap*>		MapList;	// holds objects

	Symtab();
	virtual ~Symtab();

	void enter_scope();
	void exit_scope();
	unsigned scope_level();

	Symbol* search(const std::string& name);	// search in all scopes, NULL if not found
	Symbol* add(Symbol* symbol);				// add to current scope level, symbol is weak pointer

private:
	MapList		list_;
};

#endif // ndef SYMBOL_H_
