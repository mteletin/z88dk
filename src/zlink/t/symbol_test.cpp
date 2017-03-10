//-----------------------------------------------------------------------------
// Unit tests
// Copyright (c) Paulo Custodio, 2015-2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "../memcheck.h"
#include "../symbol.h"
#include "taptest.h"

int main() {
	Symbols symbols;
	Symtab  symtab;

	Result r;

	START_TESTING();

	// empty
	OK(symbols.begin() == symbols.end());
	OK(symtab.search("s1") == NULL);
	IS(symtab.scope_level(), 0);

	// add s1
	Symbol* s1 = symbols.add(new Symbol("s1"));
	IS(s1->id(), 0);

	Symbols::SymbolsList::iterator it = symbols.begin();
	OK(*it == s1); ++it;
	OK(it == symbols.end());

	Symbol* s = symtab.add(s1);
	OK(s == s1);
	IS(s->id(), 0);
	OK(symtab.search("s1") == s1);

	// add s2
	Symbol* s2 = symbols.add(new Symbol("s2"));
	IS(s2->id(), 1);

	it = symbols.begin();
	OK(*it == s1); ++it;
	OK(*it == s2); ++it;
	OK(it == symbols.end());

	s = symtab.add(s2);
	OK(s == s2);
	IS(s->id(), 1);
	OK(symtab.search("s1") == s1);
	OK(symtab.search("s2") == s2);

	// replace s2
	Symbol* s2_new = symbols.add(new Symbol("s2"));
	IS(s2_new->id(), 2);

	it = symbols.begin();
	OK(*it == s1); ++it;
	OK(*it == s2); ++it;
	OK(*it == s2_new); ++it;
	OK(it == symbols.end());

	s = symtab.add(s2_new);
	OK(s == s2_new);
	IS(s->id(), 2);
	OK(symtab.search("s1") == s1);
	OK(symtab.search("s2") == s2_new);

	// new scope and another s1
	symtab.enter_scope();
	IS(symtab.scope_level(), 1);

	Symbol* s1_inner = symbols.add(new Symbol("s1"));
	IS(s1_inner->id(), 3);

	it = symbols.begin();
	OK(*it == s1); ++it;
	OK(*it == s2); ++it;
	OK(*it == s2_new); ++it;
	OK(*it == s1_inner); ++it;
	OK(it == symbols.end());

	s = symtab.add(s1_inner);
	OK(s == s1_inner);
	IS(s->id(), 3);
	OK(symtab.search("s1") == s1_inner);
	OK(symtab.search("s2") == s2_new);

	// exit scope
	symtab.exit_scope();
	IS(symtab.scope_level(), 0);

	it = symbols.begin();
	OK(*it == s1); ++it;
	OK(*it == s2); ++it;
	OK(*it == s2_new); ++it;
	OK(*it == s1_inner); ++it;
	OK(it == symbols.end());

	OK(symtab.search("s1") == s1);
	OK(symtab.search("s2") == s2_new);

	// exit from outher level has no effect
	symtab.exit_scope();
	IS(symtab.scope_level(), 0);

	OK(symtab.search("s1") == s1);
	OK(symtab.search("s2") == s2_new);

	DONE_TESTING();
}
