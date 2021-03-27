// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 15 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"

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


#line 59 "expr_parser.cpp"


#include "tokens.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
namespace  Expr  {
#line 137 "expr_parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
   Parser :: Parser  ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.move< AST::Node* > (std::move (that.value));
        break;

      case 70: // "intConstant"
        value.move< int > (std::move (that.value));
        break;

      case 84: // ident-list
        value.move< std::list<std::string> > (std::move (that.value));
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.move< std::string > (std::move (that.value));
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.move< std::vector<AST::Node*> > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.copy< AST::Node* > (YY_MOVE (that.value));
        break;

      case 70: // "intConstant"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 84: // ident-list
        value.copy< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.copy< std::vector<AST::Node*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.move< AST::Node* > (YY_MOVE (s.value));
        break;

      case 70: // "intConstant"
        value.move< int > (YY_MOVE (s.value));
        break;

      case 84: // ident-list
        value.move< std::list<std::string> > (YY_MOVE (s.value));
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.move< std::vector<AST::Node*> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

   Parser ::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
   Parser ::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_number_type
   Parser ::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.YY_MOVE_OR_COPY< AST::Node* > (YY_MOVE (that.value));
        break;

      case 70: // "intConstant"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 84: // ident-list
        value.YY_MOVE_OR_COPY< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.YY_MOVE_OR_COPY< std::vector<AST::Node*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.move< AST::Node* > (YY_MOVE (that.value));
        break;

      case 70: // "intConstant"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 84: // ident-list
        value.move< std::list<std::string> > (YY_MOVE (that.value));
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.move< std::vector<AST::Node*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.copy< AST::Node* > (that.value);
        break;

      case 70: // "intConstant"
        value.copy< int > (that.value);
        break;

      case 84: // ident-list
        value.copy< std::list<std::string> > (that.value);
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.copy< std::string > (that.value);
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.copy< std::vector<AST::Node*> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        value.move< AST::Node* > (that.value);
        break;

      case 70: // "intConstant"
        value.move< int > (that.value);
        break;

      case 84: // ident-list
        value.move< std::list<std::string> > (that.value);
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.move< std::string > (that.value);
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        value.move< std::vector<AST::Node*> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 76: // program
      case 85: // type
      case 87: // subprogramDecl
      case 90: // argument-decl
      case 92: // argument
      case 93: // statement
      case 97: // if-statement
      case 98: // else-if-block
      case 99: // else-block
      case 100: // lvalue
      case 101: // expr
      case 102: // prec
      case 103: // term
      case 104: // power
      case 105: // factor
        yylhs.value.emplace< AST::Node* > ();
        break;

      case 70: // "intConstant"
        yylhs.value.emplace< int > ();
        break;

      case 84: // ident-list
        yylhs.value.emplace< std::list<std::string> > ();
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        yylhs.value.emplace< std::string > ();
        break;

      case 78: // subtype-section
      case 79: // subprogram-decl
      case 80: // variable-section
      case 83: // variable-decl
      case 86: // subprogram-decl-list
      case 88: // argument-opt
      case 89: // argument-comma
      case 91: // argument-comma-list
      case 94: // stmts
      case 95: // exprList
      case 96: // optional-expr
        yylhs.value.emplace< std::vector<AST::Node*> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 134 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        AST::gen_code(yystack_[1].value.as < AST::Node* > ());
        std::cout << yystack_[1].value.as < AST::Node* > ()->asm_code << std::endl;
    }
#line 1027 "expr_parser.cpp"
    break;

  case 3:
#line 142 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::Program_C(new AST::Stmt_List(yystack_[6].value.as < std::vector<AST::Node*> > ()),new AST::Stmt_List(yystack_[5].value.as < std::vector<AST::Node*> > ()),new AST::Stmt_List(yystack_[2].value.as < std::vector<AST::Node*> > ()));
    }
#line 1035 "expr_parser.cpp"
    break;

  case 4:
#line 149 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
       { }
#line 1041 "expr_parser.cpp"
    break;

  case 6:
#line 158 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ()=yystack_[0].value.as < std::vector<AST::Node*> > ();
    }
#line 1049 "expr_parser.cpp"
    break;

  case 7:
#line 161 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
               { }
#line 1055 "expr_parser.cpp"
    break;

  case 8:
#line 165 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[0].value.as < std::vector<AST::Node*> > ();
    }
#line 1063 "expr_parser.cpp"
    break;

  case 9:
#line 168 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
               { }
#line 1069 "expr_parser.cpp"
    break;

  case 10:
#line 174 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[1].value.as < std::vector<AST::Node*> > ();
    }
#line 1077 "expr_parser.cpp"
    break;

  case 14:
#line 188 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
         { }
#line 1083 "expr_parser.cpp"
    break;

  case 15:
#line 194 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ()=yystack_[3].value.as < std::vector<AST::Node*> > ();
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(new AST::Var_Decl(yystack_[1].value.as < AST::Node* > (), yystack_[0].value.as < std::list<std::string> > ()));
    }
#line 1092 "expr_parser.cpp"
    break;

  case 16:
#line 199 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(new AST::Var_Decl(yystack_[1].value.as < AST::Node* > (), yystack_[0].value.as < std::list<std::string> > ()));
    }
#line 1100 "expr_parser.cpp"
    break;

  case 17:
#line 206 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::list<std::string> > () = yystack_[2].value.as < std::list<std::string> > ();
        yylhs.value.as < std::list<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1109 "expr_parser.cpp"
    break;

  case 18:
#line 211 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::list<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1117 "expr_parser.cpp"
    break;

  case 19:
#line 218 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
         { yylhs.value.as < AST::Node* > () = new AST::Type_N("int", 0, nullptr); }
#line 1123 "expr_parser.cpp"
    break;

  case 20:
#line 220 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
             { yylhs.value.as < AST::Node* > () = new AST::Type_N("char", 0, nullptr); }
#line 1129 "expr_parser.cpp"
    break;

  case 21:
#line 222 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
             { yylhs.value.as < AST::Node* > () = new AST::Type_N("bool", 0, nullptr); }
#line 1135 "expr_parser.cpp"
    break;

  case 22:
#line 225 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::Type_N("arr", yystack_[3].value.as < int > (), yystack_[0].value.as < AST::Node* > ());
    }
#line 1143 "expr_parser.cpp"
    break;

  case 23:
#line 234 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[1].value.as < std::vector<AST::Node*> > ();
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1152 "expr_parser.cpp"
    break;

  case 24:
#line 239 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1160 "expr_parser.cpp"
    break;

  case 25:
#line 247 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {       
        std::vector<AST::Node*> vars;
        int bytes = 8;
        for(auto &a : yystack_[10].value.as < std::vector<AST::Node*> > ())
        {
            AST::Argument_N* arg = static_cast<AST::Argument_N*>(a);
            arg->pos = bytes;
            vars.push_back(arg);
            bytes += 4;
        }
        yylhs.value.as < AST::Node* > () = new AST::Func_Decl(yystack_[11].value.as < std::string > (), vars, yystack_[8].value.as < AST::Node* > (), yystack_[6].value.as < std::vector<AST::Node*> > (), new AST::Stmt_List(yystack_[3].value.as < std::vector<AST::Node*> > ()));
    }
#line 1177 "expr_parser.cpp"
    break;

  case 26:
#line 260 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        std::vector<AST::Node*> vars;
        int bytes = 8;
        for(auto &a : yystack_[8].value.as < std::vector<AST::Node*> > ()){
            AST::Argument_N* arg = static_cast<AST::Argument_N*>(a);
            arg->pos = bytes;
            vars.push_back(arg);
            bytes += 4;
    }
    yylhs.value.as < AST::Node* > () = new AST::Proc_Decl(yystack_[9].value.as < std::string > (), vars, yystack_[6].value.as < std::vector<AST::Node*> > (), new AST::Stmt_List(yystack_[3].value.as < std::vector<AST::Node*> > ()));
}
#line 1193 "expr_parser.cpp"
    break;

  case 27:
#line 276 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[1].value.as < std::vector<AST::Node*> > ();
    }
#line 1201 "expr_parser.cpp"
    break;

  case 28:
#line 280 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        std::vector<AST::Node*> empty;
        yylhs.value.as < std::vector<AST::Node*> > () = empty;
    }
