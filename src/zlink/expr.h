//-----------------------------------------------------------------------------
// zlink - expression
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef EXPR_H_
#define EXPR_H_

#include "fwd.h"
#include "result.h"
#include <string>

class Expr {
public:
	Expr();
	virtual ~Expr();
	virtual Result eval() const = 0;		// evaluate
	virtual Expr* clone() const = 0;		// make a copy

	// logical functions
	static Result logical_ident(int a) { return a == 0 ? 0 : 1; }
	static Result logical_not(int a) { return logical_ident(!a); }
	static Result equal(int a, int b) { return logical_ident(a == b); }
	static Result not_equal(int a, int b) { return logical_ident(a != b); }
	static Result less(int a, int b) { return logical_ident(a < b); }
	static Result greater(int a, int b) { return logical_ident(a > b); }
	static Result less_equal(int a, int b) { return logical_ident(a <= b); }
	static Result greater_equal(int a, int b) { return logical_ident(a >= b); }
	
	// binary functions
	static Result binary_not(int a) { return ~a; }
	static Result binary_or(int a, int b) { return a | b; }
	static Result binary_xor(int a, int b) { return a ^ b; }
	static Result binary_and(int a, int b) { return a & b; }
	static Result right_shift(int a, int b) { return a >> b; }
	static Result left_shift(int a, int b) { return a << b; }

	// arithmetic functions
	static Result negate(int a) { return -a; }
	static Result power(int base, int exp);	// integer power function
	static Result modulo(int a, int b);		// integer modulo function, detect division by zero
	static Result divide(int a, int b);		// integer divide function, detect division by zero
	static Result multiply(int a, int b) { return a * b; }
	static Result minus(int a, int b) { return a - b; }
	static Result plus(int a, int b) { return a + b; }
};

// expression leaf: undef
class UndefExpr : public Expr {
public:
	UndefExpr();
	virtual ~UndefExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
};

// expression leaf: number
class NumberExpr : public Expr {
public:
	NumberExpr(int value);
	virtual ~NumberExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	int		value_;
};

// expression leaf: symbol
class SymbolExpr : public Expr {
public:
	SymbolExpr(Symbol* symbol);
	virtual ~SymbolExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	Symbol* symbol_;	// weak pointer
};

// unary expression
class UnaryExpr : public Expr {
public:
	UnaryExpr(Result(*func)(int a), Expr* a);
	virtual ~UnaryExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	Result(*func_)(int a);
	Expr* a_;
};

// binary expression
class BinaryExpr : public Expr {
public:
	BinaryExpr(Result(*func)(int a, int b), Expr* a, Expr* b);
	virtual ~BinaryExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	Result(*func_)(int a, int b);
	Expr* a_;
	Expr* b_;
};

// logical expressions with short-circuit, i.e. false branch not evaluated
class LogicalOrExpr : public Expr {
public:
	LogicalOrExpr(Expr* a, Expr* b);
	~LogicalOrExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	Expr* a_;
	Expr* b_;
};

class LogicalAndExpr : public Expr {
public:
	LogicalAndExpr(Expr* a, Expr* b);
	~LogicalAndExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	Expr* a_;
	Expr* b_;
};

class LogicalIfExpr : public Expr {
public:
	LogicalIfExpr(Expr* cond, Expr* t, Expr* f);
	~LogicalIfExpr();
	virtual Result eval() const;
	virtual Expr* clone() const;

private:
	Expr* cond_;
	Expr* t_;
	Expr* f_;
};

#endif // ndef EXPR_H_
