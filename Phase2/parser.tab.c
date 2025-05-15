/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	void yyerror(char* s);
	int yylex();
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include "./semantic.h"  // Include semantic analysis header
	void ins();
	void insV();
	int flag=0;

	#define ANSI_COLOR_RED		"\x1b[31m"
	#define ANSI_COLOR_GREEN	"\x1b[32m"
	#define ANSI_COLOR_CYAN		"\x1b[36m"
	#define ANSI_COLOR_RESET	"\x1b[0m"

	extern char curid[20];
	extern char curtype[20];
	extern char curval[20];
	
	// Symbol table structure from scanner.l
	extern struct symboltable {
		char name[100];
		char class[100];
		char type[100];
		char value[100];
		int lineno;
		int length;
		int scope;
	} ST[1001];
	
	// Current function for return type checking
	char current_function[100];
	char current_function_type[100];
	
	// Variable to store expression type
	char expression_type[100];


#line 112 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 7,                     /* DOUBLE  */
  YYSYMBOL_LONG = 8,                       /* LONG  */
  YYSYMBOL_SHORT = 9,                      /* SHORT  */
  YYSYMBOL_SIGNED = 10,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 11,                  /* UNSIGNED  */
  YYSYMBOL_STRUCT = 12,                    /* STRUCT  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_ENDIF = 20,                     /* ENDIF  */
  YYSYMBOL_identifier = 21,                /* identifier  */
  YYSYMBOL_integer_constant = 22,          /* integer_constant  */
  YYSYMBOL_string_constant = 23,           /* string_constant  */
  YYSYMBOL_float_constant = 24,            /* float_constant  */
  YYSYMBOL_character_constant = 25,        /* character_constant  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_leftshift_assignment_operator = 27, /* leftshift_assignment_operator  */
  YYSYMBOL_rightshift_assignment_operator = 28, /* rightshift_assignment_operator  */
  YYSYMBOL_XOR_assignment_operator = 29,   /* XOR_assignment_operator  */
  YYSYMBOL_OR_assignment_operator = 30,    /* OR_assignment_operator  */
  YYSYMBOL_AND_assignment_operator = 31,   /* AND_assignment_operator  */
  YYSYMBOL_modulo_assignment_operator = 32, /* modulo_assignment_operator  */
  YYSYMBOL_multiplication_assignment_operator = 33, /* multiplication_assignment_operator  */
  YYSYMBOL_division_assignment_operator = 34, /* division_assignment_operator  */
  YYSYMBOL_addition_assignment_operator = 35, /* addition_assignment_operator  */
  YYSYMBOL_subtraction_assignment_operator = 36, /* subtraction_assignment_operator  */
  YYSYMBOL_assignment_operator = 37,       /* assignment_operator  */
  YYSYMBOL_OR_operator = 38,               /* OR_operator  */
  YYSYMBOL_AND_operator = 39,              /* AND_operator  */
  YYSYMBOL_pipe_operator = 40,             /* pipe_operator  */
  YYSYMBOL_caret_operator = 41,            /* caret_operator  */
  YYSYMBOL_amp_operator = 42,              /* amp_operator  */
  YYSYMBOL_equality_operator = 43,         /* equality_operator  */
  YYSYMBOL_inequality_operator = 44,       /* inequality_operator  */
  YYSYMBOL_lessthan_assignment_operator = 45, /* lessthan_assignment_operator  */
  YYSYMBOL_lessthan_operator = 46,         /* lessthan_operator  */
  YYSYMBOL_greaterthan_assignment_operator = 47, /* greaterthan_assignment_operator  */
  YYSYMBOL_greaterthan_operator = 48,      /* greaterthan_operator  */
  YYSYMBOL_leftshift_operator = 49,        /* leftshift_operator  */
  YYSYMBOL_rightshift_operator = 50,       /* rightshift_operator  */
  YYSYMBOL_add_operator = 51,              /* add_operator  */
  YYSYMBOL_subtract_operator = 52,         /* subtract_operator  */
  YYSYMBOL_multiplication_operator = 53,   /* multiplication_operator  */
  YYSYMBOL_division_operator = 54,         /* division_operator  */
  YYSYMBOL_modulo_operator = 55,           /* modulo_operator  */
  YYSYMBOL_SIZEOF = 56,                    /* SIZEOF  */
  YYSYMBOL_tilde_operator = 57,            /* tilde_operator  */
  YYSYMBOL_exclamation_operator = 58,      /* exclamation_operator  */
  YYSYMBOL_increment_operator = 59,        /* increment_operator  */
  YYSYMBOL_decrement_operator = 60,        /* decrement_operator  */
  YYSYMBOL_61_ = 61,                       /* ';'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_65_ = 65,                       /* '{'  */
  YYSYMBOL_66_ = 66,                       /* '}'  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_declaration_list = 72,          /* declaration_list  */
  YYSYMBOL_D = 73,                         /* D  */
  YYSYMBOL_declaration = 74,               /* declaration  */
  YYSYMBOL_variable_declaration = 75,      /* variable_declaration  */
  YYSYMBOL_variable_declaration_list = 76, /* variable_declaration_list  */
  YYSYMBOL_V = 77,                         /* V  */
  YYSYMBOL_variable_declaration_identifier = 78, /* variable_declaration_identifier  */
  YYSYMBOL_79_1 = 79,                      /* $@1  */
  YYSYMBOL_vdi = 80,                       /* vdi  */
  YYSYMBOL_identifier_array_type = 81,     /* identifier_array_type  */
  YYSYMBOL_initilization_params = 82,      /* initilization_params  */
  YYSYMBOL_initilization = 83,             /* initilization  */
  YYSYMBOL_type_specifier = 84,            /* type_specifier  */
  YYSYMBOL_unsigned_grammar = 85,          /* unsigned_grammar  */
  YYSYMBOL_signed_grammar = 86,            /* signed_grammar  */
  YYSYMBOL_long_grammar = 87,              /* long_grammar  */
  YYSYMBOL_short_grammar = 88,             /* short_grammar  */
  YYSYMBOL_structure_definition = 89,      /* structure_definition  */
  YYSYMBOL_90_2 = 90,                      /* $@2  */
  YYSYMBOL_91_3 = 91,                      /* $@3  */
  YYSYMBOL_92_4 = 92,                      /* $@4  */
  YYSYMBOL_V1 = 93,                        /* V1  */
  YYSYMBOL_structure_declaration = 94,     /* structure_declaration  */
  YYSYMBOL_function_declaration = 95,      /* function_declaration  */
  YYSYMBOL_function_declaration_type = 96, /* function_declaration_type  */
  YYSYMBOL_function_declaration_param_statement = 97, /* function_declaration_param_statement  */
  YYSYMBOL_params = 98,                    /* params  */
  YYSYMBOL_parameters_list = 99,           /* parameters_list  */
  YYSYMBOL_parameters_identifier_list = 100, /* parameters_identifier_list  */
  YYSYMBOL_parameters_identifier_list_breakup = 101, /* parameters_identifier_list_breakup  */
  YYSYMBOL_param_identifier = 102,         /* param_identifier  */
  YYSYMBOL_103_5 = 103,                    /* $@5  */
  YYSYMBOL_param_identifier_breakup = 104, /* param_identifier_breakup  */
  YYSYMBOL_statement = 105,                /* statement  */
  YYSYMBOL_compound_statement = 106,       /* compound_statement  */
  YYSYMBOL_107_6 = 107,                    /* $@6  */
  YYSYMBOL_statment_list = 108,            /* statment_list  */
  YYSYMBOL_expression_statment = 109,      /* expression_statment  */
  YYSYMBOL_conditional_statements = 110,   /* conditional_statements  */
  YYSYMBOL_conditional_statements_breakup = 111, /* conditional_statements_breakup  */
  YYSYMBOL_iterative_statements = 112,     /* iterative_statements  */
  YYSYMBOL_return_statement = 113,         /* return_statement  */
  YYSYMBOL_return_statement_breakup = 114, /* return_statement_breakup  */
  YYSYMBOL_break_statement = 115,          /* break_statement  */
  YYSYMBOL_string_initilization = 116,     /* string_initilization  */
  YYSYMBOL_array_initialization = 117,     /* array_initialization  */
  YYSYMBOL_array_int_declarations = 118,   /* array_int_declarations  */
  YYSYMBOL_array_int_declarations_breakup = 119, /* array_int_declarations_breakup  */
  YYSYMBOL_expression = 120,               /* expression  */
  YYSYMBOL_expression_breakup = 121,       /* expression_breakup  */
  YYSYMBOL_simple_expression = 122,        /* simple_expression  */
  YYSYMBOL_simple_expression_breakup = 123, /* simple_expression_breakup  */
  YYSYMBOL_and_expression = 124,           /* and_expression  */
  YYSYMBOL_and_expression_breakup = 125,   /* and_expression_breakup  */
  YYSYMBOL_unary_relation_expression = 126, /* unary_relation_expression  */
  YYSYMBOL_regular_expression = 127,       /* regular_expression  */
  YYSYMBOL_regular_expression_breakup = 128, /* regular_expression_breakup  */
  YYSYMBOL_relational_operators = 129,     /* relational_operators  */
  YYSYMBOL_sum_expression = 130,           /* sum_expression  */
  YYSYMBOL_sum_operators = 131,            /* sum_operators  */
  YYSYMBOL_term = 132,                     /* term  */
  YYSYMBOL_MULOP = 133,                    /* MULOP  */
  YYSYMBOL_factor = 134,                   /* factor  */
  YYSYMBOL_mutable = 135,                  /* mutable  */
  YYSYMBOL_mutable_breakup = 136,          /* mutable_breakup  */
  YYSYMBOL_immutable = 137,                /* immutable  */
  YYSYMBOL_call = 138,                     /* call  */
  YYSYMBOL_139_7 = 139,                    /* $@7  */
  YYSYMBOL_arguments = 140,                /* arguments  */
  YYSYMBOL_arguments_list = 141,           /* arguments_list  */
  YYSYMBOL_A = 142,                        /* A  */
  YYSYMBOL_constant = 143                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      67,    68,     2,     2,    62,     2,    69,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    66,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    86,    89,    90,    93,    94,    95,    98,
      99,   102,   105,   106,   109,   109,   122,   122,   125,   126,
     129,   130,   133,   134,   135,   138,   138,   138,   138,   139,
     140,   141,   142,   143,   146,   146,   146,   146,   149,   149,
     149,   149,   152,   152,   155,   155,   158,   158,   158,   158,
     160,   160,   163,   167,   170,   186,   189,   189,   192,   195,
     198,   199,   202,   202,   215,   216,   219,   219,   220,   220,
     221,   221,   222,   225,   225,   228,   229,   232,   233,   236,
     239,   240,   243,   244,   245,   248,   251,   257,   264,   267,
     270,   273,   276,   277,   280,   281,   289,   295,   296,   297,
     298,   299,   300,   301,   304,   307,   307,   310,   313,   314,
     317,   318,   321,   324,   328,   331,   331,   331,   332,   332,
     332,   335,   336,   339,   340,   343,   344,   347,   347,   347,
     350,   350,   353,   365,   368,   375,   378,   379,   379,   382,
     382,   388,   388,   391,   394,   395,   398,   399,   400,   401
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "INT", "CHAR",
  "FLOAT", "DOUBLE", "LONG", "SHORT", "SIGNED", "UNSIGNED", "STRUCT",
  "RETURN", "MAIN", "VOID", "WHILE", "FOR", "DO", "BREAK", "ENDIF",
  "identifier", "integer_constant", "string_constant", "float_constant",
  "character_constant", "ELSE", "leftshift_assignment_operator",
  "rightshift_assignment_operator", "XOR_assignment_operator",
  "OR_assignment_operator", "AND_assignment_operator",
  "modulo_assignment_operator", "multiplication_assignment_operator",
  "division_assignment_operator", "addition_assignment_operator",
  "subtraction_assignment_operator", "assignment_operator", "OR_operator",
  "AND_operator", "pipe_operator", "caret_operator", "amp_operator",
  "equality_operator", "inequality_operator",
  "lessthan_assignment_operator", "lessthan_operator",
  "greaterthan_assignment_operator", "greaterthan_operator",
  "leftshift_operator", "rightshift_operator", "add_operator",
  "subtract_operator", "multiplication_operator", "division_operator",
  "modulo_operator", "SIZEOF", "tilde_operator", "exclamation_operator",
  "increment_operator", "decrement_operator", "';'", "','", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "'.'", "$accept", "program",
  "declaration_list", "D", "declaration", "variable_declaration",
  "variable_declaration_list", "V", "variable_declaration_identifier",
  "$@1", "vdi", "identifier_array_type", "initilization_params",
  "initilization", "type_specifier", "unsigned_grammar", "signed_grammar",
  "long_grammar", "short_grammar", "structure_definition", "$@2", "$@3",
  "$@4", "V1", "structure_declaration", "function_declaration",
  "function_declaration_type", "function_declaration_param_statement",
  "params", "parameters_list", "parameters_identifier_list",
  "parameters_identifier_list_breakup", "param_identifier", "$@5",
  "param_identifier_breakup", "statement", "compound_statement", "$@6",
  "statment_list", "expression_statment", "conditional_statements",
  "conditional_statements_breakup", "iterative_statements",
  "return_statement", "return_statement_breakup", "break_statement",
  "string_initilization", "array_initialization", "array_int_declarations",
  "array_int_declarations_breakup", "expression", "expression_breakup",
  "simple_expression", "simple_expression_breakup", "and_expression",
  "and_expression_breakup", "unary_relation_expression",
  "regular_expression", "regular_expression_breakup",
  "relational_operators", "sum_expression", "sum_operators", "term",
  "MULOP", "factor", "mutable", "mutable_breakup", "immutable", "call",
  "$@7", "arguments", "arguments_list", "A", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,  -100,  -100,  -100,  -100,     6,     9,    13,    19,    18,
    -100,    56,  -100,   135,  -100,    36,  -100,  -100,  -100,   205,
    -100,  -100,  -100,  -100,  -100,     6,     9,  -100,  -100,     6,
       9,  -100,    38,  -100,  -100,  -100,    -6,     1,     5,    44,
    -100,     2,  -100,  -100,  -100,  -100,  -100,  -100,  -100,    11,
    -100,   -29,  -100,    38,  -100,  -100,  -100,    10,   171,  -100,
      20,   -16,  -100,  -100,  -100,    14,   205,  -100,     4,    53,
       8,    17,    27,   171,    34,    32,  -100,  -100,  -100,  -100,
      20,  -100,  -100,    20,  -100,    38,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,    39,  -100,    47,    68,  -100,   120,   -17,
    -100,    69,  -100,  -100,  -100,   193,  -100,    45,    73,  -100,
      48,  -100,  -100,    20,    38,  -100,  -100,    52,    20,    20,
      98,  -100,  -100,  -100,   -51,   171,    49,  -100,    20,  -100,
      20,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    58,    58,  -100,  -100,  -100,    58,    20,    20,    20,
      20,    20,    20,  -100,  -100,    20,    94,  -100,  -100,   193,
      50,    83,    99,  -100,  -100,    55,  -100,    59,    60,    57,
      20,   171,    64,  -100,    47,    68,    -5,   -17,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,    62,  -100,  -100,  -100,   -14,
    -100,  -100,  -100,  -100,   171,   171,    20,    20,    71,    63,
    -100,  -100,  -100,  -100,  -100,  -100,    74,   112,   122,  -100,
      88,    84,    20,  -100,  -100,  -100,    89,    90,   171,  -100,
      20,    93,    71,   112,  -100,  -100,  -100,    87,  -100,  -100,
    -100,   171,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    26,    27,    28,    43,    45,    41,    37,     0,
      33,     0,     2,     5,     6,     0,     8,    10,     7,    57,
      42,    29,    44,    30,    38,    43,    45,    32,    34,    43,
      45,    31,    46,     1,     4,     3,    14,     0,    13,     0,
      53,     0,    56,    39,    40,    35,    36,    14,    52,     0,
      54,    19,     9,     0,    11,    62,    58,    61,     0,    47,
       0,     0,    15,    16,    12,    65,     0,    59,     0,     0,
       0,     0,     0,     0,     0,   132,   146,   147,   148,   149,
       0,    78,    73,     0,    72,     0,    55,    67,    66,    68,
      69,    70,    71,     0,    95,   106,   109,   111,   114,   122,
     126,   131,   130,   137,   138,    51,    17,     0,     0,    18,
       0,    63,    60,     0,     0,    86,    85,     0,     0,     0,
       0,    88,   139,   110,   131,    76,     0,    77,     0,   104,
       0,   107,   119,   120,   116,   118,   115,   117,   123,   124,
     112,     0,     0,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,   102,   103,     0,     0,    94,   133,    51,
       0,    24,     0,    21,    64,     0,    87,     0,     0,     0,
     142,    76,     0,   136,   106,   109,   113,   121,   125,   101,
      99,   100,    97,    98,    96,     0,   135,    50,    48,     0,
      20,    22,    23,    89,     0,     0,     0,     0,   145,     0,
     141,    75,    74,   105,   108,   134,     0,     0,    81,    82,
       0,     0,     0,   143,   140,    49,    93,     0,     0,    79,
       0,     0,   145,     0,    91,    90,    80,     0,    84,   144,
      92,     0,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,   144,  -100,  -100,     3,   -28,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,     7,  -100,  -100,    24,    28,  -100,
    -100,  -100,  -100,    -1,  -100,  -100,  -100,  -100,  -100,   103,
    -100,  -100,  -100,  -100,  -100,   -58,  -100,  -100,   -12,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,    30,  -100,   -53,  -100,
     -59,  -100,   -99,    33,    78,    42,   -75,  -100,  -100,  -100,
      77,  -100,    43,  -100,    75,   -78,  -100,  -100,  -100,  -100,
    -100,  -100,    -3,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    35,    13,    84,    37,    54,    38,    51,
      62,    63,   109,   190,    85,    31,    27,    21,    23,    16,
      49,   105,   206,   160,    17,    18,    19,    40,    41,    42,
      56,    67,    57,    65,   111,   171,    87,   125,   172,    88,
      89,   219,    90,    91,   116,    92,   163,   192,   217,   224,
      93,   157,    94,   129,    95,   131,    96,    97,   140,   141,
      98,   142,    99,   146,   100,   101,   158,   102,   103,   170,
     199,   200,   213,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,   106,   124,    14,    48,   123,   107,    15,    60,   193,
      20,   117,   155,    22,   165,   120,    14,    24,   156,   167,
      15,    25,    26,    28,   126,    64,    39,    29,    30,    75,
      76,    77,    78,    79,    61,   124,   143,   144,   145,    32,
     124,    75,    76,    77,    78,    79,   138,   139,   108,    43,
     124,   207,   124,    45,    44,   175,    33,    36,    46,    47,
     168,    50,    52,   124,   124,    55,    80,    53,   124,   115,
      58,   113,    66,    39,   114,    83,    59,   110,    80,    75,
      76,    77,    78,    79,   118,   128,    48,    83,   179,   180,
     181,   182,   183,   184,   119,   121,   185,   210,   211,   122,
     127,   147,   148,   149,   150,   151,   152,   130,   159,   161,
     162,   198,   164,   166,   169,   186,   188,   173,   124,   124,
     189,   196,   193,   194,   197,    83,   205,   195,   153,   154,
     202,   214,   155,   212,   216,   215,   208,   209,   156,     1,
       2,     3,     4,     5,     6,     7,     8,     9,   218,   220,
      10,   223,   221,   222,   228,   231,   225,    34,   187,   201,
     226,   227,   159,   132,   133,   134,   135,   136,   137,   112,
     230,   138,   139,   232,    68,     1,     2,     3,     4,     5,
       6,     7,     8,    69,    70,   177,    10,    71,    72,    73,
      74,   191,    75,    76,    77,    78,    79,     1,     2,     3,
       4,     5,     6,     7,     8,    69,   174,   203,    10,     1,
       2,     3,     4,     5,     6,     7,     8,   204,   176,   229,
      10,   178,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,    81,     0,     0,     0,    82,     0,    83
};

