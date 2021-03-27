/* ast.h.  Generated automatically by treecc */
#ifndef __yy_ast_h
#define __yy_ast_h
#line 4 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"

//-----------------------------------------------/
//                 INCLUDES
//-----------------------------------------------/
#include <vector>
#include <set>
#include <unordered_map> 
#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <algorithm>
namespace AST{
    class Node;
}

using node_l = std::vector<AST::Node*>;
using string_t = std::string;


//-----------------------------------------------/
//              LIST  VARIABLES
//-----------------------------------------------/
using variable_list = std::vector<std::pair<std::string,std::string>>;
using ident_list = std::list<std::string>;

#line 32 "ast.h"

#include <new>

namespace AST
{

const int Node_kind = 1;
const int Expression_kind = 2;
const int NodeStmts_kind = 23;
const int Proc_Decl_kind = 30;
const int Func_Decl_kind = 31;
const int Program_Call_kind = 33;
const int Program_C_kind = 34;
const int Var_Decl_kind = 35;
const int Type_N_kind = 36;
const int Argument_N_kind = 37;
const int BinaryExpression_kind = 3;
const int NumExpr_kind = 18;
const int CharExpr_kind = 19;
const int BoolExpr_kind = 20;
const int IdExpr_kind = 21;
const int ArrayExpr_kind = 22;
const int S_Constant_kind = 29;
const int LessEqThanExpr_kind = 4;
const int GreaterEqThanExpr_kind = 5;
const int LessThanExpr_kind = 6;
const int GreaterThanExpr_kind = 7;
const int EqualExpr_kind = 8;
const int NotEqualExpr_kind = 9;
const int AndExpr_kind = 10;
const int OrExpr_kind = 11;
const int AssignStmt_kind = 12;
const int SubExpr_kind = 13;
const int AddExpr_kind = 14;
const int DivExpr_kind = 15;
const int ModExpr_kind = 16;
const int MultExpr_kind = 17;
const int IfStmt_kind = 24;
const int Stmt_List_kind = 25;
const int WhileStmt_kind = 26;
const int ForStmt_kind = 27;
const int RptStmt_kind = 28;
const int RetrnStmt_kind = 32;
const int PrintStmt_kind = 38;

class Node;
class Expression;
class NodeStmts;
class Proc_Decl;
class Func_Decl;
class Program_Call;
class Program_C;
class Var_Decl;
class Type_N;
class Argument_N;
class BinaryExpression;
class NumExpr;
class CharExpr;
class BoolExpr;
class IdExpr;
class ArrayExpr;
class S_Constant;
class LessEqThanExpr;
class GreaterEqThanExpr;
class LessThanExpr;
class GreaterThanExpr;
class EqualExpr;
class NotEqualExpr;
class AndExpr;
class OrExpr;
class AssignStmt;
class SubExpr;
class AddExpr;
class DivExpr;
class ModExpr;
class MultExpr;
class IfStmt;
class Stmt_List;
class WhileStmt;
class ForStmt;
class RptStmt;
class RetrnStmt;
class PrintStmt;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 130 "ast.h"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual const char *currFilename() const;
	virtual long currLinenum() const;

};

class Node
{
protected:

	int kind__;
	const char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(const char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	Node();

public:

	string_t asm_code;
	string_t place;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Node();

};

class Expression : public Node
{
protected:

	Expression();

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expression();

};

class NodeStmts : public Node
{
protected:

	NodeStmts();

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NodeStmts();

};

class Proc_Decl : public Node
{
public:

	Proc_Decl(string_t procedureID, node_l args, node_l varSection, Node * statements);

public:

	string_t procedureID;
	node_l args;
	node_l varSection;
	Node * statements;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Proc_Decl();

};

class Func_Decl : public Node
{
public:

	Func_Decl(string_t functionID, node_l args, Node * type, node_l varSection, Node * statements);

public:

	string_t functionID;
	node_l args;
	Node * type;
	node_l varSection;
	Node * statements;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Func_Decl();

};

class Program_Call : public Node
{
public:

	Program_Call(string_t id, node_l args);

public:

	string_t id;
	node_l args;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program_Call();

};

class Program_C : public Node
{
public:

	Program_C(Node * varSection, Node * subprogramSection, Node * statements);

public:

	Node * varSection;
	Node * subprogramSection;
	Node * statements;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program_C();

};

class Var_Decl : public Node
{
public:

