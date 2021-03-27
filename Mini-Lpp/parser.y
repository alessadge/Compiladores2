%language "c++"

%define parse.error verbose
%define api.value.type variant

%define api.parser.class { Parser }
%define api.namespace { Expr }

%code requires{
    #include <unordered_map>
    #include <string>
    #include "ast.h"
}

%{
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

#include "tokens.h"
#include "ast.h"
namespace Expr
    {
    void Expr::Parser::error(const std::string& e){
        throw std::string(e);
    }
}

int yylex(Expr::Parser::semantic_type *yylval);

%}

//Operands
%token OpAdd "+"
%token OpSub "-"
%token OpMul "*"
%token OpDiv "/"
%token Mod "mod"
%token Caret "^"

//LogicOperands
%token Assign "<-"
%token Equal "="
%token OpEqual "=="
%token NotEqual "<>"
%token LessThan "<"
%token GreaterThan ">"
%token LessEqThan "<="
%token GreaterEqThan ">="

//Symbols
%token LeftPar "("
%token RightPar ")"
%token LeftBracket "["
%token RightBracket "]"
%token Colon ":"
%token Comma ","

//ReservedWords
%token De "de"
%token Funcion "funcion"
%token Procedimiento "procedimiento"
%token Var "var"
%token Repita "repita"
%token Hasta "hasta"
%token Caso "caso"
%token Cerrar "cerrar"
%token Archivo "archivo"
%token Secuencial "secuencial"
%token Abrir "abrir"
%token Como "como"
%token No "no"
%token Div "div"
%token Inicio "inicio"
%token Lectura "lectura"
%token O "o"
%token Entonces "entonces"
%token Sino "sino"
%token Haga "haga"
%token Lea "lea"
%token Escriba "escriba"
%token Retorne "retorne"
%token Tipo "tipo"
%token Es "es"
%token Registro "registro"
%token Escritura "escritura"
%token Llamar "llamar"
%token Para "para"
%token Mientras "mientras"
%token Y "y"
%token Fin "fin"
%token Final "final"
%token Si "si"
%token Leer "leer"
%token Escribir "escribir"

//Types
%token Entero "entero"
%token Booleano "booleano"
%token Caracter "caracter"
%token Real "real"
%token Arreglo "arreglo"

//BoolOperands
%token <std::string> Verdadero "verdadero"
%token <std::string> Falso "falso"

//Primitive
%token<std::string> Id "ID"
%token Cadena "cadena"
%token<std::string> charConstant "charConstant"
%token <std::string> stringConstant "stringConstant"
%token<int> intConstant "intConstant"


//Dividers
%token Error
%token EoL
%token FIN_ 0 "EOF"

//TypesDeclaration
%type <AST::Node*> program subprogramDecl argument-decl lvalue  argument if-statement statement else-if-block else-block
%type <std::vector<AST::Node*>> subtype-section variable-section variable-decl subprogram-decl subprogram-decl-list optional-expr exprList argument-comma-list stmts argument-comma argument-opt
%type <std::list<std::string>> ident-list
%type <AST::Node*> type expr prec power term factor


//Start
%%

start: 
empty-EoLList program opt-EoL 
    {
        AST::gen_code($2);
        std::cout << $2->asm_code << std::endl;
    }
;

program: 
subtype-section subprogram-decl "inicio" EoLList stmts EoLList "fin" 
    {
        $$ = new AST::Program_C(new AST::Stmt_List($1),new AST::Stmt_List($2),new AST::Stmt_List($5));
    }

;

empty-EoLList: 
%empty { }
| EoLList

;



subtype-section: 
variable-section 
    {
        $$=$1;
    }
    |   %empty { };

subprogram-decl: 
subprogram-decl-list 
    {
        $$ = $1;
    } 
|       %empty { }

;

variable-section: 
variable-decl EoLList 
    {
        $$ = $1;
    }

;

EoLList: 
EoLList EoL 
| EoL

;

opt-EoL: 
EoL 
| %empty { }

;

