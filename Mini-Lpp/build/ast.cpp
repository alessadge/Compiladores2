/* ast.cpp.  Generated automatically by treecc */
#line 33 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"

#include "ast.h"
int labels = 0;
int strings = 0;
int temps = 0;
variable_list vars;
ident_list identifiers;


//-----------------------------------------------/
//                  CLASSES
//-----------------------------------------------/

class ByteCounter{
        public: 
            std::vector<std::string> refs;
            std::vector<std::pair<std::string, std::string>> params;
            ByteCounter(std::string id1){
                id = id1;
            }

            std::string getPlace(std::string id){
                for(auto &a : params){
                    if(a.first == id) return a.second;
                }
                for(auto &b : refs){
                    if(id == b){
                        return "dword["+id+"]";
                    }
                }
                return "dword["+id+"]";
            }
        private:
            std::string id;
};

ByteCounter* crnt_Function = nullptr;
std::vector<ByteCounter*> count_b;
std::unordered_map<std::string, std::string> ident_type;

//-----------------------------------------------/
//               FUNCTIONS
//-----------------------------------------------/
std::string newTemp(){
    return "dword[tmp" + std::to_string(temps++) + "]";
}

std::string newLabel(){
    return "label" + std::to_string(labels++);
}

std::string newStr(){
    return "str" + std::to_string(strings++);
}

std::string getBoolPrint(string_t place){
    std::ostringstream out;
    string_t contLabel = newLabel();
    string_t isTrue = newLabel();

    out << "cmp " << place << ", 1\n"
        << "je " << isTrue << "\n\n"
        << "push Falsep\n"
        << "jmp " << contLabel << "\n\n"
        << isTrue <<  ":\n"
        << "push Truep\n"
        <<  contLabel << ":\n"
        << "call printf\n"
        << "add esp, 4\n";

    return out.str();
}


#line 78 "ast.cpp"

#include <cstddef>