static const yytype_int16 yycheck[] =
{
      58,    60,    80,     0,    32,    80,    22,     0,    37,    23,
       4,    70,    63,     4,   113,    73,    13,     4,    69,   118,
      13,     8,     9,     4,    83,    53,    19,     8,     9,    21,
      22,    23,    24,    25,    63,   113,    53,    54,    55,    21,
     118,    21,    22,    23,    24,    25,    51,    52,    64,    25,
     128,    65,   130,    29,    26,   130,     0,    21,    30,    21,
     119,    67,    61,   141,   142,    21,    58,    62,   146,    61,
      68,    67,    62,    66,    21,    67,    65,    63,    58,    21,
      22,    23,    24,    25,    67,    38,   114,    67,   147,   148,
     149,   150,   151,   152,    67,    61,   155,   196,   197,    67,
      61,    32,    33,    34,    35,    36,    37,    39,   105,    64,
      37,   170,    64,    61,    16,    21,    66,    68,   196,   197,
      37,    61,    23,    68,    67,    67,    64,    68,    59,    60,
      66,    68,    63,    62,    22,    61,   194,   195,    69,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    26,    61,
      15,    62,    68,   212,    61,    68,    66,    13,   159,   171,
     218,   220,   159,    43,    44,    45,    46,    47,    48,    66,
     223,    51,    52,   231,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   142,    15,    16,    17,    18,
      19,   161,    21,    22,    23,    24,    25,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   128,   174,    15,     4,
       5,     6,     7,     8,     9,    10,    11,   175,   141,   222,
      15,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    65,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      15,    71,    72,    74,    75,    84,    89,    94,    95,    96,
       4,    87,     4,    88,     4,     8,     9,    86,     4,     8,
       9,    85,    21,     0,    72,    73,    21,    76,    78,    84,
      97,    98,    99,    87,    88,    87,    88,    21,    76,    90,
      67,    79,    61,    62,    77,    21,   100,   102,    68,    65,
      37,    63,    80,    81,    76,   103,    62,   101,     3,    12,
      13,    16,    17,    18,    19,    21,    22,    23,    24,    25,
      58,    61,    65,    67,    75,    84,   105,   106,   109,   110,
     112,   113,   115,   120,   122,   124,   126,   127,   130,   132,
     134,   135,   137,   138,   143,    91,   120,    22,    64,    82,
      63,   104,    99,    67,    21,    61,   114,   120,    67,    67,
     105,    61,    67,   126,   135,   107,   120,    61,    38,   123,
      39,   125,    43,    44,    45,    46,    47,    48,    51,    52,
     128,   129,   131,    53,    54,    55,   133,    32,    33,    34,
      35,    36,    37,    59,    60,    63,    69,   121,   136,    75,
      93,    64,    37,   116,    64,   122,    61,   122,   120,    16,
     139,   105,   108,    68,   124,   126,   130,   132,   134,   120,
     120,   120,   120,   120,   120,   120,    21,    93,    66,    37,
      83,   116,   117,    23,    68,    68,    61,    67,   120,   140,
     141,   108,    66,   123,   125,    64,    92,    65,   105,   105,
     122,   122,    62,   142,    68,    61,    22,   118,    26,   111,
      61,    68,   120,    62,   119,    66,   105,   120,    61,   142,
     118,    68,   105
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    73,    73,    74,    74,    74,    75,
      75,    76,    77,    77,    79,    78,    80,    80,    81,    81,
      82,    82,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      86,    86,    87,    87,    88,    88,    90,    91,    92,    89,
      93,    93,    94,    95,    96,    97,    98,    98,    99,   100,
     101,   101,   103,   102,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   107,   106,   108,   108,   109,   109,   110,
     111,   111,   112,   112,   112,   113,   114,   114,   115,   116,
     117,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   122,   123,   123,   124,   125,   125,
     126,   126,   127,   128,   128,   129,   129,   129,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   137,   139,
     138,   140,   140,   141,   142,   142,   143,   143,   143,   143
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     1,     3,
       1,     2,     2,     0,     0,     3,     1,     2,     2,     0,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     2,     0,     1,     2,
       2,     0,     1,     0,     1,     0,     0,     0,     0,     9,
       2,     0,     3,     2,     3,     3,     1,     0,     2,     2,
       2,     0,     0,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     2,     0,     2,     1,     6,
       2,     0,     5,     9,     7,     2,     1,     2,     2,     2,
       4,     2,     2,     0,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     2,     3,     0,     2,     3,     0,
       2,     1,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     3,     1,     1,     0,
       5,     1,     0,     2,     3,     0,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 14: /* $@1: %empty  */
#line 109 "parser.y"
                                     { 
			    ins(); 
			    // Add scope to symbol table
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            ST[i].scope = getCurrentScope();
			            break;
			        }
			    }
			    // Check for redeclaration
			    checkVariableRedeclaration(curid);
			}