variable-decl: 
variable-decl EoL type ident-list 
    {
        $$=$1;
        $$.push_back(new AST::Var_Decl($3, $4));
    } 
| type ident-list 
    {
        $$.push_back(new AST::Var_Decl($1, $2));
    }
;

ident-list: 
ident-list "," "ID" 
    {
        $$ = $1;
        $$.push_back($3);
    }
| "ID" 
    {
        $$.push_back($1);
    }

;

type: 
"entero" { $$ = new AST::Type_N("int", 0, nullptr); }

| "caracter" { $$ = new AST::Type_N("char", 0, nullptr); }

| "booleano" { $$ = new AST::Type_N("bool", 0, nullptr); }

| "arreglo" "[" "intConstant" "]" "de" type
    {
        $$ = new AST::Type_N("arr", $3, $6);
    }

;


subprogram-decl-list: 
subprogram-decl-list subprogramDecl 
    {
        $$ = $1;
        $$.push_back($2);
    } 
| subprogramDecl 
    {
        $$.push_back($1);
    }

;

subprogramDecl: 
"funcion" "ID"  argument-opt ":" type EoLList subtype-section "inicio" EoLList stmts EoLList "fin" EoL
    {       
        std::vector<AST::Node*> PARAM_FUNCION;
        int bytes = 8;
        for(auto &a : $3)
        {
            AST::Argument_N* arg = static_cast<AST::Argument_N*>(a);
            arg->pos = bytes;
            PARAM_FUNCION.push_back(arg);
            bytes += 4;
        }
        $$ = new AST::Func_Decl($2, PARAM_FUNCION, $5, $7, new AST::Stmt_List($10));
    }
|"procedimiento" "ID" argument-opt EoLList subtype-section "inicio" EoLList stmts EoLList "fin" EoL
    {
        std::vector<AST::Node*> PARAM_PROCEDIMIENTO;
        int bytes = 8;
        for(auto &a : $3){
            AST::Argument_N* arg = static_cast<AST::Argument_N*>(a);
            arg->pos = bytes;
            PARAM_PROCEDIMIENTO.push_back(arg);
            bytes += 4;
    }
    $$ = new AST::Proc_Decl($2, PARAM_PROCEDIMIENTO, $5, new AST::Stmt_List($8));
}

;

argument-opt: 
"(" argument-comma ")" 
    {
        $$ = $2;
    }
| %empty 
    {
        std::vector<AST::Node*> empty;
        $$ = empty;
    }
    
;


argument-comma: 
argument-comma "," argument-decl 
    {
        $$ = $1;
        $$.push_back($3);
    }
| argument-decl 
    {
        $$.push_back($1);
    }
    
;

argument-decl: "var" type "ID" 
    {
        $$ = new AST::Argument_N($2, $3, 1, 0);
    }
| type "ID" 
    {
        $$ = new AST::Argument_N($1, $2, 0, 0);
    }

;   

argument-comma-list: 
argument-comma-list "," argument 
    {
        $$ = $1;
        $$.push_back($3);
    }
| argument 
    {
        $$.push_back($1);
    }

;

argument: 
"stringConstant" 
    {
        $$ = new AST::S_Constant($1);
    }
| expr 
    {
        $$ = $1;
    }

;

statement: 
lvalue "<-" expr 
    {
        $$ = new AST::AssignStmt($1, $3);
    }
|"llamar" "ID" "(" optional-expr ")" 
    {
        $$ = new AST::Program_Call($2, $4);
    }
|"llamar" "ID"
    {
        node_l empty;
        $$ = new AST::Program_Call($2, empty);
    }
|"escriba" argument-comma-list 
    {
        $$ = new AST::PrintStmt($2); 
    }
|"retorne" { }

|"retorne" expr 
    {
        $$ = new AST::RetrnStmt($2);
    }
|if-statement

|"mientras" expr "haga" EoLList stmts EoLList "fin" "mientras" 
    {
        AST::Node* block = new AST::Stmt_List($5);
        $$ = new AST::WhileStmt($2, block, "", "");
    }