#line 1210 "expr_parser.cpp"
    break;

  case 29:
#line 290 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[2].value.as < std::vector<AST::Node*> > ();
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1219 "expr_parser.cpp"
    break;

  case 30:
#line 295 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1227 "expr_parser.cpp"
    break;

  case 31:
#line 302 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::Argument_N(yystack_[1].value.as < AST::Node* > (), yystack_[0].value.as < std::string > (), 1, 0);
    }
#line 1235 "expr_parser.cpp"
    break;

  case 32:
#line 306 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::Argument_N(yystack_[1].value.as < AST::Node* > (), yystack_[0].value.as < std::string > (), 0, 0);
    }
#line 1243 "expr_parser.cpp"
    break;

  case 33:
#line 314 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[2].value.as < std::vector<AST::Node*> > ();
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1252 "expr_parser.cpp"
    break;

  case 34:
#line 319 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1260 "expr_parser.cpp"
    break;

  case 35:
#line 327 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::S_Constant(yystack_[0].value.as < std::string > ());
    }
#line 1268 "expr_parser.cpp"
    break;

  case 36:
#line 331 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = yystack_[0].value.as < AST::Node* > ();
    }
#line 1276 "expr_parser.cpp"
    break;

  case 37:
#line 339 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::AssignStmt(yystack_[2].value.as < AST::Node* > (), yystack_[0].value.as < AST::Node* > ());
    }
#line 1284 "expr_parser.cpp"
    break;

  case 38:
#line 343 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::Program_Call(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<AST::Node*> > ());
    }
#line 1292 "expr_parser.cpp"
    break;

  case 39:
#line 347 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        node_l empty;
        yylhs.value.as < AST::Node* > () = new AST::Program_Call(yystack_[0].value.as < std::string > (), empty);
    }
#line 1301 "expr_parser.cpp"
    break;

  case 40:
#line 352 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::PrintStmt(yystack_[0].value.as < std::vector<AST::Node*> > ()); 
    }
#line 1309 "expr_parser.cpp"
    break;

  case 41:
#line 355 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
           { }
#line 1315 "expr_parser.cpp"
    break;

  case 42:
#line 358 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::RetrnStmt(yystack_[0].value.as < AST::Node* > ());
    }
#line 1323 "expr_parser.cpp"
    break;

  case 43:
#line 361 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
 { yylhs.value.as < AST::Node* > () = yystack_[0].value.as < AST::Node* > (); }
#line 1329 "expr_parser.cpp"
    break;

  case 44:
#line 364 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        AST::Node* block = new AST::Stmt_List(yystack_[3].value.as < std::vector<AST::Node*> > ());
        yylhs.value.as < AST::Node* > () = new AST::WhileStmt(yystack_[6].value.as < AST::Node* > (), block, "", "");
    }
#line 1338 "expr_parser.cpp"
    break;

  case 45:
#line 369 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::RptStmt(yystack_[0].value.as < AST::Node* > (), new AST::Stmt_List(yystack_[3].value.as < std::vector<AST::Node*> > ()));
    }
#line 1346 "expr_parser.cpp"
    break;

  case 46:
#line 373 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        AST::Node* assign = new AST::AssignStmt(yystack_[10].value.as < AST::Node* > (), yystack_[8].value.as < AST::Node* > ());
        yylhs.value.as < AST::Node* > () = new AST::ForStmt(assign, yystack_[6].value.as < AST::Node* > (), new AST::Stmt_List(yystack_[3].value.as < std::vector<AST::Node*> > ()), "", "");
    }
#line 1355 "expr_parser.cpp"
    break;

  case 47:
#line 382 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[2].value.as < std::vector<AST::Node*> > ();
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1364 "expr_parser.cpp"
    break;

  case 48:
#line 387 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1372 "expr_parser.cpp"
    break;

  case 49:
#line 394 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > () = yystack_[2].value.as < std::vector<AST::Node*> > ();
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1381 "expr_parser.cpp"
    break;

  case 50:
#line 399 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < std::vector<AST::Node*> > ().push_back(yystack_[0].value.as < AST::Node* > ());
    }
#line 1389 "expr_parser.cpp"
    break;

  case 51:
