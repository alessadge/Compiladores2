// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file tokens.h
 ** Define the  Expr ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
// "%code requires" blocks.
#line 9 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"

    #include <unordered_map>
    #include <string>
    #include "ast.h"

#line 54 "tokens.h"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif


#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 7 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
namespace  Expr  {
#line 189 "tokens.h"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // program
      // type
      // subprogramDecl
      // argument-decl
      // argument
      // statement
      // if-statement
      // else-if-block
      // else-block
      // lvalue
      // expr
      // prec
      // term
      // power
      // factor
      char dummy1[sizeof (AST::Node*)];

      // "intConstant"
      char dummy2[sizeof (int)];

      // ident-list
      char dummy3[sizeof (std::list<std::string>)];

      // "verdadero"
      // "falso"
      // "ID"
      // "charConstant"
      // "stringConstant"
      char dummy4[sizeof (std::string)];

      // subtype-section
      // subprogram-decl
      // variable-section
      // variable-decl
      // subprogram-decl-list
      // argument-opt
      // argument-comma
      // argument-comma-list
      // stmts
      // exprList
      // optional-expr
      char dummy5[sizeof (std::vector<AST::Node*>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        FIN_ = 0,
        OpAdd = 258,
        OpSub = 259,
        OpMul = 260,
        OpDiv = 261,
        Mod = 262,
        Caret = 263,
        Assign = 264,
        Equal = 265,
        OpEqual = 266,
        NotEqual = 267,
        LessThan = 268,
        GreaterThan = 269,
        LessEqThan = 270,
        GreaterEqThan = 271,
        LeftPar = 272,
        RightPar = 273,
        LeftBracket = 274,
        RightBracket = 275,
        Colon = 276,
        Comma = 277,
        De = 278,
        Funcion = 279,
        Procedimiento = 280,
        Var = 281,
        Repita = 282,
        Hasta = 283,
        Caso = 284,
        Cerrar = 285,
        Archivo = 286,
        Secuencial = 287,
        Abrir = 288,
        Como = 289,
        No = 290,
        Div = 291,
        Inicio = 292,
        Lectura = 293,
        O = 294,
        Entonces = 295,
        Sino = 296,
        Haga = 297,
        Lea = 298,
        Escriba = 299,
        Retorne = 300,
        Tipo = 301,
        Es = 302,
        Registro = 303,
        Escritura = 304,
        Llamar = 305,
        Para = 306,
        Mientras = 307,
        Y = 308,
        Fin = 309,
        Final = 310,
        Si = 311,
        Leer = 312,
        Escribir = 313,
        Entero = 314,
        Booleano = 315,
        Caracter = 316,
        Real = 317,
        Arreglo = 318,
        Verdadero = 319,
        Falso = 320,
        Id = 321,
        Cadena = 322,
        charConstant = 323,
        stringConstant = 324,
        intConstant = 325,
        Error = 326,
        EoL = 327
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AST::Node*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AST::Node*& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::list<std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::list<std::string>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AST::Node*>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AST::Node*>& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
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
        value.template destroy< AST::Node* > ();
        break;

      case 70: // "intConstant"
        value.template destroy< int > ();
        break;

      case 84: // ident-list
        value.template destroy< std::list<std::string> > ();
        break;

      case 64: // "verdadero"
      case 65: // "falso"
      case 66: // "ID"
      case 68: // "charConstant"
      case 69: // "stringConstant"
        value.template destroy< std::string > ();
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
        value.template destroy< std::vector<AST::Node*> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::FIN_ || tok == token::OpAdd || tok == token::OpSub || tok == token::OpMul || tok == token::OpDiv || tok == token::Mod || tok == token::Caret || tok == token::Assign || tok == token::Equal || tok == token::OpEqual || tok == token::NotEqual || tok == token::LessThan || tok == token::GreaterThan || tok == token::LessEqThan || tok == token::GreaterEqThan || tok == token::LeftPar || tok == token::RightPar || tok == token::LeftBracket || tok == token::RightBracket || tok == token::Colon || tok == token::Comma || tok == token::De || tok == token::Funcion || tok == token::Procedimiento || tok == token::Var || tok == token::Repita || tok == token::Hasta || tok == token::Caso || tok == token::Cerrar || tok == token::Archivo || tok == token::Secuencial || tok == token::Abrir || tok == token::Como || tok == token::No || tok == token::Div || tok == token::Inicio || tok == token::Lectura || tok == token::O || tok == token::Entonces || tok == token::Sino || tok == token::Haga || tok == token::Lea || tok == token::Escriba || tok == token::Retorne || tok == token::Tipo || tok == token::Es || tok == token::Registro || tok == token::Escritura || tok == token::Llamar || tok == token::Para || tok == token::Mientras || tok == token::Y || tok == token::Fin || tok == token::Final || tok == token::Si || tok == token::Leer || tok == token::Escribir || tok == token::Entero || tok == token::Booleano || tok == token::Caracter || tok == token::Real || tok == token::Arreglo || tok == token::Cadena || tok == token::Error || tok == token::EoL || tok == 328);
      }
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::FIN_ || tok == token::OpAdd || tok == token::OpSub || tok == token::OpMul || tok == token::OpDiv || tok == token::Mod || tok == token::Caret || tok == token::Assign || tok == token::Equal || tok == token::OpEqual || tok == token::NotEqual || tok == token::LessThan || tok == token::GreaterThan || tok == token::LessEqThan || tok == token::GreaterEqThan || tok == token::LeftPar || tok == token::RightPar || tok == token::LeftBracket || tok == token::RightBracket || tok == token::Colon || tok == token::Comma || tok == token::De || tok == token::Funcion || tok == token::Procedimiento || tok == token::Var || tok == token::Repita || tok == token::Hasta || tok == token::Caso || tok == token::Cerrar || tok == token::Archivo || tok == token::Secuencial || tok == token::Abrir || tok == token::Como || tok == token::No || tok == token::Div || tok == token::Inicio || tok == token::Lectura || tok == token::O || tok == token::Entonces || tok == token::Sino || tok == token::Haga || tok == token::Lea || tok == token::Escriba || tok == token::Retorne || tok == token::Tipo || tok == token::Es || tok == token::Registro || tok == token::Escritura || tok == token::Llamar || tok == token::Para || tok == token::Mientras || tok == token::Y || tok == token::Fin || tok == token::Final || tok == token::Si || tok == token::Leer || tok == token::Escribir || tok == token::Entero || tok == token::Booleano || tok == token::Caracter || tok == token::Real || tok == token::Arreglo || tok == token::Cadena || tok == token::Error || tok == token::EoL || tok == 328);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::intConstant);
      }