namespace AST
{

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	offsetof(_YYNODESTATE_align_##type, field)
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

const char *YYNODESTATE::currFilename() const
{
	return (const char *)0;
}

long YYNODESTATE::currLinenum() const
{
	return 0;
}

#endif
#line 362 "ast.cpp"
void *Node::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Node::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Node::Node()
{
	this->kind__ = Node_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->asm_code = "";
	this->place = "";
}

Node::~Node()
{
	// not used
}

int Node::isA(int kind) const
{
	if(kind == Node_kind)
		return 1;
	else
		return 0;
}

const char *Node::getKindName() const
{
	return "Node";
}

Expression::Expression()
	: Node()
{
	this->kind__ = Expression_kind;
}

Expression::~Expression()
{
	// not used
}

int Expression::isA(int kind) const
{
	if(kind == Expression_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Expression::getKindName() const
{
	return "Expression";
}

NodeStmts::NodeStmts()
	: Node()
{
	this->kind__ = NodeStmts_kind;
}

NodeStmts::~NodeStmts()
{
	// not used
}

int NodeStmts::isA(int kind) const
{
	if(kind == NodeStmts_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *NodeStmts::getKindName() const
{
	return "NodeStmts";
}

Proc_Decl::Proc_Decl(string_t procedureID, node_l args, node_l varSection, Node * statements)
	: Node()
{
	this->kind__ = Proc_Decl_kind;
	this->procedureID = procedureID;
	this->args = args;
	this->varSection = varSection;
	this->statements = statements;
}

Proc_Decl::~Proc_Decl()
{
	// not used
}

int Proc_Decl::isA(int kind) const
{
	if(kind == Proc_Decl_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Proc_Decl::getKindName() const
{
	return "Proc_Decl";
}

Func_Decl::Func_Decl(string_t functionID, node_l args, Node * type, node_l varSection, Node * statements)
	: Node()
{
	this->kind__ = Func_Decl_kind;
	this->functionID = functionID;
	this->args = args;
	this->type = type;
	this->varSection = varSection;
	this->statements = statements;
}

Func_Decl::~Func_Decl()
{
	// not used
}

int Func_Decl::isA(int kind) const
{
	if(kind == Func_Decl_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Func_Decl::getKindName() const
{
	return "Func_Decl";
}

Program_Call::Program_Call(string_t id, node_l args)
	: Node()
{
	this->kind__ = Program_Call_kind;
	this->id = id;
	this->args = args;
}

Program_Call::~Program_Call()
{
	// not used
}

int Program_Call::isA(int kind) const
{
	if(kind == Program_Call_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Program_Call::getKindName() const
{
	return "Program_Call";
}

Program_C::Program_C(Node * varSection, Node * subprogramSection, Node * statements)
	: Node()
{
	this->kind__ = Program_C_kind;
	this->varSection = varSection;
	this->subprogramSection = subprogramSection;
	this->statements = statements;
}

Program_C::~Program_C()
{
	// not used
}

int Program_C::isA(int kind) const
{
	if(kind == Program_C_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Program_C::getKindName() const
{
	return "Program_C";
}

Var_Decl::Var_Decl(Node * type, ident_list identifierList)
	: Node()
{
	this->kind__ = Var_Decl_kind;
	this->type = type;
	this->identifierList = identifierList;
}

Var_Decl::~Var_Decl()
{
	// not used
}

int Var_Decl::isA(int kind) const
{
	if(kind == Var_Decl_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Var_Decl::getKindName() const
{
	return "Var_Decl";
}

Type_N::Type_N(string_t type, int arraySize, Node * arrayType)
	: Node()
{
	this->kind__ = Type_N_kind;
	this->type = type;
	this->arraySize = arraySize;
	this->arrayType = arrayType;
}

Type_N::~Type_N()
{
	// not used
}

int Type_N::isA(int kind) const
{
	if(kind == Type_N_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Type_N::getKindName() const
{
	return "Type_N";
}

Argument_N::Argument_N(Node * type, string_t identifier, int isRef, int pos)
	: Node()
{
	this->kind__ = Argument_N_kind;
	this->type = type;
	this->identifier = identifier;
	this->isRef = isRef;
	this->pos = pos;
}

Argument_N::~Argument_N()
{
	// not used
}

int Argument_N::isA(int kind) const
{
	if(kind == Argument_N_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Argument_N::getKindName() const
{
	return "Argument_N";
}

BinaryExpression::BinaryExpression(Node * Expr1, Node * Expr2)
	: Expression()
{
	this->kind__ = BinaryExpression_kind;
	this->Expr1 = Expr1;
	this->Expr2 = Expr2;
}

BinaryExpression::~BinaryExpression()
{
	// not used
}

int BinaryExpression::isA(int kind) const
{
	if(kind == BinaryExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BinaryExpression::getKindName() const
{
	return "BinaryExpression";
}

NumExpr::NumExpr(int val)
	: Expression()
{
	this->kind__ = NumExpr_kind;
	this->val = val;
}

NumExpr::~NumExpr()
{
	// not used
}

int NumExpr::isA(int kind) const
{
	if(kind == NumExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *NumExpr::getKindName() const
{
	return "NumExpr";
}

CharExpr::CharExpr(int val)
	: Expression()
{
	this->kind__ = CharExpr_kind;
	this->val = val;
}

CharExpr::~CharExpr()
{
	// not used
}

int CharExpr::isA(int kind) const
{
	if(kind == CharExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *CharExpr::getKindName() const
{
	return "CharExpr";
}

BoolExpr::BoolExpr(string_t val)
	: Expression()
{
	this->kind__ = BoolExpr_kind;
	this->val = val;
}

BoolExpr::~BoolExpr()
{
	// not used
}

int BoolExpr::isA(int kind) const
{
	if(kind == BoolExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BoolExpr::getKindName() const
{
	return "BoolExpr";
}

IdExpr::IdExpr(string_t val)
	: Expression()
{
	this->kind__ = IdExpr_kind;
	this->val = val;
}

IdExpr::~IdExpr()
{
	// not used
}

int IdExpr::isA(int kind) const
{
	if(kind == IdExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *IdExpr::getKindName() const
{
	return "IdExpr";
}

ArrayExpr::ArrayExpr(string_t id, Node * pos)
	: Expression()
{
	this->kind__ = ArrayExpr_kind;
	this->id = id;
	this->pos = pos;
}

ArrayExpr::~ArrayExpr()
{
	// not used
}

int ArrayExpr::isA(int kind) const
{
	if(kind == ArrayExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *ArrayExpr::getKindName() const
{
	return "ArrayExpr";
}

S_Constant::S_Constant(string_t val)
	: Expression()
{
	this->kind__ = S_Constant_kind;
	this->val = val;
}

S_Constant::~S_Constant()
{
	// not used
}

int S_Constant::isA(int kind) const
{
	if(kind == S_Constant_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *S_Constant::getKindName() const
{
	return "S_Constant";
}

LessEqThanExpr::LessEqThanExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = LessEqThanExpr_kind;
}

LessEqThanExpr::~LessEqThanExpr()
{
	// not used
}

int LessEqThanExpr::isA(int kind) const
{
	if(kind == LessEqThanExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *LessEqThanExpr::getKindName() const
{
	return "LessEqThanExpr";
}

GreaterEqThanExpr::GreaterEqThanExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = GreaterEqThanExpr_kind;
}

GreaterEqThanExpr::~GreaterEqThanExpr()
{
	// not used
}

int GreaterEqThanExpr::isA(int kind) const
{
	if(kind == GreaterEqThanExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *GreaterEqThanExpr::getKindName() const
{
	return "GreaterEqThanExpr";
}

LessThanExpr::LessThanExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = LessThanExpr_kind;
}

LessThanExpr::~LessThanExpr()
{
	// not used
}

int LessThanExpr::isA(int kind) const
{
	if(kind == LessThanExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *LessThanExpr::getKindName() const
{
	return "LessThanExpr";
}

GreaterThanExpr::GreaterThanExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = GreaterThanExpr_kind;
}

GreaterThanExpr::~GreaterThanExpr()
{
	// not used
}

int GreaterThanExpr::isA(int kind) const
{
	if(kind == GreaterThanExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *GreaterThanExpr::getKindName() const
{
	return "GreaterThanExpr";
}

EqualExpr::EqualExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = EqualExpr_kind;
}

EqualExpr::~EqualExpr()
{
	// not used
}

int EqualExpr::isA(int kind) const
{
	if(kind == EqualExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *EqualExpr::getKindName() const
{
	return "EqualExpr";
}

NotEqualExpr::NotEqualExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = NotEqualExpr_kind;
}

NotEqualExpr::~NotEqualExpr()
{
	// not used
}

int NotEqualExpr::isA(int kind) const
{
	if(kind == NotEqualExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *NotEqualExpr::getKindName() const
{
	return "NotEqualExpr";
}

AndExpr::AndExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = AndExpr_kind;
}

AndExpr::~AndExpr()
{
	// not used
}

int AndExpr::isA(int kind) const
{
	if(kind == AndExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *AndExpr::getKindName() const
{
	return "AndExpr";
}

OrExpr::OrExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = OrExpr_kind;
}

OrExpr::~OrExpr()
{
	// not used
}

int OrExpr::isA(int kind) const
{
	if(kind == OrExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *OrExpr::getKindName() const
{
	return "OrExpr";
}

AssignStmt::AssignStmt(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = AssignStmt_kind;
}

AssignStmt::~AssignStmt()
{
	// not used
}

int AssignStmt::isA(int kind) const
{
	if(kind == AssignStmt_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *AssignStmt::getKindName() const
{
	return "AssignStmt";
}

SubExpr::SubExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

int SubExpr::isA(int kind) const
{
	if(kind == SubExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *SubExpr::getKindName() const
{
	return "SubExpr";
}

AddExpr::AddExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

int AddExpr::isA(int kind) const
{
	if(kind == AddExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *AddExpr::getKindName() const
{
	return "AddExpr";
}

DivExpr::DivExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

int DivExpr::isA(int kind) const
{
	if(kind == DivExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *DivExpr::getKindName() const
{
	return "DivExpr";
}

ModExpr::ModExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

int ModExpr::isA(int kind) const
{
	if(kind == ModExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *ModExpr::getKindName() const
{
	return "ModExpr";
}

MultExpr::MultExpr(Node * Expr1, Node * Expr2)
	: BinaryExpression(Expr1, Expr2)
{
	this->kind__ = MultExpr_kind;
}

MultExpr::~MultExpr()
{
	// not used
}

int MultExpr::isA(int kind) const
{
	if(kind == MultExpr_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *MultExpr::getKindName() const
{
	return "MultExpr";
}

IfStmt::IfStmt(Node * cond, Node * trueBlock, Node * elseBlock, string_t elseLabel, string_t endLabel)
	: NodeStmts()
{
	this->kind__ = IfStmt_kind;
	this->cond = cond;
	this->trueBlock = trueBlock;
	this->elseBlock = elseBlock;
	this->elseLabel = elseLabel;
	this->endLabel = endLabel;
}

IfStmt::~IfStmt()
{
	// not used
}

int IfStmt::isA(int kind) const
{
	if(kind == IfStmt_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *IfStmt::getKindName() const
{
	return "IfStmt";
}

Stmt_List::Stmt_List(node_l statements)
	: NodeStmts()
{
	this->kind__ = Stmt_List_kind;
	this->statements = statements;
}

Stmt_List::~Stmt_List()
{
	// not used
}

int Stmt_List::isA(int kind) const
{
	if(kind == Stmt_List_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *Stmt_List::getKindName() const
{
	return "Stmt_List";
}

WhileStmt::WhileStmt(Node * cond, Node * block, string_t label_end, string_t label_start)
	: NodeStmts()
{
	this->kind__ = WhileStmt_kind;
	this->cond = cond;
	this->block = block;
	this->label_end = label_end;
	this->label_start = label_start;
}

WhileStmt::~WhileStmt()
{
	// not used
}

int WhileStmt::isA(int kind) const
{
	if(kind == WhileStmt_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *WhileStmt::getKindName() const
{
	return "WhileStmt";
}

ForStmt::ForStmt(Node * assign, Node * cond, Node * block, string_t label_start, string_t label_end)
	: NodeStmts()
{
	this->kind__ = ForStmt_kind;
	this->assign = assign;
	this->cond = cond;
	this->block = block;
	this->label_start = label_start;
	this->label_end = label_end;
}

ForStmt::~ForStmt()
{
	// not used
}

int ForStmt::isA(int kind) const
{
	if(kind == ForStmt_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *ForStmt::getKindName() const
{
	return "ForStmt";
}

RptStmt::RptStmt(Node * cond, Node * statements)
	: NodeStmts()
{
	this->kind__ = RptStmt_kind;
	this->cond = cond;
	this->statements = statements;
}

RptStmt::~RptStmt()
{
	// not used
}

int RptStmt::isA(int kind) const
{
	if(kind == RptStmt_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *RptStmt::getKindName() const
{
	return "RptStmt";
}

RetrnStmt::RetrnStmt(Node * expr)
	: NodeStmts()
{
	this->kind__ = RetrnStmt_kind;
	this->expr = expr;
}

RetrnStmt::~RetrnStmt()
{
	// not used
}

int RetrnStmt::isA(int kind) const
{
	if(kind == RetrnStmt_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *RetrnStmt::getKindName() const
{
	return "RetrnStmt";
}

PrintStmt::PrintStmt(node_l args)
	: NodeStmts()
{
	this->kind__ = PrintStmt_kind;
	this->args = args;
}

PrintStmt::~PrintStmt()
{
	// not used
}

int PrintStmt::isA(int kind) const
{
	if(kind == PrintStmt_kind)
		return 1;
	else
		return NodeStmts::isA(kind);
}

const char *PrintStmt::getKindName() const
{
	return "PrintStmt";
}

static void gen_code_1__(LessEqThanExpr *e)
#line 382 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e -> place = e->Expr2->place;
    std::ostringstream out;
    out <<  e->Expr1 -> asm_code << '\n'
        << e->Expr2 -> asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "cmp eax," << e->place << '\n'
        << "mov eax,0\n"
        << "setle al \n"
        << "mov " << e -> place << ",eax\n";
    e->asm_code = out.str();
}
#line 1356 "ast.cpp"

static void gen_code_2__(GreaterEqThanExpr *e)
#line 398 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{        
    gen_code(e->Expr2);

    e->place = e->Expr2->place;

    std::ostringstream out;
    out <<  e->Expr1-> asm_code << '\n'
        << e->Expr2 -> asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "cmp eax," << e->place << '\n'
        << "mov eax,0\n"
        << "setge al\n"
        << "mov "<< e-> place<< ",eax\n";

    e->asm_code =out.str();
}
#line 1376 "ast.cpp"

static void gen_code_3__(LessThanExpr *e)
#line 347 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e->place = e->Expr2->place;

    std::ostringstream out;
    out <<  e->Expr1 -> asm_code << '\n'
        << e->Expr2 -> asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "cmp eax," << e->place << '\n'
        << "mov eax,0\n"
        << "setl al \n"
        << "mov " << e -> place << ",eax\n";
    e->asm_code = out.str();
}
#line 1396 "ast.cpp"

static void gen_code_4__(GreaterThanExpr *e)
#line 364 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e -> place = e->Expr2->place;

    std::ostringstream out;
    out <<  e->Expr1 -> asm_code << '\n'
        << e->Expr2 -> asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "cmp eax,"<< e->place << '\n'
        << "mov eax,0\n"
        << "setg al \n"
        << "mov " << e -> place << ",eax\n";

    e->asm_code = out.str();
}
#line 1417 "ast.cpp"

static void gen_code_5__(EqualExpr *e)
#line 416 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e->place = e->Expr2->place;

    std::ostringstream out;

    out << e->Expr1->asm_code<< '\n'
        << e->Expr2->asm_code<< '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "cmp eax,"<< e->place << '\n'
        << "mov eax,0\n"
        << "sete al\n"
        << "mov "<< e->place << ",eax\n";
    
    e->asm_code= out.str();
}
#line 1439 "ast.cpp"

static void gen_code_6__(NotEqualExpr *e)
#line 436 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e->place = e->Expr2->place;

    std::ostringstream out;
    out << e->Expr1->asm_code << '\n'
        << e->Expr2->asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "cmp eax," << e->place << '\n'
        << "mov eax,0\n"
        << "setne al\n"
        << "mov "<< e->place << ",eax\n";
    
    e->asm_code = out.str();
}
#line 1460 "ast.cpp"

static void gen_code_7__(AndExpr *e)
#line 454 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e -> place = e->Expr2->place;
    string_t label_false = newLabel();
    string_t label_end = newLabel();

    std::ostringstream out;

    out 
        << e->Expr1 -> asm_code << '\n'
        << e->Expr2 -> asm_code << '\n'
        << "cmp " << e->Expr1 -> place << ",0\n"
        << "je "<< label_false << '\n'
        << "cmp " << e->Expr2->place << ",0\n"
        << "je " << label_false << '\n'
        << "mov "<< e->place << ",1 " << '\n'
        << "jmp "<< label_end << '\n'
        << label_false<< ":\n"
        << "mov "<< e->place << ",0\n"
        << label_end << ":\n";

    e->asm_code = out.str();

}
#line 1490 "ast.cpp"

static void gen_code_8__(OrExpr *e)
#line 481 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->Expr1);
    gen_code(e->Expr2);

    e->place = newTemp();
    string_t label_true = newLabel();
    string_t label_end = newLabel();

    std::ostringstream out;
    out << e->Expr1->asm_code << '\n'
        << e->Expr2->asm_code  << '\n'
        << "cmp " << e->Expr1 -> place << ",1\n"
        << "je " << label_true << '\n'
        << "cmp " << e->Expr2->place << ",1\n"
        << "je " << label_true << '\n'
        << "mov " << e->place << ",0\n"
        << "jmp " << label_end << '\n'
        << label_true << ":\n"
        << "mov " << e->place << ",1\n"
        << label_end << ":\n";

        e->asm_code =out.str();
}
#line 1517 "ast.cpp"

static void gen_code_9__(AssignStmt *e)
#line 884 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e-> Expr1);
    gen_code(e-> Expr2);
    std::ostringstream out;

    if(e->Expr1->isA(IdExpr_kind)){
        IdExpr* exp1 = static_cast<IdExpr*>(e->Expr1);
        identifiers.push_back(exp1->val);

        e->place = e->Expr1 -> place;

        out << e->Expr2->asm_code << '\n'
            << e->Expr1-> asm_code << '\n'
            << "mov eax, " << e->Expr2->place << '\n'
            << "mov " << e->Expr1 -> place << ",eax\n";

    }else{
        ArrayExpr* exp1 = static_cast<ArrayExpr*>(e->Expr1);
        NumExpr* index = static_cast<NumExpr*> (exp1->pos);

        out << e->Expr2->asm_code << '\n'
            << "mov ecx, " << e->Expr2->place << '\n'
            << "mov dword[" << exp1-> id << "+" << index -> val << "*4-4],ecx\n"
            << "mov ecx, dword[" << exp1-> id << "+" << index -> val << "*4-4]\n"
            << "mov " << e->Expr2 ->place << ",ecx\n\n";
            e->place = e->Expr2->place;
        
    }
    e->asm_code = out.str();
}
#line 1551 "ast.cpp"

static void gen_code_10__(SubExpr *e)
#line 274 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e-> Expr1);
    gen_code(e-> Expr2);
    e -> place = newTemp();
    std::ostringstream out;

    out << e->Expr1 ->asm_code << '\n'
        << e->Expr2 ->asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "sub eax," << e->Expr2->place << '\n'
        << "mov " << e->place << ",eax\n";


    e -> asm_code = out.str();

}
#line 1571 "ast.cpp"

static void gen_code_11__(AddExpr *e)
#line 259 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e-> Expr1);
    gen_code(e-> Expr2);
    e->place = newTemp();
    std::ostringstream out;

    out << e->Expr1 ->asm_code << '\n'
        << e->Expr2 ->asm_code << '\n'
        << "mov eax," << e->Expr1->place << '\n'
        << "add eax," << e->Expr2->place << '\n'
        << "mov " << e->place << ",eax\n";
        
    e -> asm_code = out.str();
}
#line 1589 "ast.cpp"

static void gen_code_12__(DivExpr *e)
#line 292 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e-> Expr1);
    gen_code(e-> Expr2);

    e -> place = newTemp();
    std::ostringstream out;

    out << e->Expr1 ->asm_code << '\n'
        << e->Expr2 ->asm_code << '\n'
        << "mov eax," << e->Expr1 -> place << '\n'
        << "mov edx,0" << '\n' 
        << "div " << e->Expr2->place << '\n'
        << "mov " << e->place << ",eax" << '\n';

    e -> asm_code = out.str();

}
#line 1610 "ast.cpp"

static void gen_code_13__(ModExpr *e)
#line 310 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e-> Expr1);
    gen_code(e-> Expr2);

    e -> place = newTemp();

    std::ostringstream out;

    out << e->Expr1 ->asm_code << '\n'
        << e->Expr2 ->asm_code << '\n'
        << "mov eax," << e->Expr1 -> place << '\n'
        << "mov edx,0" << '\n' 
        << "div " << e->Expr2->place << '\n'
        << "mov " << e->place << ",edx" << '\n';

    e -> asm_code = out.str();
}
#line 1631 "ast.cpp"

static void gen_code_14__(MultExpr *e)
#line 328 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{

    gen_code(e-> Expr1);
    gen_code(e-> Expr2);

    e -> place = newTemp();
    std::ostringstream out;

    out << e->Expr1 ->asm_code << '\n'
        << e->Expr2 ->asm_code << '\n'
        << "mov edx,0" << '\n' 
        << "mov eax," << e->Expr1 -> place << '\n'
        << "mul " << e->Expr2 ->place << '\n'
        << "mov " << e->place << ",eax" << '\n';

    e -> asm_code = out.str();

}
#line 1653 "ast.cpp"

static void gen_code_15__(NumExpr *e)
#line 520 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    e->place = newTemp();
    e->asm_code = "mov " + e -> place + "," + std::to_string(e -> val);
}
#line 1661 "ast.cpp"

static void gen_code_16__(CharExpr *e)
#line 915 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    e -> place = newTemp();
    e -> asm_code = "mov " + e -> place + "," + std::to_string(e -> val);
}
#line 1669 "ast.cpp"

static void gen_code_17__(BoolExpr *e)
#line 927 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    if(e->val == "t")
        e->place = "dword[true]";
    else
        e->place = "dword[false]";
}
#line 1679 "ast.cpp"

static void gen_code_18__(IdExpr *e)
#line 525 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    if(crnt_Function != nullptr){
        e->place = crnt_Function->getPlace(e->val);
    }else{
        e->place = "dword["+e->val+"]";
        e-> asm_code = "";
        identifiers.push_back(e->val);
    }
    
}
#line 1693 "ast.cpp"

static void gen_code_19__(ArrayExpr *e)
#line 505 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->pos);
    std::ostringstream out;
    e->place = newTemp();

    NumExpr* arrPos = static_cast<NumExpr*> (e->pos);
    out << e->pos->asm_code << '\n'
        << "mov ebx," << e->pos->place << '\n'
        << "mov ecx," << "dword[" << e->id << "+ebx*4-4]\n"
        << "mov " << e->place << ",ecx\n";
    
    e->asm_code = out.str();
}
#line 1710 "ast.cpp"

static void gen_code_20__(S_Constant *e)
#line 920 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    string_t strName = newStr();
    vars.push_back(std::make_pair(strName, e->val));

    e->place = strName;
}
#line 1720 "ast.cpp"

static void gen_code_21__(IfStmt *e)
#line 580 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->cond);
    gen_code(e->trueBlock);


    std::ostringstream out;
    if(e->elseBlock != nullptr){
        gen_code(e->elseBlock);
        e-> elseLabel = newLabel();
        e-> endLabel = newLabel();

        out << e->cond->asm_code << '\n'
            << "cmp " << e-> cond->place << ",0\n"
            << "je " << e->elseLabel << '\n'
            << e-> trueBlock->asm_code << '\n'
            << "jmp " << e->endLabel << '\n'
            << e->elseLabel << ":\n"
            << e->elseBlock->asm_code << '\n'
            << e->endLabel << ":\n";
    }else{
        e->endLabel = newLabel();
        out << e->cond->asm_code << '\n'
            << "cmp " << e->cond->place << ",0\n"
            << "je " << e->endLabel << '\n'
            << e->trueBlock->asm_code << '\n'
            << e->endLabel<< ":\n";
    }

    e->asm_code = out.str();
    
}
#line 1755 "ast.cpp"

static void gen_code_22__(Stmt_List *e)
#line 663 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    for(auto &stmt : e->statements){
        gen_code(stmt);
        e->place = stmt->place;
        e->asm_code += stmt->asm_code;
    }
}
#line 1766 "ast.cpp"

static void gen_code_23__(WhileStmt *e)
#line 612 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->cond);
    gen_code(e->block);
    e-> label_start = newLabel();
    e-> label_end = newLabel();

    std::ostringstream out;

    out << e->label_start << ":\n"
        << e->cond->asm_code << '\n'
        << "cmp " << e->cond->place << ", 0\n"
        << "je " << e->label_end << '\n'
        << e->block->asm_code << '\n'
        << "jmp " << e->label_start << '\n'
        << e->label_end << ":\n";

    e->asm_code = out.str();
}
#line 1788 "ast.cpp"

static void gen_code_24__(ForStmt *e)
#line 536 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->assign);
    gen_code(e->cond);
    gen_code(e->block);

    e-> label_start = newLabel();
    e-> label_end = newLabel();

    std::ostringstream out;

    out << e->assign->asm_code << '\n'
        << e->cond->asm_code << '\n'
        << e-> label_start << ":\n"
        << "mov eax, " <<  e->cond->place << '\n'
        << "cmp " << e->assign ->place << ",eax\n"
        << "jg " << e->label_end
        << e->block->asm_code << '\n'
        << "inc " << e->assign ->place << '\n'
        << "jmp " << e->label_start << '\n'
        << e->label_end << ":\n";

    e-> asm_code = out.str();
}
#line 1815 "ast.cpp"

static void gen_code_25__(RptStmt *e)
#line 560 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->cond);
    gen_code(e->statements);

    std::ostringstream out;

    string_t repeatL = newLabel(); 
    std::string exitL = newLabel();

    out << repeatL << ":\n"
        << e-> statements ->asm_code << '\n'
        << e-> cond->asm_code << '\n'
        << "cmp " << e->cond->place << ", 1\n"
        << "je " << exitL << "\n"
        << "jmp " << repeatL << "\n"
        << exitL << ":\n";

    e->asm_code = out.str();
}
#line 1838 "ast.cpp"

static void gen_code_26__(RetrnStmt *e)
#line 766 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->expr);
    e->place = e->expr->place;

    std::ostringstream out;
    out << e->expr->asm_code << '\n'
    << "mov eax," << e->expr->place << '\n'
    << "mov esp,ebp\n"
    << "pop ebp\n"
    << "ret\n";

    e->asm_code = out.str();
}
#line 1855 "ast.cpp"

static void gen_code_27__(PrintStmt *e)
#line 810 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    std::ostringstream out;

    for (auto &a: e-> args){
        gen_code(a);
        if(a->isA(IdExpr_kind)){
            IdExpr* ID = static_cast<IdExpr*>(a);
            out << a->asm_code << std::endl;
            if(ident_type[ID->val] == "int" || ident_type[ID->val] == "char"){
                out << "push " << a->place << "\n";
            }else if(ident_type[ID->val] == "bool"){
                out << getBoolPrint(a->place);
            }else if(ident_type[ID->val] == "char"){
                out << "push charFormat\n"
                << "call printf\n";
            }
            if(ident_type[ID->val] == "int"){
                out << "push format\n"
                    << "call printf\n";
            }else if(ident_type[ID->val] == "char"){
                    out << "push charFormat\n"
                        << "call printf\n";
            }

            if(ident_type[ID->val] == "int" || ident_type[ID->val] == "char" ){
                out << "add esp,8\n";
            }else if(ident_type[ID->val] == "bool"){}
            }else if(a->isA(NumExpr_kind)){
                out << a->asm_code << '\n'
                    << "push " << a->place << '\n'
                    << "push format\n"
                    << "call printf\n"
                    << "add esp,8\n"; 
            }
            else if(a->isA(S_Constant_kind)){
                out << a->asm_code << '\n'
                    << "push " << a -> place << '\n'
                    << "call printf\n"
                    << "add esp,4\n"; 
            }else if(a->isA(BinaryExpression_kind)){
                BinaryExpression* bin = static_cast<BinaryExpression*>(a);

                gen_code(a);
                out << a->asm_code << '\n'
                    << "push " << a->place << "\n"
                    << "push format\n"
                    << "call printf\n"
                    << "add esp,8\n";
            }else if(a->isA(Program_Call_kind)){
                gen_code(a);
                out << a-> asm_code << '\n'
                    << "push eax\n"
                    << "push format\n"
                    << "call printf\n"
                    << "add esp,8\n";
            }else if(a->isA(ArrayExpr_kind)){
                gen_code(a);
                out << a->asm_code << '\n'
                    << "push " << a->place << '\n'
                    << "push format\n"
                    << "call printf\n"
                    << "add esp, 8\n";
            }else if(a->isA(CharExpr_kind)){
                CharExpr* charE = static_cast<CharExpr*>(a);
                out << a->asm_code << '\n'
                    << "push " << charE->val << "\n"
                    << "push charFormat\n"
                    << "call printf\n"
                    << "add esp,8\n";
            } 
        }
        e->asm_code = out.str();
    }
#line 1932 "ast.cpp"

static void gen_code_28__(Proc_Decl *e)
#line 671 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    
    std::ostringstream out;
    ByteCounter* funcion = new ByteCounter(e->procedureID);
    std::vector<std::pair<std::string, std::string>> vectorTemp;
    std::vector<std::string> refsTemp;
    for(auto &a : e->args){
        AST::Argument_N* arg = static_cast<AST::Argument_N*>(a);
        if(arg->isRef){
            refsTemp.push_back(arg->identifier);
        }else{
            vectorTemp.push_back(make_pair(arg->identifier,"dword[ebp+"+std::to_string(arg->pos)+"]"));
        }
    }
    count_b.push_back(funcion);
    funcion->params = vectorTemp;
    
    crnt_Function = funcion;
    gen_code(e->statements);
    out << e-> procedureID << ":\n"
        << "push ebp\n"
        << "mov ebp,esp\n"
        << "sub esp," << e->varSection.size()*4 << '\n'
        << e->statements->asm_code << '\n'
        << "mov esp,ebp\n"
        << "pop ebp\n"
        << "ret\n";
    e->asm_code = out.str();
    crnt_Function = nullptr;
}
#line 1966 "ast.cpp"

static void gen_code_29__(Func_Decl *e)
#line 631 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    std::ostringstream out;

    ByteCounter* funcion = new ByteCounter(e->functionID);
    std::vector<std::pair<std::string, std::string>> vectorTemp;
    std::vector<std::string> refsTemp;

    for(auto &a : e->args){
        AST::Argument_N* arg = static_cast<AST::Argument_N*>(a);
        if(arg->isRef){
            refsTemp.push_back(arg->identifier);
        }else{
            vectorTemp.push_back(make_pair(arg->identifier,"dword[ebp+"+std::to_string(arg->pos)+"]"));
        }
    }
    count_b.push_back(funcion);
    funcion->params = vectorTemp;
    
    crnt_Function = funcion;
    gen_code(e->statements);
    out << e-> functionID << ":\n"
        << "push ebp\n"
        << "mov ebp,esp\n"
        << e->statements->asm_code << '\n'
        << "mov esp,ebp\n"
        << "pop ebp\n"
        << "ret\n";
    e->asm_code = out.str();
    crnt_Function = nullptr;
}
#line 2000 "ast.cpp"

static void gen_code_30__(Program_Call *e)
#line 737 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    e->place = newTemp();
    std::ostringstream out;

    std::vector<AST::Node*> params = e->args;
    std::reverse(params.begin(), params.end());
    for(auto &param: params){
        gen_code(param);

        if(param -> isA(IdExpr_kind)){
            IdExpr* ID = static_cast<IdExpr*> (param);
            string_t varName = ID->val;
            
            out << param ->asm_code << '\n'
                << "push " << param->place << '\n';
        }else{
            out << param ->asm_code << '\n'
                << "push " << param->place << '\n';
        }
    }
    out << "call " << e->id << '\n'
        << "add esp," <<  (e->args.size())*4 << '\n'
        << "mov " <<  e->place << ",eax\n";


    e->asm_code = out.str();

}
#line 2032 "ast.cpp"

static void gen_code_31__(Program_C *e)
#line 702 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    gen_code(e->varSection);
    gen_code(e->subprogramSection);
    gen_code(e->statements);
    std::ostringstream stringIDs;
    std::ostringstream tempData;

    for(int i = 0; i< temps; i++){
        tempData << "tmp" << i << " dd 0\n";
    }
    for (auto a: vars){
        stringIDs << a.first << " db \'" << a.second << "\',0 ,10\n";
    }
    std::ostringstream out;
    out << "extern printf\n"
        << "global main\n"
        << "section .data\n"
        << "format db '%d',0\n"
        << "charFormat db '%c',0\n"
        << "true dd 1\n"
        << "false dd 0\n"
        << "Truep db 'Verdadero',0\n"
        << "Falsep db 'Falso',0\n"
        << e->varSection->asm_code << '\n'
        << tempData.str()
        << stringIDs.str() << '\n'
        << "section .text\n"
        << e->subprogramSection->asm_code << '\n'
        << "main: \n"
        << e->statements->asm_code << '\n'
        << "ret\n";

    e->asm_code = out.str();
}
#line 2070 "ast.cpp"

static void gen_code_32__(Var_Decl *e)
#line 780 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
    //iniciar las variables en 0
    std::ostringstream out;

    //std::cout << "entered\n";
    //std::cout << "size: " << e->identifierList.size() << '\n';
    for(auto var : e->identifierList){
        Type_N * typeN = static_cast<Type_N*>(e->type);

        if(typeN-> type == "int"){
            ident_type[var] = "int";
        }else if (typeN-> type == "bool"){
            ident_type[var] = "bool";
        }else if (typeN-> type == "char"){
            ident_type[var] = "char";
        }else{
            ident_type[var] = "arr";
        }

        if(typeN-> type != "arr"){
            out << var << " dd 0\n";
        }else{
            out << var << " times " << typeN -> arraySize << " dd 0\n";
        }
        
    }
    e->asm_code = out.str();
}
#line 2102 "ast.cpp"

static void gen_code_33__(Type_N *e)
#line 938 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
//Solo lo instancie para evitar error 
}
#line 2109 "ast.cpp"

static void gen_code_34__(Argument_N *e)
#line 934 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/ast.tc"
{
//Solo lo instancie para evitar error en Argument_N
}
#line 2116 "ast.cpp"

void gen_code(Node * e__)
{
	switch(e__->getKind())
	{
		case LessEqThanExpr_kind:
		{
			gen_code_1__((LessEqThanExpr *)e__);
		}
		break;

		case GreaterEqThanExpr_kind:
		{
			gen_code_2__((GreaterEqThanExpr *)e__);
		}
		break;

		case LessThanExpr_kind:
		{
			gen_code_3__((LessThanExpr *)e__);
		}
		break;

		case GreaterThanExpr_kind:
		{
			gen_code_4__((GreaterThanExpr *)e__);
		}
		break;

		case EqualExpr_kind:
		{
			gen_code_5__((EqualExpr *)e__);
		}
		break;

		case NotEqualExpr_kind:
		{
			gen_code_6__((NotEqualExpr *)e__);
		}
		break;

		case AndExpr_kind:
		{
			gen_code_7__((AndExpr *)e__);
		}
		break;

		case OrExpr_kind:
		{
			gen_code_8__((OrExpr *)e__);
		}
		break;

		case AssignStmt_kind:
		{
			gen_code_9__((AssignStmt *)e__);
		}
		break;

		case SubExpr_kind:
		{
			gen_code_10__((SubExpr *)e__);
		}
		break;

		case AddExpr_kind:
		{
			gen_code_11__((AddExpr *)e__);
		}
		break;

		case DivExpr_kind:
		{
			gen_code_12__((DivExpr *)e__);
		}
		break;

		case ModExpr_kind:
		{
			gen_code_13__((ModExpr *)e__);
		}
		break;

		case MultExpr_kind:
		{
			gen_code_14__((MultExpr *)e__);
		}
		break;

		case NumExpr_kind:
		{
			gen_code_15__((NumExpr *)e__);
		}
		break;

		case CharExpr_kind:
		{
			gen_code_16__((CharExpr *)e__);
		}
		break;

		case BoolExpr_kind:
		{
			gen_code_17__((BoolExpr *)e__);
		}
		break;

		case IdExpr_kind:
		{
			gen_code_18__((IdExpr *)e__);
		}
		break;

		case ArrayExpr_kind:
		{
			gen_code_19__((ArrayExpr *)e__);
		}
		break;

		case S_Constant_kind:
		{
			gen_code_20__((S_Constant *)e__);
		}
		break;

		case IfStmt_kind:
		{
			gen_code_21__((IfStmt *)e__);
		}
		break;

		case Stmt_List_kind:
		{
			gen_code_22__((Stmt_List *)e__);
		}
		break;

		case WhileStmt_kind:
		{
			gen_code_23__((WhileStmt *)e__);
		}
		break;

		case ForStmt_kind:
		{
			gen_code_24__((ForStmt *)e__);
		}
		break;

		case RptStmt_kind:
		{
			gen_code_25__((RptStmt *)e__);
		}
		break;

		case RetrnStmt_kind:
		{
			gen_code_26__((RetrnStmt *)e__);
		}
		break;

		case PrintStmt_kind:
		{
			gen_code_27__((PrintStmt *)e__);
		}
		break;

		case Proc_Decl_kind:
		{
			gen_code_28__((Proc_Decl *)e__);
		}
		break;

		case Func_Decl_kind:
		{
			gen_code_29__((Func_Decl *)e__);
		}
		break;

		case Program_Call_kind:
		{
			gen_code_30__((Program_Call *)e__);
		}
		break;

		case Program_C_kind:
		{
			gen_code_31__((Program_C *)e__);
		}
		break;

		case Var_Decl_kind:
		{
			gen_code_32__((Var_Decl *)e__);
		}
		break;

		case Type_N_kind:
		{
			gen_code_33__((Type_N *)e__);
		}
		break;

		case Argument_N_kind:
		{
			gen_code_34__((Argument_N *)e__);
		}
		break;

		default: break;
	}
}

}