|"repita" EoLList stmts EoLList "hasta" expr
    {
        $$ = new AST::RptStmt($6, new AST::Stmt_List($3));
    }
|"para" lvalue "<-" expr "hasta" expr "haga" EoLList stmts EoLList "fin" "para"
    {
        AST::Node* assign = new AST::AssignStmt($2, $4);
        $$ = new AST::ForStmt(assign, $6, new AST::Stmt_List($9), "", "");
    }   

;

stmts: 
stmts EoLList statement 
    {
        $$ = $1;
        $$.push_back($3);
    }
|statement 
    {
        $$.push_back($1);
    }
    
;

exprList: exprList "," expr 
    {
        $$ = $1;
        $$.push_back($3);
    }
| expr
    {
        $$.push_back($1);
    }

;

optional-expr: exprList { $$ = $1; }
| %empty 
    {
        std::vector<AST::Node*> empty;
        $$ = empty;
    }

;


if-statement:
    "si" expr opt-EoL "entonces"  EoLList stmts else-if-block "fin" "si"
    {
        $$ = new AST::IfStmt($2, new AST::Stmt_List($6), $7,"","");
    }

;

else-if-block:
EoLList "sino" else-block { $$=$3; }
| EoLList { $$ = nullptr; }

;

else-block: 
"si" expr opt-EoL "entonces" EoLList stmts else-if-block
    {
        $$ = new AST::IfStmt($2, new AST::Stmt_List($6), $7, "", "");
    }
|EoLList stmts EoLList
    {
        $$ = new AST::Stmt_List($2);
    }

;

lvalue: 
"ID" 
    {
        $$=new AST::IdExpr($1);
    }
|"ID" "[" expr "]" 
    {
        $$ = new AST::ArrayExpr($1, $3);
    }

;

expr: 
expr "<" prec
    {
        $$ = new AST::LessThanExpr($1,$3);
    }
|expr "<=" prec
    {
        $$ = new AST::LessEqThanExpr($1,$3);
    }
|expr ">" prec
    {
        $$ = new AST::GreaterThanExpr($1,$3);
    }
|expr ">=" prec
    {
        $$ = new AST::GreaterEqThanExpr($1,$3);
    }
|expr "!=" prec
    {
        $$ = new AST::NotEqualExpr($1,$3);
    }
|expr "=" prec
    {
        $$ = new AST::EqualExpr($1,$3);
    }
| prec 
    {
        $$ = $1;
    }

;

prec: prec "+" term
    {
        $$ = new AST::AddExpr($1, $3);
    }
|prec "-" term 
    {
        $$ = new AST::SubExpr($1,$3);
    }
|prec "o" term 

|term { $$ = $1; }

;

term: 
term "/" power 
    {
        if($3) $$ = new AST::DivExpr($1, $3); 
        else throw std::string("no se puede dividir entre 0");
    } 
|term "mod" power 
    {
        $$ = new AST::ModExpr($1,$3);
    }
|term "*" power
    {   
        $$ = new AST::MultExpr($1, $3);
    }
|term "y" power 
    {
        $$ = new AST::AndExpr($1, $3);
    }   
|power { $$ = $1; }

;

power: 
power "^" factor 
| factor{ $$ = $1; };

factor:
"intConstant" { $$ = new AST::NumExpr($1); }

|"charConstant"
    {
        int charC = $1[0];
        $$ = new AST::CharExpr(charC);
    }
|"verdadero" 
    {
        $$ = new AST::BoolExpr("t");
    } 
|"falso"   
    {
        $$ = new AST::BoolExpr("f");
    } 

|"ID" { $$ = new AST::IdExpr($1); }

|"ID" "(" ")" 
    {
        std::vector<AST::Node*> empty;
        $$ = new AST::Program_Call($1,empty);
    }
|"ID" "(" exprList ")"
    { 
        $$ = new AST::Program_Call($1, $3);
    }
|"ID" "[" expr "]" 
    {
        $$ = new AST::ArrayExpr($1, $3);
    }
|"(" expr ")"  { $$ = $2; }

;

%%