#else
      symbol_type (int tok, const int& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::intConstant);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::Verdadero || tok == token::Falso || tok == token::Id || tok == token::charConstant || tok == token::stringConstant);
      }
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::Verdadero || tok == token::Falso || tok == token::Id || tok == token::charConstant || tok == token::stringConstant);
      }
#endif
    };

    /// Build a parser object.
     Parser  ();
    virtual ~ Parser  ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIN_ ()
      {
        return symbol_type (token::FIN_);
      }
#else
      static
      symbol_type
      make_FIN_ ()
      {
        return symbol_type (token::FIN_);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OpAdd ()
      {
        return symbol_type (token::OpAdd);
      }
#else
      static
      symbol_type
      make_OpAdd ()
      {
        return symbol_type (token::OpAdd);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OpSub ()
      {
        return symbol_type (token::OpSub);
      }
#else
      static
      symbol_type
      make_OpSub ()
      {
        return symbol_type (token::OpSub);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OpMul ()
      {
        return symbol_type (token::OpMul);
      }
#else
      static
      symbol_type
      make_OpMul ()
      {
        return symbol_type (token::OpMul);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OpDiv ()
      {
        return symbol_type (token::OpDiv);
      }
#else
      static
      symbol_type
      make_OpDiv ()
      {
        return symbol_type (token::OpDiv);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Mod ()
      {
        return symbol_type (token::Mod);
      }
#else
      static
      symbol_type
      make_Mod ()
      {
        return symbol_type (token::Mod);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Caret ()
      {
        return symbol_type (token::Caret);
      }
#else
      static
      symbol_type
      make_Caret ()
      {
        return symbol_type (token::Caret);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Assign ()
      {
        return symbol_type (token::Assign);
      }
#else
      static
      symbol_type
      make_Assign ()
      {
        return symbol_type (token::Assign);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Equal ()
      {
        return symbol_type (token::Equal);
      }
#else
      static
      symbol_type
      make_Equal ()
      {
        return symbol_type (token::Equal);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OpEqual ()
      {
        return symbol_type (token::OpEqual);
      }
#else
      static
      symbol_type
      make_OpEqual ()
      {
        return symbol_type (token::OpEqual);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NotEqual ()
      {
        return symbol_type (token::NotEqual);
      }
#else
      static
      symbol_type
      make_NotEqual ()
      {
        return symbol_type (token::NotEqual);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LessThan ()
      {
        return symbol_type (token::LessThan);
      }
#else
      static
      symbol_type
      make_LessThan ()
      {
        return symbol_type (token::LessThan);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GreaterThan ()
      {
        return symbol_type (token::GreaterThan);
      }
#else
      static
      symbol_type
      make_GreaterThan ()
      {
        return symbol_type (token::GreaterThan);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LessEqThan ()
      {
        return symbol_type (token::LessEqThan);
      }
#else
      static
      symbol_type
      make_LessEqThan ()
      {
        return symbol_type (token::LessEqThan);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GreaterEqThan ()
      {
        return symbol_type (token::GreaterEqThan);
      }
#else
      static
      symbol_type
      make_GreaterEqThan ()
      {
        return symbol_type (token::GreaterEqThan);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LeftPar ()
      {
        return symbol_type (token::LeftPar);
      }
#else
      static
      symbol_type
      make_LeftPar ()
      {
        return symbol_type (token::LeftPar);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RightPar ()
      {
        return symbol_type (token::RightPar);
      }
#else
      static
      symbol_type
      make_RightPar ()
      {
        return symbol_type (token::RightPar);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LeftBracket ()
      {
        return symbol_type (token::LeftBracket);
      }
#else
      static
      symbol_type
      make_LeftBracket ()
      {
        return symbol_type (token::LeftBracket);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RightBracket ()
      {
        return symbol_type (token::RightBracket);
      }
#else
      static
      symbol_type
      make_RightBracket ()
      {
        return symbol_type (token::RightBracket);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Colon ()
      {
        return symbol_type (token::Colon);
      }
#else
      static
      symbol_type
      make_Colon ()
      {
        return symbol_type (token::Colon);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Comma ()
      {
        return symbol_type (token::Comma);
      }
#else
      static
      symbol_type
      make_Comma ()
      {
        return symbol_type (token::Comma);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_De ()
      {
        return symbol_type (token::De);
      }
#else
      static
      symbol_type
      make_De ()
      {
        return symbol_type (token::De);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Funcion ()
      {
        return symbol_type (token::Funcion);
      }
#else
      static
      symbol_type
      make_Funcion ()
      {
        return symbol_type (token::Funcion);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Procedimiento ()
      {
        return symbol_type (token::Procedimiento);
      }
#else
      static
      symbol_type
      make_Procedimiento ()
      {
        return symbol_type (token::Procedimiento);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Var ()
      {
        return symbol_type (token::Var);
      }
#else
      static
      symbol_type
      make_Var ()
      {
        return symbol_type (token::Var);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Repita ()
      {
        return symbol_type (token::Repita);
      }
#else
      static
      symbol_type
      make_Repita ()
      {
        return symbol_type (token::Repita);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Hasta ()
      {
        return symbol_type (token::Hasta);
      }
#else
      static
      symbol_type
      make_Hasta ()
      {
        return symbol_type (token::Hasta);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Caso ()
      {
        return symbol_type (token::Caso);
      }
#else
      static
      symbol_type
      make_Caso ()
      {
        return symbol_type (token::Caso);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Cerrar ()
      {
        return symbol_type (token::Cerrar);
      }
#else
      static
      symbol_type
      make_Cerrar ()
      {
        return symbol_type (token::Cerrar);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Archivo ()
      {
        return symbol_type (token::Archivo);
      }
#else
      static
      symbol_type
      make_Archivo ()
      {
        return symbol_type (token::Archivo);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Secuencial ()
      {
        return symbol_type (token::Secuencial);
      }
#else
      static
      symbol_type
      make_Secuencial ()
      {
        return symbol_type (token::Secuencial);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Abrir ()
      {
        return symbol_type (token::Abrir);
      }
#else
      static
      symbol_type
      make_Abrir ()
      {
        return symbol_type (token::Abrir);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Como ()
      {
        return symbol_type (token::Como);
      }
#else
      static
      symbol_type
      make_Como ()
      {
        return symbol_type (token::Como);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_No ()
      {
        return symbol_type (token::No);
      }
#else
      static
      symbol_type
      make_No ()
      {
        return symbol_type (token::No);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Div ()
      {
        return symbol_type (token::Div);
      }
#else
      static
      symbol_type
      make_Div ()
      {
        return symbol_type (token::Div);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Inicio ()
      {
        return symbol_type (token::Inicio);
      }
#else
      static
      symbol_type
      make_Inicio ()
      {
        return symbol_type (token::Inicio);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Lectura ()
      {
        return symbol_type (token::Lectura);
      }
#else
      static
      symbol_type
      make_Lectura ()
      {
        return symbol_type (token::Lectura);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_O ()
      {
        return symbol_type (token::O);
      }
#else
      static
      symbol_type
      make_O ()
      {
        return symbol_type (token::O);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Entonces ()
      {
        return symbol_type (token::Entonces);
      }
#else
      static
      symbol_type
      make_Entonces ()
      {
        return symbol_type (token::Entonces);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Sino ()
      {
        return symbol_type (token::Sino);
      }
#else
      static
      symbol_type
      make_Sino ()
      {
        return symbol_type (token::Sino);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Haga ()
      {
        return symbol_type (token::Haga);
      }
#else
      static
      symbol_type
      make_Haga ()
      {
        return symbol_type (token::Haga);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Lea ()
      {
        return symbol_type (token::Lea);
      }
#else
      static
      symbol_type
      make_Lea ()
      {
        return symbol_type (token::Lea);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Escriba ()
      {
        return symbol_type (token::Escriba);
      }
#else
      static
      symbol_type
      make_Escriba ()
      {
        return symbol_type (token::Escriba);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Retorne ()
      {
        return symbol_type (token::Retorne);
      }
#else
      static
      symbol_type
      make_Retorne ()
      {
        return symbol_type (token::Retorne);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Tipo ()
      {
        return symbol_type (token::Tipo);
      }
#else
      static
      symbol_type
      make_Tipo ()
      {
        return symbol_type (token::Tipo);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Es ()
      {
        return symbol_type (token::Es);
      }
#else
      static
      symbol_type
      make_Es ()
      {
        return symbol_type (token::Es);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Registro ()
      {
        return symbol_type (token::Registro);
      }
#else
      static
      symbol_type
      make_Registro ()
      {
        return symbol_type (token::Registro);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Escritura ()
      {
        return symbol_type (token::Escritura);
      }
#else
      static
      symbol_type
      make_Escritura ()
      {
        return symbol_type (token::Escritura);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Llamar ()
      {
        return symbol_type (token::Llamar);
      }
#else
      static
      symbol_type
      make_Llamar ()
      {
        return symbol_type (token::Llamar);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Para ()
      {
        return symbol_type (token::Para);
      }
#else
      static
      symbol_type
      make_Para ()
      {
        return symbol_type (token::Para);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Mientras ()
      {
        return symbol_type (token::Mientras);
      }
#else
      static
      symbol_type
      make_Mientras ()
      {
        return symbol_type (token::Mientras);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Y ()
      {
        return symbol_type (token::Y);
      }
#else
      static
      symbol_type
      make_Y ()
      {
        return symbol_type (token::Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Fin ()
      {
        return symbol_type (token::Fin);
      }
#else
      static
      symbol_type
      make_Fin ()
      {
        return symbol_type (token::Fin);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Final ()
      {
        return symbol_type (token::Final);
      }
#else
      static
      symbol_type
      make_Final ()
      {
        return symbol_type (token::Final);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Si ()
      {
        return symbol_type (token::Si);
      }
#else
      static
      symbol_type
      make_Si ()
      {
        return symbol_type (token::Si);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Leer ()
      {
        return symbol_type (token::Leer);
      }
#else
      static
      symbol_type
      make_Leer ()
      {
        return symbol_type (token::Leer);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Escribir ()
      {
        return symbol_type (token::Escribir);
      }
#else
      static
      symbol_type
      make_Escribir ()
      {
        return symbol_type (token::Escribir);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Entero ()
      {
        return symbol_type (token::Entero);
      }
#else
      static
      symbol_type
      make_Entero ()
      {
        return symbol_type (token::Entero);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Booleano ()
      {
        return symbol_type (token::Booleano);
      }
#else
      static
      symbol_type
      make_Booleano ()
      {
        return symbol_type (token::Booleano);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Caracter ()
      {
        return symbol_type (token::Caracter);
      }
#else
      static
      symbol_type
      make_Caracter ()
      {
        return symbol_type (token::Caracter);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Real ()
      {
        return symbol_type (token::Real);
      }
#else
      static
      symbol_type
      make_Real ()
      {
        return symbol_type (token::Real);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Arreglo ()
      {
        return symbol_type (token::Arreglo);
      }
#else
      static
      symbol_type
      make_Arreglo ()
      {
        return symbol_type (token::Arreglo);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Verdadero (std::string v)
      {
        return symbol_type (token::Verdadero, std::move (v));
      }
#else
      static
      symbol_type
      make_Verdadero (const std::string& v)
      {
        return symbol_type (token::Verdadero, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Falso (std::string v)
      {
        return symbol_type (token::Falso, std::move (v));
      }
#else
      static
      symbol_type
      make_Falso (const std::string& v)
      {
        return symbol_type (token::Falso, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Id (std::string v)
      {
        return symbol_type (token::Id, std::move (v));
      }
#else
      static
      symbol_type
      make_Id (const std::string& v)
      {
        return symbol_type (token::Id, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Cadena ()
      {
        return symbol_type (token::Cadena);
      }
#else
      static
      symbol_type
      make_Cadena ()
      {
        return symbol_type (token::Cadena);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_charConstant (std::string v)
      {
        return symbol_type (token::charConstant, std::move (v));
      }
#else
      static
      symbol_type
      make_charConstant (const std::string& v)
      {
        return symbol_type (token::charConstant, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_stringConstant (std::string v)
      {
        return symbol_type (token::stringConstant, std::move (v));
      }
#else
      static
      symbol_type
      make_stringConstant (const std::string& v)
      {
        return symbol_type (token::stringConstant, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_intConstant (int v)
      {
        return symbol_type (token::intConstant, std::move (v));
      }
#else
      static
      symbol_type
      make_intConstant (const int& v)
      {
        return symbol_type (token::intConstant, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Error ()
      {
        return symbol_type (token::Error);
      }
#else
      static
      symbol_type
      make_Error ()
      {
        return symbol_type (token::Error);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EoL ()
      {
        return symbol_type (token::EoL);
      }
#else
      static
      symbol_type
      make_EoL ()
      {
        return symbol_type (token::EoL);
      }
#endif


  private:
    /// This class is not copyable.
     Parser  (const  Parser &);
     Parser & operator= (const  Parser &);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 375,     ///< Last index in yytable_.
      yynnts_ = 32,  ///< Number of nonterminal symbols.
      yyfinal_ = 5, ///< Termination state number.
      yyntokens_ = 74  ///< Number of tokens.
    };


  };


#line 7 "/home/alessandro/Desktop/Evaluaciones/Mini-Lpp/parser.y"
} //  Expr 
#line 2225 "tokens.h"





#endif // !YY_YY_TOKENS_H_INCLUDED