#line 1454 "parser.tab.c"
    break;

  case 46: /* $@2: %empty  */
#line 158 "parser.y"
                                            { ins(); }
#line 1460 "parser.tab.c"
    break;

  case 47: /* $@3: %empty  */
#line 158 "parser.y"
                                                           { enterScope(); }
#line 1466 "parser.tab.c"
    break;

  case 48: /* $@4: %empty  */
#line 158 "parser.y"
                                                                                     { exitScope(); }
#line 1472 "parser.tab.c"
    break;

  case 54: /* function_declaration_type: type_specifier identifier '('  */
#line 170 "parser.y"
                                                        { 
			    // Store function name and type for return type checking
			    strcpy(current_function, curid);
			    strcpy(current_function_type, curtype);
			    ins(); 
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            strcpy(ST[i].class, "Function");
			            break;
			        }
			    }
			    // Create a new scope for function
			    enterScope();
			}
#line 1491 "parser.tab.c"
    break;

  case 55: /* function_declaration_param_statement: params ')' statement  */
#line 186 "parser.y"
                                               { exitScope(); }
#line 1497 "parser.tab.c"
    break;

  case 62: /* $@5: %empty  */
#line 202 "parser.y"
                                     { 
			    ins(); 
			    // Add scope to parameter
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            ST[i].scope = getCurrentScope();
			            strcpy(ST[i].class, "Parameter");
			            break;
			        }
			    }
			}