#line 405 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
                        { yylhs.value.as < std::vector<AST::Node*> > () = yystack_[0].value.as < std::vector<AST::Node*> > (); }
#line 1395 "expr_parser.cpp"
    break;

  case 52:
#line 407 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        std::vector<AST::Node*> empty;
        yylhs.value.as < std::vector<AST::Node*> > () = empty;
    }
#line 1404 "expr_parser.cpp"
    break;

  case 53:
#line 417 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::IfStmt(yystack_[7].value.as < AST::Node* > (), new AST::Stmt_List(yystack_[3].value.as < std::vector<AST::Node*> > ()), yystack_[2].value.as < AST::Node* > (),"","");
    }
#line 1412 "expr_parser.cpp"
    break;

  case 54:
#line 424 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
                          { yylhs.value.as < AST::Node* > ()=yystack_[0].value.as < AST::Node* > (); }
#line 1418 "expr_parser.cpp"
    break;

  case 55:
#line 425 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
          { yylhs.value.as < AST::Node* > () = nullptr; }
#line 1424 "expr_parser.cpp"
    break;

  case 56:
#line 431 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::IfStmt(yystack_[5].value.as < AST::Node* > (), new AST::Stmt_List(yystack_[1].value.as < std::vector<AST::Node*> > ()), yystack_[0].value.as < AST::Node* > (), "", "");
    }
#line 1432 "expr_parser.cpp"
    break;

  case 57:
#line 435 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::Stmt_List(yystack_[1].value.as < std::vector<AST::Node*> > ());
    }
#line 1440 "expr_parser.cpp"
    break;

  case 58:
#line 443 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > ()=new AST::IdExpr(yystack_[0].value.as < std::string > ());
    }
#line 1448 "expr_parser.cpp"
    break;

  case 59:
#line 447 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::ArrayExpr(yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::Node* > ());
    }
#line 1456 "expr_parser.cpp"
    break;

  case 60:
#line 455 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::LessThanExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1464 "expr_parser.cpp"
    break;

  case 61:
#line 459 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::LessEqThanExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1472 "expr_parser.cpp"
    break;

  case 62:
#line 463 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::GreaterThanExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1480 "expr_parser.cpp"
    break;

  case 63:
#line 467 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::GreaterEqThanExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1488 "expr_parser.cpp"
    break;

  case 64:
#line 471 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::NotEqualExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1496 "expr_parser.cpp"
    break;

  case 65:
#line 475 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::EqualExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1504 "expr_parser.cpp"
    break;

  case 66:
#line 479 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = yystack_[0].value.as < AST::Node* > ();
    }
#line 1512 "expr_parser.cpp"
    break;

  case 67:
#line 486 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::AddExpr(yystack_[2].value.as < AST::Node* > (), yystack_[0].value.as < AST::Node* > ());
    }
#line 1520 "expr_parser.cpp"
    break;

  case 68:
#line 490 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::SubExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1528 "expr_parser.cpp"
    break;

  case 69:
#line 493 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
 { yylhs.value.as < AST::Node* > () = yystack_[2].value.as < AST::Node* > (); }
#line 1534 "expr_parser.cpp"
    break;

  case 70:
#line 495 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
      { yylhs.value.as < AST::Node* > () = yystack_[0].value.as < AST::Node* > (); }
#line 1540 "expr_parser.cpp"
    break;

  case 71:
#line 501 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        if(yystack_[0].value.as < AST::Node* > ()) yylhs.value.as < AST::Node* > () = new AST::DivExpr(yystack_[2].value.as < AST::Node* > (), yystack_[0].value.as < AST::Node* > ()); 
        else throw std::string("no se puede dividir entre 0");
    }
#line 1549 "expr_parser.cpp"
    break;

  case 72:
#line 506 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::ModExpr(yystack_[2].value.as < AST::Node* > (),yystack_[0].value.as < AST::Node* > ());
    }
#line 1557 "expr_parser.cpp"
    break;

  case 73:
#line 510 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {   
        yylhs.value.as < AST::Node* > () = new AST::MultExpr(yystack_[2].value.as < AST::Node* > (), yystack_[0].value.as < AST::Node* > ());
    }
