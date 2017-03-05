//-----------------------------------------------------------------------------
// zlink - expression
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "expr.h"
#include "symbol.h"

// Expr
Expr::Expr() {}
Expr::~Expr() {}

// exponentiation by squaring
Result Expr::power(int base, int exp) {
	int result = 1;
	if (exp < 0) {
		return Result(0);
	}
	else {
		while (exp) {
			if (exp & 1)
				result *= base;
			exp >>= 1;
			base *= base;
		}
		return Result(result);
	}
}

Result Expr::divide(int a, int b) {
	if (b == 0)
		return Result(0, Result::DIVIDE_ZERO);
	else
		return a / b;
}

Result Expr::modulo(int a, int b) {
	if (b == 0)
		return Result(0, Result::DIVIDE_ZERO);
	else
		return a % b;
}

// Undefinded Expr
UndefExpr::UndefExpr() {}

UndefExpr::~UndefExpr() {}

Result UndefExpr::eval() const {
	return Result(0, Result::UNDEFINED);
}

Expr* UndefExpr::clone() const {
	return new UndefExpr();
}

// Number Expr
NumberExpr::NumberExpr(int value)
	: value_(value) {}

NumberExpr::~NumberExpr() {}

Result NumberExpr::eval() const {
	return Result(value_, Result::OK);
}

Expr* NumberExpr::clone() const {
	return new NumberExpr(value_);
}

// Symbol Expr
SymbolExpr::SymbolExpr(Symbol* symbol)
	: symbol_(symbol) {}

SymbolExpr::~SymbolExpr() {}

Result SymbolExpr::eval() const {
	return symbol_->eval();
}

Expr* SymbolExpr::clone() const {
	return new SymbolExpr(symbol_);
}
