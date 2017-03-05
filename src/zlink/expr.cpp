//-----------------------------------------------------------------------------
// zlink - expression
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "memcheck.h"
#include "expr.h"
#include "symbol.h"

//-----------------------------------------------------------------------------
// Expr
Expr::Expr() {}
Expr::~Expr() {}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Undefinded Expr
UndefExpr::UndefExpr() {}

UndefExpr::~UndefExpr() {}

Result UndefExpr::eval() const {
	return Result(0, Result::UNDEFINED);
}

Expr* UndefExpr::clone() const {
	return new UndefExpr();
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// unary expression
UnaryExpr::UnaryExpr(Result(*func)(int a), Expr* a)
	: func_(func), a_(a) {}

UnaryExpr::~UnaryExpr() {
	delete a_;
}

Result UnaryExpr::eval() const {
	Result a = a_->eval();
	if (a.error != Result::OK)
		return a;

	return func_(a.value);
}

Expr* UnaryExpr::clone() const {
	return new UnaryExpr(func_, a_->clone());
}

//-----------------------------------------------------------------------------
// binary expression
BinaryExpr::BinaryExpr(Result(*func)(int a, int b), Expr* a, Expr* b)
	: func_(func), a_(a), b_(b) {}

BinaryExpr::~BinaryExpr() {
	delete a_;
	delete b_;
}

Result BinaryExpr::eval() const {
	Result a = a_->eval();
	if (a.error != Result::OK)
		return a;

	Result b = b_->eval();
	if (b.error != Result::OK)
		return b;

	return func_(a.value, b.value);
}

Expr* BinaryExpr::clone() const {
	return new BinaryExpr(func_, a_->clone(), b_->clone());
}

//-----------------------------------------------------------------------------
// logical or
LogicalOrExpr::LogicalOrExpr(Expr* a, Expr* b)
	: a_(a), b_(b) {}

LogicalOrExpr::~LogicalOrExpr() {
	delete a_;
	delete b_;
}

Result LogicalOrExpr::eval() const {
	Result a = a_->eval();
	if (a.error != Result::OK || a.value != 0)
		return a;

	Result b = b_->eval();
	return b;
}

Expr* LogicalOrExpr::clone() const {
	return new LogicalOrExpr(a_->clone(), b_->clone());
}

//-----------------------------------------------------------------------------
// logical and
LogicalAndExpr::LogicalAndExpr(Expr* a, Expr* b)
	: a_(a), b_(b) {}

LogicalAndExpr::~LogicalAndExpr() {
	delete a_;
	delete b_;
}

Result LogicalAndExpr::eval() const {
	Result a = a_->eval();
	if (a.error != Result::OK || a.value == 0)
		return a;

	Result b = b_->eval();
	return b;
}

Expr* LogicalAndExpr::clone() const {
	return new LogicalAndExpr(a_->clone(), b_->clone());
}

//-----------------------------------------------------------------------------
// logical if
LogicalIfExpr::LogicalIfExpr(Expr* cond, Expr* t, Expr* f)
	: cond_(cond), t_(t), f_(f) {}

LogicalIfExpr::~LogicalIfExpr() {
	delete cond_;
	delete t_;
	delete f_;
}

Result LogicalIfExpr::eval() const {
	Result cond = cond_->eval();
	if (cond.error != Result::OK)
		return cond;

	if (cond.value)
		return t_->eval();
	else
		return f_->eval();
}

Expr* LogicalIfExpr::clone() const {
	return new LogicalIfExpr(cond_->clone(), t_->clone(), f_->clone());
}