#line 1565 "expr_parser.cpp"
    break;

  case 74:
#line 514 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::AndExpr(yystack_[2].value.as < AST::Node* > (), yystack_[0].value.as < AST::Node* > ());
    }
#line 1573 "expr_parser.cpp"
    break;

  case 75:
#line 517 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
       { yylhs.value.as < AST::Node* > () = yystack_[0].value.as < AST::Node* > (); }
#line 1579 "expr_parser.cpp"
    break;

  case 76:
#line 522 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
{ yylhs.value.as < AST::Node* > () = yystack_[2].value.as < AST::Node* > (); }
#line 1585 "expr_parser.cpp"
    break;

  case 77:
#line 523 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
        { yylhs.value.as < AST::Node* > () = yystack_[0].value.as < AST::Node* > (); }
#line 1591 "expr_parser.cpp"
    break;

  case 78:
#line 526 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
              { yylhs.value.as < AST::Node* > () = new AST::NumExpr(yystack_[0].value.as < int > ()); }
#line 1597 "expr_parser.cpp"
    break;

  case 79:
#line 529 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        int charC = yystack_[0].value.as < std::string > ()[0];
        yylhs.value.as < AST::Node* > () = new AST::CharExpr(charC);
    }
#line 1606 "expr_parser.cpp"
    break;

  case 80:
#line 534 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::BoolExpr("t");
    }
#line 1614 "expr_parser.cpp"
    break;

  case 81:
#line 538 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::BoolExpr("f");
    }
#line 1622 "expr_parser.cpp"
    break;

  case 82:
#line 542 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
      { yylhs.value.as < AST::Node* > () = new AST::IdExpr(yystack_[0].value.as < std::string > ()); }
#line 1628 "expr_parser.cpp"
    break;

  case 83:
#line 545 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        std::vector<AST::Node*> empty;
        yylhs.value.as < AST::Node* > () = new AST::Program_Call(yystack_[2].value.as < std::string > (),empty);
    }
#line 1637 "expr_parser.cpp"
    break;

  case 84:
#line 550 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    { 
        yylhs.value.as < AST::Node* > () = new AST::Program_Call(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<AST::Node*> > ());
    }
#line 1645 "expr_parser.cpp"
    break;

  case 85:
#line 554 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
    {
        yylhs.value.as < AST::Node* > () = new AST::ArrayExpr(yystack_[3].value.as < std::string > (), yystack_[1].value.as < AST::Node* > ());
    }
#line 1653 "expr_parser.cpp"
    break;

  case 86:
#line 557 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
               { yylhs.value.as < AST::Node* > () = yystack_[1].value.as < AST::Node* > (); }
#line 1659 "expr_parser.cpp"
    break;


