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

class Symbol {
public:
	Symbol(unsigned id, const std::string& name = "");
	virtual ~Symbol();

	Expr* value();
	void set_value(Expr* value);

	Result eval();

private:
	unsigned		id_;					// unique id in this module
	std::string		name_;					// symbol name
	Expr*			value_;					// symbol value
	int				eval_count_;			// check for recursive evals

	bool			variable_;				// true if value can be changed
	bool			defined_;				// true if defined
	bool			external_;				// true if defined elsewhere
	bool			exported_;				// true if exported out

	MK_GET(unsigned, id);
	MK_GET(const std::string&, name);

	MK_GET_SET(bool, variable);
	MK_GET_SET(bool, defined);
	MK_GET_SET(bool, external);
	MK_GET_SET(bool, exported);
};

class Symtab {
public:
	Symtab();
	virtual ~Symtab();

private:
#if 0
	Store					symids_;			// map name to ID
	std::vector<Symbol*>	symbols_;			// map ID to symbol
#endif
};

#endif // ndef SYMBOL_H_
