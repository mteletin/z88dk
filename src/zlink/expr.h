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

	static Result power(int base, int exp);	// integer power function
	static Result divide(int a, int b);		// integer divide function, detect division by zero
	static Result modulo(int a, int b);		// integer modulo function, detect division by zero

private:
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

#endif // ndef EXPR_H_