#line 1513 "parser.tab.c"
    break;

  case 73: /* $@6: %empty  */
#line 225 "parser.y"
                              { enterScope(); }
#line 1519 "parser.tab.c"
    break;

  case 74: /* compound_statement: '{' $@6 statment_list '}'  */
#line 225 "parser.y"
                                                                  { exitScope(); }
#line 1525 "parser.tab.c"
    break;

  case 86: /* return_statement_breakup: ';'  */
#line 251 "parser.y"
                              { 
			    // Check if return type is compatible with function type
			    if (strcmp(current_function_type, "VOID") != 0) {
			        semanticError("Function with non-void return type must return a value", -1);
			    }
			}
#line 1536 "parser.tab.c"
    break;

  case 87: /* return_statement_breakup: expression ';'  */
#line 257 "parser.y"
                                         {
			    // Need to validate return type matches function type
			    // For simplicity, assuming expression_type contains the type of last expression
			    validateReturnType(current_function_type, expression_type);
			}
#line 1546 "parser.tab.c"
    break;

  case 89: /* string_initilization: assignment_operator string_constant  */
#line 267 "parser.y"
                                                              { insV(); }
#line 1552 "parser.tab.c"
    break;

  case 95: /* expression: simple_expression  */
#line 281 "parser.y"
                                            {
			    // Store expression type for return type checking
			    // This is simplified; in a real implementation, we would track the type through
			    // the expression tree
			    strcpy(expression_type, "INT"); // Default to INT for simplicity
			}
