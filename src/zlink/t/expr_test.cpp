//-----------------------------------------------------------------------------
// Unit tests
// Copyright (c) Paulo Custodio, 2015-2016
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "../memcheck.h"
#include "../expr.h"
#include "../symbol.h"
#include "taptest.h"

#define IS_RES(r,v,e)	IS(r.value, v); IS(r.error, e)
#define IS_RES_OK(r,v)	IS_RES(r, v, Result::OK)
#define IS_RES_ERR(r,e)	IS_RES(r, 0, e)

int main() {
	Result r;

	START_TESTING();

	// power
	r = Expr::power(10, -1); IS_RES_OK(r, 0);
	r = Expr::power(10, 0); IS_RES_OK(r, 1);
	r = Expr::power(10, 1); IS_RES_OK(r, 10);
	r = Expr::power(10, 2); IS_RES_OK(r, 100);
	r = Expr::power(10, 3); IS_RES_OK(r, 1000);

	// divide
	r = Expr::divide(11, 3); IS_RES_OK(r, 3);
	r = Expr::divide(11, 0); IS_RES_ERR(r, Result::DIVIDE_ZERO);

	// modulo
	r = Expr::modulo(11, 3); IS_RES_OK(r, 2);
	r = Expr::modulo(11, 0); IS_RES_ERR(r, Result::DIVIDE_ZERO);

	// undef
	{
		UndefExpr* e1 = new UndefExpr();
		r = e1->eval();
		IS_RES_ERR(r, Result::UNDEFINED);

		Expr* e2 = e1->clone();
		delete e1;

		r = e2->eval();
		IS_RES_ERR(r, Result::UNDEFINED);
		delete e2;
	}

	// number
	{
		NumberExpr* e1 = new NumberExpr(23);
		r = e1->eval();
		IS_RES_OK(r, 23);

		Expr* e2 = e1->clone();
		delete e1;

		r = e2->eval();
		IS_RES_OK(r, 23);
		delete e2;
	}

	// symbol
	{
		Symbol s1(0, "var");
		r = s1.eval();
		IS_RES_ERR(r, Result::UNDEFINED);

		s1.set_value(new NumberExpr(24));
		r = s1.eval();
		IS_RES_OK(r, 24);
	}

	// symbol with recursion
	{
		Symbol s1(0, "var");
		s1.set_value(new SymbolExpr(&s1));
		r = s1.eval();
		IS_RES_ERR(r, Result::RECURSIVE);
	}

	DONE_TESTING();
}
