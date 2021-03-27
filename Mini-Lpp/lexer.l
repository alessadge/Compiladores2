%option noyywrap
%option yylineno
%option caseless

%{

#include <cstring>
#include <cstdio>
#include <iostream>
#include "tokens.h"

#define YY_DECL int yylex(Expr::Parser::semantic_type *yylval)
#define yyterminate() return Expr::Parser::token::FIN_

%}



%x BlockComment StartString
%x StartChar


%%

#Operands
"+" return Expr::Parser::token::OpAdd;
"-" return Expr::Parser::token::OpSub;
"/" return Expr::Parser::token::OpDiv;
"*" return Expr::Parser::token::OpMul;

#LogicOperands
"<-" return Expr::Parser::token::Assign;
"=" return Expr::Parser::token::Equal;
"==" return Expr::Parser::token::OpEqual;
"<>" return Expr::Parser::token::NotEqual;
"<" return Expr::Parser::token::LessThan;
">" return Expr::Parser::token::GreaterThan;
"<=" return Expr::Parser::token::LessEqThan;
">=" return Expr::Parser::token::GreaterEqThan;

#Symbols
"[" return Expr::Parser::token::LeftBracket;
"]" return Expr::Parser::token::RightBracket;
"(" return Expr::Parser::token::LeftPar;
")" return Expr::Parser::token::RightPar;
"," return Expr::Parser::token::Comma;
":" return Expr::Parser::token::Colon;
"^" return Expr::Parser::token::Caret;

#Types
"booleano" return Expr::Parser::token::Booleano;
"caracter" return Expr::Parser::token::Caracter;
"arreglo" return Expr::Parser::token::Arreglo;
"real" return Expr::Parser::token::Real;
"cadena" return Expr::Parser::token::Cadena;
"entero" return Expr::Parser::token::Entero;

#ReservedWords
"es" return Expr::Parser::token::Es;
"caso" return Expr::Parser::token::Caso;
"o" return Expr::Parser::token::O;
"y" return Expr::Parser::token::Y;
"no" return Expr::Parser::token::No;
"registro" return Expr::Parser::token::Registro;
"abrir" return Expr::Parser::token::Abrir;
"de" return Expr::Parser::token::De;
"funcion" return Expr::Parser::token::Funcion;
"procedimiento" return Expr::Parser::token::Procedimiento;
"var" return Expr::Parser::token::Var;
"inicio" return Expr::Parser::token::Inicio;
"fin" return Expr::Parser::token::Fin;
"leer" return Expr::Parser::token::Leer;
"escribir" return Expr::Parser::token::Escribir;
"verdadero" return Expr::Parser::token::Verdadero;
"falso" return Expr::Parser::token::Falso;
"tipo" return Expr::Parser::token::Tipo;
"final" return Expr::Parser::token::Final;
"si" return Expr::Parser::token::Si;
"entonces" return Expr::Parser::token::Entonces;
"sino" return Expr::Parser::token::Sino;
"para" return Expr::Parser::token::Para;
"mientras" return Expr::Parser::token::Mientras;
"haga" return Expr::Parser::token::Haga;
"llamar" return Expr::Parser::token::Llamar;
"como" return Expr::Parser::token::Como;
"lectura" return Expr::Parser::token::Lectura;
"escritura" return Expr::Parser::token::Escritura;
"cerrar" return Expr::Parser::token::Cerrar;
"archivo" return Expr::Parser::token::Archivo;
"secuencial" return Expr::Parser::token::Secuencial;
"repita" return Expr::Parser::token::Repita;
"hasta" return Expr::Parser::token::Hasta;
"div" return Expr::Parser::token::Div;
"mod" return Expr::Parser::token::Mod;
"lea" return Expr::Parser::token::Lea;
"escriba" return Expr::Parser::token::Escriba;
"retorne" return Expr::Parser::token::Retorne;

\" BEGIN(StartString);
#Primitive
[0-9]* {yylval->emplace<int>(atoi(yytext)); return Expr::Parser::token::intConstant;}
[1-9][0-9]*\.[0-9]+ {yylval->emplace<double>(strtod(yytext, nullptr)); return Expr::Parser::token::Real;}
[_a-zA-Z][a-zA-Z0-9_]* {yylval->emplace<std::string>(yytext, yyleng); return Expr::Parser::token::Id;}
"//"[^\n]*(\n)* {/* ignorar */}

#Dividers
[ \t]*
[\n]* return Expr::Parser::token::EoL;

"/*" BEGIN(BlockComment);
\' BEGIN(StartChar);

. return Expr::Parser::token::Error;


<BlockComment>{
"*/"      BEGIN(INITIAL);
[^*\n]+   
"*"
\n        yylineno++;
}

<StartChar>{
\' BEGIN(INITIAL);
[\x20-\x7E] {
yylval->emplace<std::string>(yytext, yyleng); return Expr::Parser::token::charConstant;}
}

<StartString>{
\" BEGIN(INITIAL);
[ \t]
[^\"]* {yylval->emplace<std::string>(yytext, yyleng); return Expr::Parser::token::stringConstant;}
}




%%