#line 1563 "parser.tab.c"
    break;

  case 96: /* expression_breakup: assignment_operator expression  */
#line 289 "parser.y"
                                                         {
			    // Type checking for assignment operations
			    if (curid[0] != '\0') {
			        checkUndeclaredVariable(curid);
			    }
			}
#line 1574 "parser.tab.c"
    break;

  case 113: /* regular_expression_breakup: relational_operators sum_expression  */
#line 324 "parser.y"
                                                              {
			    // Type checking for relational operations
			    strcpy(expression_type, "INT"); // Relational operations result in boolean (INT)
			}
#line 1583 "parser.tab.c"
    break;

  case 132: /* mutable: identifier  */
#line 353 "parser.y"
                                     {
			    // Check if variable is declared
			    checkUndeclaredVariable(curid);
			    
			    // Get type for expression type tracking
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            strcpy(expression_type, ST[i].type);
			            break;
			        }
			    }
			}
#line 1600 "parser.tab.c"
    break;

  case 134: /* mutable_breakup: '[' expression ']'  */
#line 368 "parser.y"
                                             {
			    // Validate array access - index must be integer
			    // For simplicity, we don't do full expression type checking
			    if (strcmp(expression_type, "INT") != 0) {
			        semanticError("Array index must be an integer", -1);
			    }
			}
