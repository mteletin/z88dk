//-----------------------------------------------------------------------------
// Unit tests
// Copyright (c) Paulo Custodio, 2015-2017
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

	// logical ident
	r = Expr::logical_ident(0); IS_RES_OK(r, 0);
	r = Expr::logical_ident(1); IS_RES_OK(r, 1);
	r = Expr::logical_ident(-1); IS_RES_OK(r, 1);

	// logical not
	r = Expr::logical_not(0); IS_RES_OK(r, 1);
	r = Expr::logical_not(1); IS_RES_OK(r, 0);
	r = Expr::logical_not(-1); IS_RES_OK(r, 0);

	// equal
	r = Expr::equal(1, 0); IS_RES_OK(r, 0);
	r = Expr::equal(1, 1); IS_RES_OK(r, 1);
	r = Expr::equal(1, 2); IS_RES_OK(r, 0);

	// not_equal
	r = Expr::not_equal(1, 0); IS_RES_OK(r, 1);
	r = Expr::not_equal(1, 1); IS_RES_OK(r, 0);
	r = Expr::not_equal(1, 2); IS_RES_OK(r, 1);

	// less
	r = Expr::less(1, 0); IS_RES_OK(r, 0);
	r = Expr::less(1, 1); IS_RES_OK(r, 0);
	r = Expr::less(1, 2); IS_RES_OK(r, 1);

	// greater
	r = Expr::greater(1, 0); IS_RES_OK(r, 1);
	r = Expr::greater(1, 1); IS_RES_OK(r, 0);
	r = Expr::greater(1, 2); IS_RES_OK(r, 0);

	// less_equal
	r = Expr::less_equal(1, 0); IS_RES_OK(r, 0);
	r = Expr::less_equal(1, 1); IS_RES_OK(r, 1);
	r = Expr::less_equal(1, 2); IS_RES_OK(r, 1);

	// greater_equal
	r = Expr::greater_equal(1, 0); IS_RES_OK(r, 1);
	r = Expr::greater_equal(1, 1); IS_RES_OK(r, 1);
	r = Expr::greater_equal(1, 2); IS_RES_OK(r, 0);

	// binary not
	r = Expr::binary_not(0); IS_RES_OK(r, ~0);
	r = Expr::binary_not(0xFF); IS_RES_OK(r, ~0xFF);

	// binary or
	r = Expr::binary_or(0, 0); IS_RES_OK(r, 0);
	r = Expr::binary_or(0, 1); IS_RES_OK(r, 1);
	r = Expr::binary_or(1, 0); IS_RES_OK(r, 1);
	r = Expr::binary_or(1, 1); IS_RES_OK(r, 1);
	r = Expr::binary_or(0xAA, 0x55); IS_RES_OK(r, 0xFF);

	// binary xor
	r = Expr::binary_xor(0, 0); IS_RES_OK(r, 0);
	r = Expr::binary_xor(0, 1); IS_RES_OK(r, 1);
	r = Expr::binary_xor(1, 0); IS_RES_OK(r, 1);
	r = Expr::binary_xor(1, 1); IS_RES_OK(r, 0);
	r = Expr::binary_xor(0xAA, 0xFF); IS_RES_OK(r, 0x55);

	// binary and
	r = Expr::binary_and(0, 0); IS_RES_OK(r, 0);
	r = Expr::binary_and(0, 1); IS_RES_OK(r, 0);
	r = Expr::binary_and(1, 0); IS_RES_OK(r, 0);
	r = Expr::binary_and(1, 1); IS_RES_OK(r, 1);
	r = Expr::binary_and(0xAA, 0x55); IS_RES_OK(r, 0);

	// right_shift
	r = Expr::right_shift(6, 0); IS_RES_OK(r, 6);
	r = Expr::right_shift(6, 1); IS_RES_OK(r, 3);
	r = Expr::right_shift(6, 2); IS_RES_OK(r, 1);

	// left_shift
	r = Expr::left_shift(6, 0); IS_RES_OK(r, 6);
	r = Expr::left_shift(6, 1); IS_RES_OK(r, 12);
	r = Expr::left_shift(6, 2); IS_RES_OK(r, 24);

	// negate
	r = Expr::negate(-1); IS_RES_OK(r, 1);
	r = Expr::negate(0); IS_RES_OK(r, 0);
	r = Expr::negate(1); IS_RES_OK(r, -1);

	// power
	r = Expr::power(10, -1); IS_RES_OK(r, 0);
	r = Expr::power(10, 0); IS_RES_OK(r, 1);
	r = Expr::power(10, 1); IS_RES_OK(r, 10);
	r = Expr::power(10, 2); IS_RES_OK(r, 100);
	r = Expr::power(10, 3); IS_RES_OK(r, 1000);

	// modulo
	r = Expr::modulo(11, 3); IS_RES_OK(r, 2);
	r = Expr::modulo(11, 0); IS_RES_ERR(r, Result::DIVIDE_ZERO);

	// divide
	r = Expr::divide(11, 3); IS_RES_OK(r, 3);
	r = Expr::divide(11, 0); IS_RES_ERR(r, Result::DIVIDE_ZERO);

	// multiply
	r = Expr::multiply(11, 0); IS_RES_OK(r, 0);
	r = Expr::multiply(11, 1); IS_RES_OK(r, 11);
	r = Expr::multiply(11, 2); IS_RES_OK(r, 22);

	// minus
	r = Expr::minus(11, 0); IS_RES_OK(r, 11);
	r = Expr::minus(11, 1); IS_RES_OK(r, 10);
	r = Expr::minus(11, 2); IS_RES_OK(r, 9);

	// plus
	r = Expr::plus(11, 0); IS_RES_OK(r, 11);
	r = Expr::plus(11, 1); IS_RES_OK(r, 12);
	r = Expr::plus(11, 2); IS_RES_OK(r, 13);

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
		Symbol s1("var");
		r = s1.eval();
		IS_RES_ERR(r, Result::UNDEFINED);

		s1.set_value(new NumberExpr(24));
		r = s1.eval();
		IS_RES_OK(r, 24);
	}

	// symbol with recursion
	{
		Symbol s1("var");
		s1.set_value(new SymbolExpr(&s1));
		r = s1.eval();
		IS_RES_ERR(r, Result::RECURSIVE);
	}

	// unary expression
	{
		Expr* num = new NumberExpr(23);
		Expr* e1 = new UnaryExpr(Expr::negate, num);
		r = e1->eval();
		IS_RES_OK(r, -23);
		Expr* e2 = e1->clone();
		delete e1;
		r = e2->eval();
		IS_RES_OK(r, -23);
		delete e2;
	}

	// unary expression with error
	{
		Expr* num0 = new NumberExpr(0);
		Expr* num1 = new NumberExpr(1);
		Expr* e1 = new BinaryExpr(Expr::divide, num1, num0);
		Expr* e2 = new UnaryExpr(Expr::negate, e1);
		r = e2->eval();
		IS_RES_ERR(r, Result::DIVIDE_ZERO);
		Expr* e3 = e2->clone();
		delete e2;
		r = e3->eval();
		IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e3;
	}

	// binary expression
	{
		Expr* num23 = new NumberExpr(23);
		Expr* num31 = new NumberExpr(31);
		Expr* e1 = new BinaryExpr(Expr::plus, num23,num31);
		r = e1->eval();
		IS_RES_OK(r, 54);
		Expr* e2 = e1->clone();
		delete e1;
		r = e2->eval();
		IS_RES_OK(r, 54);
		delete e2;
	}

	// binary expression with error
	{
		Expr* num0 = new NumberExpr(0);
		Expr* num1 = new NumberExpr(1);
		Expr* num2 = new NumberExpr(2);
		Expr* e1 = new BinaryExpr(Expr::divide, num1, num0);
		Expr* e2 = new BinaryExpr(Expr::plus, num2, e1);
		r = e2->eval();
		IS_RES_ERR(r, Result::DIVIDE_ZERO);
		Expr* e3 = e2->clone();
		delete e2;
		r = e3->eval();
		IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e3;
	}

	// logical or
	{
		Expr* e1 = new LogicalOrExpr(new NumberExpr(0), new NumberExpr(0));
		r = e1->eval(); IS_RES_OK(r, 0);
		delete e1;

		e1 = new LogicalOrExpr(new NumberExpr(0), new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 2);
		delete e1;

		e1 = new LogicalOrExpr(new NumberExpr(0),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)));
		r = e1->eval(); IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e1;

		e1 = new LogicalOrExpr(new NumberExpr(1), new NumberExpr(0));
		r = e1->eval(); IS_RES_OK(r, 1);
		delete e1;

		e1 = new LogicalOrExpr(new NumberExpr(1), new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 1);
		delete e1;

		e1 = new LogicalOrExpr(new NumberExpr(1),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)));
		r = e1->eval(); IS_RES_OK(r, 1);
		delete e1;
	}

	// logical and
	{
		Expr* e1 = new LogicalAndExpr(new NumberExpr(0), new NumberExpr(0));
		r = e1->eval(); IS_RES_OK(r, 0);
		delete e1;

		e1 = new LogicalAndExpr(new NumberExpr(0), new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 0);
		delete e1;

		e1 = new LogicalAndExpr(new NumberExpr(0),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)));
		r = e1->eval(); IS_RES_OK(r, 0);
		delete e1;

		e1 = new LogicalAndExpr(new NumberExpr(1), new NumberExpr(0));
		r = e1->eval(); IS_RES_OK(r, 0);
		delete e1;

		e1 = new LogicalAndExpr(new NumberExpr(1), new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 2);
		delete e1;

		e1 = new LogicalAndExpr(new NumberExpr(1),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)));
		r = e1->eval(); IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e1;
	}

	// logical if
	{
		Expr* e1 = new LogicalIfExpr(
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)),
			new NumberExpr(1),
			new NumberExpr(2));
		r = e1->eval(); IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e1;

		e1 = new LogicalIfExpr(
			new NumberExpr(0),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)),
			new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 2);
		delete e1;

		e1 = new LogicalIfExpr(
			new NumberExpr(0),
			new NumberExpr(1),
			new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 2);
		delete e1;

		e1 = new LogicalIfExpr(
			new NumberExpr(0),
			new NumberExpr(1),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)));
		r = e1->eval(); IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e1;

		e1 = new LogicalIfExpr(
			new NumberExpr(1),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)),
			new NumberExpr(2));
		r = e1->eval(); IS_RES_ERR(r, Result::DIVIDE_ZERO);
		delete e1;

		e1 = new LogicalIfExpr(
			new NumberExpr(1),
			new NumberExpr(1),
			new NumberExpr(2));
		r = e1->eval(); IS_RES_OK(r, 1);
		delete e1;

		e1 = new LogicalIfExpr(
			new NumberExpr(1),
			new NumberExpr(1),
			new BinaryExpr(Expr::divide, new NumberExpr(2), new NumberExpr(0)));
		r = e1->eval(); IS_RES_OK(r, 1);
		delete e1;

	}

	DONE_TESTING();
}