#line 1663 "expr_parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser ::yypact_ninf_ = -89;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     -66,   -89,    14,   116,   -51,   -89,   -89,   -89,   -89,    20,
     -19,    46,   -89,   -16,    -5,   -89,     9,   -89,   -89,    15,
      41,    72,    46,   -89,   116,   -51,   -89,    88,    92,    98,
      98,   -66,   -89,    -5,    52,    94,    70,   102,   -66,   303,
      88,   -89,   116,   116,    53,    55,   -89,   116,    85,   -66,
      97,    23,    62,    68,    23,    23,   117,   -89,   -66,   -89,
     129,   -89,    81,   -89,   -89,    70,   -66,   121,   303,    23,
     -89,   -89,    11,   -89,   -89,   -89,   138,   -89,   140,    51,
       4,   156,   -89,   140,   163,   164,     2,    10,    23,   160,
      23,   -89,   -89,    85,   -66,   -66,    19,   154,    23,    97,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,   -66,   142,    32,   -89,
     -89,   140,   146,   303,   200,   -89,   -89,    58,   140,    49,
     -89,    51,    51,    51,    51,    51,    51,     4,     4,     4,
     156,   156,   156,   156,   -89,   166,   167,   111,   303,   -66,
     -89,   -66,   -66,    23,   -89,    23,   -89,   -89,    23,   -66,
     303,   303,   203,   140,   140,   127,   233,   -66,   -66,   118,
     -66,   139,   252,   141,   265,   -89,   303,   -89,   -53,   143,
     124,   -66,    23,   303,   -89,   -89,   -89,   284,    10,   -66,
     147,   161,   303,   -89,   -66,   303,   -66,   -89
  };

  const signed char
   Parser ::yydefact_[] =
  {
       4,    12,     0,     7,     5,     1,    19,    21,    20,     0,
      14,     9,     6,     0,     0,    11,     0,    13,     2,     0,
       0,     0,     8,    24,    12,    10,    18,    16,     0,    28,
      28,     0,    23,     0,     0,     0,     0,     0,     0,     0,
      15,    17,     0,     0,     0,     0,    30,     0,     7,     0,
       0,    41,     0,     0,     0,     0,    58,    48,     0,    43,
       0,    22,     0,    32,    27,     0,     0,     0,     0,     0,
      80,    81,    82,    79,    35,    78,    40,    34,    36,    66,
      70,    75,    77,    42,    39,     0,     0,    14,     0,     0,
       0,    31,    29,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     3,
      47,    37,     0,     0,     0,    86,    83,     0,    50,     0,
      33,    65,    60,    62,    61,    63,    64,    67,    68,    69,
      73,    71,    72,    74,    76,    51,     0,     0,     0,     0,
      59,     0,     0,     0,    84,     0,    85,    38,     0,     0,
       0,     0,     0,    45,    49,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,    26,     0,    44,     0,     0,
       0,     0,     0,     0,    54,    53,    25,     0,    14,     0,
       0,     0,    57,    46,     0,     0,     0,    56
  };

  const short
   Parser ::yypgoto_[] =
  {
     -89,   -89,   -89,   -89,   -21,   -89,   -89,     0,   -85,   -89,
     169,   150,   -89,   181,   176,   -89,   144,   -89,   108,   -88,
     -63,   103,   -89,   -89,    12,   -89,   168,   -47,   133,    -6,
     130,   110
  };

  const short
   Parser ::yydefgoto_[] =
  {
      -1,     2,    10,     3,    11,    21,    12,   172,    18,    13,
      27,    14,    22,    23,    37,    45,    46,    76,    77,    57,
      58,   127,   146,    59,   173,   184,    60,    78,    79,    80,
      81,    82
  };

  const unsigned char
   Parser ::yytable_[] =
  {
       4,   120,   117,   182,    83,    95,     1,    86,    87,   109,
     110,   111,   100,    25,     5,   101,   102,   103,   104,     1,
     100,    15,    96,   101,   102,   103,   104,    67,    97,   100,
      98,    39,   101,   102,   103,   104,   120,   125,    48,    16,
      69,   118,   100,   121,   116,   101,   102,   103,   104,    68,
     128,   129,   150,    17,   106,   107,    24,   112,    89,   100,
     152,    26,   101,   102,   103,   104,    93,   128,   147,   156,
      19,    20,   122,    64,   120,   105,   154,    65,   120,    28,
     155,    29,    17,   105,   120,   159,   120,    70,    71,    72,
     108,    73,   105,    75,   123,   124,    43,   167,   168,   120,
     137,   138,   139,   191,   120,   105,   163,    30,   164,    31,
      34,   165,    35,   181,    69,    36,   148,    42,    41,    63,
     189,   100,   105,    47,   101,   102,   103,   104,    84,     6,
       7,     8,   196,     9,    56,   188,    88,   100,    90,   158,
     101,   102,   103,   104,     6,     7,     8,    91,     9,   160,
     100,   161,   162,   101,   102,   103,   104,    15,    94,   166,
      99,    70,    71,    72,   113,    73,    74,    75,   174,   170,
     176,    69,   126,   115,    33,     6,     7,     8,   183,     9,
     114,   187,   149,   151,   105,   157,    44,    49,   155,   192,
     175,   177,    61,    62,   195,   179,   186,    66,   193,   185,
     105,   194,    40,    32,    50,    51,    38,   130,   197,    92,
      52,    53,    54,   105,   119,    44,    55,   145,    70,    71,
      72,    85,    73,   144,    75,     0,    56,    49,   153,     0,
      49,     0,    15,   131,   132,   133,   134,   135,   136,   140,
     141,   142,   143,     0,    50,    51,     0,    50,    51,     0,
      52,    53,    54,    52,    53,    54,    55,   169,     0,    55,
      49,     0,     0,     0,     0,     0,    56,     0,     0,    56,
       0,     0,    15,     0,     0,    15,     0,    50,    51,    49,
       0,     0,     0,    52,    53,    54,     0,   171,     0,    55,
       0,     0,    49,   178,     0,     0,    50,    51,     0,    56,
       0,     0,    52,    53,    54,    15,     0,     0,    55,    50,
      51,    49,     0,     0,     0,    52,    53,    54,    56,   180,
       0,    55,     0,     0,    15,     0,     0,     0,    50,    51,
      49,    56,     0,     0,    52,    53,    54,    15,   190,     0,
      55,     0,     0,     0,     0,     0,     0,    50,    51,     0,
      56,     0,     0,    52,    53,    54,    15,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,    15
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    89,    87,    56,    51,    68,    72,    54,    55,     5,
       6,     7,    10,    13,     0,    13,    14,    15,    16,    72,
      10,    72,    69,    13,    14,    15,    16,    48,    17,    10,
      19,    31,    13,    14,    15,    16,   124,    18,    38,    19,
      17,    88,    10,    90,    42,    13,    14,    15,    16,    49,
      97,    98,    20,    72,     3,     4,    72,    53,    58,    10,
     123,    66,    13,    14,    15,    16,    66,   114,   115,    20,
      24,    25,    93,    18,   162,    73,    18,    22,   166,    70,
      22,    66,    72,    73,   172,   148,   174,    64,    65,    66,
      39,    68,    73,    70,    94,    95,    26,   160,   161,   187,
     106,   107,   108,   188,   192,    73,   153,    66,   155,    37,
      22,   158,    20,   176,    17,    17,   116,    23,    66,    66,
     183,    10,    73,    21,    13,    14,    15,    16,    66,    59,
      60,    61,   195,    63,    66,   182,    19,    10,     9,    28,
      13,    14,    15,    16,    59,    60,    61,    66,    63,   149,
      10,   151,   152,    13,    14,    15,    16,    72,    37,   159,
      22,    64,    65,    66,     8,    68,    69,    70,   168,    42,
     170,    17,    18,     9,    24,    59,    60,    61,   178,    63,
      17,   181,    40,    37,    73,    18,    36,    27,    22,   189,
      72,    52,    42,    43,   194,    54,    72,    47,    51,    56,
      73,    40,    33,    22,    44,    45,    30,    99,   196,    65,
      50,    51,    52,    73,    54,    65,    56,   114,    64,    65,
      66,    53,    68,   113,    70,    -1,    66,    27,    28,    -1,
      27,    -1,    72,   100,   101,   102,   103,   104,   105,   109,
     110,   111,   112,    -1,    44,    45,    -1,    44,    45,    -1,
      50,    51,    52,    50,    51,    52,    56,    54,    -1,    56,
      27,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    66,
      -1,    -1,    72,    -1,    -1,    72,    -1,    44,    45,    27,
      -1,    -1,    -1,    50,    51,    52,    -1,    54,    -1,    56,
      -1,    -1,    27,    41,    -1,    -1,    44,    45,    -1,    66,
      -1,    -1,    50,    51,    52,    72,    -1,    -1,    56,    44,
      45,    27,    -1,    -1,    -1,    50,    51,    52,    66,    54,
      -1,    56,    -1,    -1,    72,    -1,    -1,    -1,    44,    45,
      27,    66,    -1,    -1,    50,    51,    52,    72,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      66,    -1,    -1,    50,    51,    52,    72,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    72
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    72,    75,    77,    81,     0,    59,    60,    61,    63,
      76,    78,    80,    83,    85,    72,    19,    72,    82,    24,
      25,    79,    86,    87,    72,    81,    66,    84,    70,    66,
      66,    37,    87,    85,    22,    20,    17,    88,    88,    81,
      84,    66,    23,    26,    85,    89,    90,    21,    81,    27,
      44,    45,    50,    51,    52,    56,    66,    93,    94,    97,
     100,    85,    85,    66,    18,    22,    85,    78,    81,    17,
      64,    65,    66,    68,    69,    70,    91,    92,   101,   102,
     103,   104,   105,   101,    66,   100,   101,   101,    19,    81,
       9,    66,    90,    81,    37,    94,   101,    17,    19,    22,
      10,    13,    14,    15,    16,    73,     3,     4,    39,     5,
       6,     7,    53,     8,    17,     9,    42,    82,   101,    54,
      93,   101,    78,    81,    81,    18,    18,    95,   101,   101,
      92,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     104,   104,   104,   104,   105,    95,    96,   101,    81,    40,
      20,    37,    94,    28,    18,    22,    20,    18,    28,    94,
      81,    81,    81,   101,   101,   101,    81,    94,    94,    54,
      42,    54,    81,    98,    81,    72,    81,    52,    41,    54,
      54,    94,    56,    81,    99,    56,    72,    81,   101,    94,
      54,    82,    81,    51,    40,    81,    94,    98
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    74,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     3,     7,     0,     1,     1,     0,     1,     0,
       2,     2,     1,     1,     0,     4,     2,     3,     1,     1,
       1,     1,     6,     2,     1,    13,    11,     3,     0,     3,
       1,     3,     2,     3,     1,     1,     1,     3,     5,     2,
       2,     1,     2,     1,     8,     6,    12,     3,     1,     3,
       1,     1,     0,     9,     3,     1,     7,     3,     1,     4,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"EOF\"", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"mod\"", "\"^\"", "\"<-\"", "\"=\"", "\"==\"", "\"<>\"", "\"<\"",
  "\">\"", "\"<=\"", "\">=\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\":\"",
  "\",\"", "\"de\"", "\"funcion\"", "\"procedimiento\"", "\"var\"",
  "\"repita\"", "\"hasta\"", "\"caso\"", "\"cerrar\"", "\"archivo\"",
  "\"secuencial\"", "\"abrir\"", "\"como\"", "\"no\"", "\"div\"",
  "\"inicio\"", "\"lectura\"", "\"o\"", "\"entonces\"", "\"sino\"",
  "\"haga\"", "\"lea\"", "\"escriba\"", "\"retorne\"", "\"tipo\"",
  "\"es\"", "\"registro\"", "\"escritura\"", "\"llamar\"", "\"para\"",
  "\"mientras\"", "\"y\"", "\"fin\"", "\"final\"", "\"si\"", "\"leer\"",
  "\"escribir\"", "\"entero\"", "\"booleano\"", "\"caracter\"", "\"real\"",
  "\"arreglo\"", "\"verdadero\"", "\"falso\"", "\"ID\"", "\"cadena\"",
  "\"charConstant\"", "\"stringConstant\"", "\"intConstant\"", "Error",
  "EoL", "\"!=\"", "$accept", "start", "program", "empty-EoLList",
  "subtype-section", "subprogram-decl", "variable-section", "EoLList",
  "opt-EoL", "variable-decl", "ident-list", "type", "subprogram-decl-list",
  "subprogramDecl", "argument-opt", "argument-comma", "argument-decl",
  "argument-comma-list", "argument", "statement", "stmts", "exprList",
  "optional-expr", "if-statement", "else-if-block", "else-block", "lvalue",
  "expr", "prec", "term", "power", "factor", YY_NULLPTR
  };

#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   133,   133,   141,   149,   150,   157,   161,   164,   168,
     173,   181,   182,   187,   188,   193,   198,   205,   210,   218,
     220,   222,   224,   233,   238,   246,   259,   275,   279,   289,
     294,   301,   305,   313,   318,   326,   330,   338,   342,   346,
     351,   355,   357,   361,   363,   368,   372,   381,   386,   393,
     398,   405,   406,   416,   424,   425,   430,   434,   442,   446,
     454,   458,   462,   466,   470,   474,   478,   485,   489,   493,
     495,   500,   505,   509,   513,   517,   522,   523,   526,   528,
     533,   537,   542,   544,   549,   553,   557
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
    };
    const int user_token_number_max_ = 328;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 7 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
} //  Expr 
#line 2269 "expr_parser.cpp"

#line 561 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