#line 1612 "parser.tab.c"
    break;

  case 139: /* $@7: %empty  */
#line 382 "parser.y"
                                         {
			    // Check if function exists
			    checkFunctionCall(curid, 0); // Simplified: not tracking param count
			}
#line 1621 "parser.tab.c"
    break;

  case 146: /* constant: integer_constant  */
#line 398 "parser.y"
                                                { insV(); strcpy(expression_type, "INT"); }
#line 1627 "parser.tab.c"
    break;

  case 147: /* constant: string_constant  */
#line 399 "parser.y"
                                                { insV(); strcpy(expression_type, "CHAR"); }
#line 1633 "parser.tab.c"
    break;

  case 148: /* constant: float_constant  */
#line 400 "parser.y"
                                                { insV(); strcpy(expression_type, "FLOAT"); }
#line 1639 "parser.tab.c"
    break;

  case 149: /* constant: character_constant  */
#line 401 "parser.y"
                                            { insV(); strcpy(expression_type, "CHAR"); }
#line 1645 "parser.tab.c"
    break;


#line 1649 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 403 "parser.y"


extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insertSTtype(char *,char *);
void insertSTvalue(char *, char *);
void incertCT(char *, char *);
void printST();
void printCT();

int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");
	
	// Initialize semantic analyzer
	initializeSemanticAnalyzer();
	
	yyparse();

	if(flag == 0)
	{
		printf(ANSI_COLOR_GREEN "Status: Parsing Complete - Valid" ANSI_COLOR_RESET "\n");
		
		// Perform semantic analysis after successful parsing
		performSemanticAnalysis();
		
		printf("%30s" ANSI_COLOR_CYAN "SYMBOL TABLE" ANSI_COLOR_RESET "\n", " ");
		printf("%30s %s\n", " ", "------------");
		printST();

		printf("\n\n%30s" ANSI_COLOR_CYAN "CONSTANT TABLE" ANSI_COLOR_RESET "\n", " ");
		printf("%30s %s\n", " ", "--------------");
		printCT();
		
		// Print semantic analysis report
		printSemanticAnalysisReport();
	}
}

void yyerror(char *s)
{
	printf("%d %s %s\n", yylineno, s, yytext);
	flag=1;
	printf(ANSI_COLOR_RED "Status: Parsing Failed - Invalid\n" ANSI_COLOR_RESET);
}

void ins()
{
	insertSTtype(curid,curtype);
}

void insV()
{
	insertSTvalue(curid,curval);
}

int yywrap()
{
	return 1;
}