	Var_Decl(Node * type, ident_list identifierList);

public:

	Node * type;
	ident_list identifierList;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Var_Decl();

};

class Type_N : public Node
{
public:

	Type_N(string_t type, int arraySize, Node * arrayType);

public:

	string_t type;
	int arraySize;
	Node * arrayType;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Type_N();

};

class Argument_N : public Node
{
public:

	Argument_N(Node * type, string_t identifier, int isRef, int pos);

public:

	Node * type;
	string_t identifier;
	int isRef;
	int pos;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Argument_N();

};

class BinaryExpression : public Expression
{
protected:

	BinaryExpression(Node * Expr1, Node * Expr2);

public:

	Node * Expr1;
	Node * Expr2;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpression();

};

class NumExpr : public Expression
{
public:

	NumExpr(int val);

public:

	int val;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class CharExpr : public Expression
{
public:

	CharExpr(int val);

public:

	int val;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CharExpr();

};

class BoolExpr : public Expression
{
public:

	BoolExpr(string_t val);

public:

	string_t val;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BoolExpr();

};

class IdExpr : public Expression
{
public:

	IdExpr(string_t val);

public:

	string_t val;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdExpr();

};

class ArrayExpr : public Expression
{
public:

	ArrayExpr(string_t id, Node * pos);

public:

	string_t id;
	Node * pos;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayExpr();

};

class S_Constant : public Expression
{
public:

	S_Constant(string_t val);

public:

	string_t val;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~S_Constant();

};

class LessEqThanExpr : public BinaryExpression
{
public:

	LessEqThanExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessEqThanExpr();

};

class GreaterEqThanExpr : public BinaryExpression
{
public:

	GreaterEqThanExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreaterEqThanExpr();

};

class LessThanExpr : public BinaryExpression
{
public:

	LessThanExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessThanExpr();

};

class GreaterThanExpr : public BinaryExpression
{
public:

	GreaterThanExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreaterThanExpr();

};

class EqualExpr : public BinaryExpression
{
public:

	EqualExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqualExpr();

};

class NotEqualExpr : public BinaryExpression
{
public:

	NotEqualExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotEqualExpr();

};

class AndExpr : public BinaryExpression
{
public:

	AndExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpr();

};

class OrExpr : public BinaryExpression
{
public:

	OrExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OrExpr();

};

class AssignStmt : public BinaryExpression
{
public:

	AssignStmt(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStmt();

};

class SubExpr : public BinaryExpression
{
public:

	SubExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class AddExpr : public BinaryExpression
{
public:

	AddExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class DivExpr : public BinaryExpression
{
public:

	DivExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class ModExpr : public BinaryExpression
{
public:

	ModExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class MultExpr : public BinaryExpression
{
public:

	MultExpr(Node * Expr1, Node * Expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MultExpr();

};

class IfStmt : public NodeStmts
{
public:

	IfStmt(Node * cond, Node * trueBlock, Node * elseBlock, string_t elseLabel, string_t endLabel);

public:

	Node * cond;
	Node * trueBlock;
	Node * elseBlock;
	string_t elseLabel;
	string_t endLabel;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class Stmt_List : public NodeStmts
{
public:

	Stmt_List(node_l statements);

public:

	node_l statements;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Stmt_List();

};

class WhileStmt : public NodeStmts
{
public:

	WhileStmt(Node * cond, Node * block, string_t label_end, string_t label_start);

public:

	Node * cond;
	Node * block;
	string_t label_end;
	string_t label_start;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class ForStmt : public NodeStmts
{
public:

	ForStmt(Node * assign, Node * cond, Node * block, string_t label_start, string_t label_end);

public:

	Node * assign;
	Node * cond;
	Node * block;
	string_t label_start;
	string_t label_end;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStmt();

};

class RptStmt : public NodeStmts
{
public:

	RptStmt(Node * cond, Node * statements);

public:

	Node * cond;
	Node * statements;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RptStmt();

};

class RetrnStmt : public NodeStmts
{
public:

	RetrnStmt(Node * expr);

public:

	Node * expr;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RetrnStmt();

};

class PrintStmt : public NodeStmts
{
public:

	PrintStmt(node_l args);

public:

	node_l args;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmt();

};


void gen_code(Node * e);

}
#endif
