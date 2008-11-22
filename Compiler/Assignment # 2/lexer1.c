/****************************************************************************
*                         A C A D E M I C   C O P Y
* 
* This file was produced by an ACADEMIC COPY of Parser Generator. It is for
* use in non-commercial software only. An ACADEMIC COPY of Parser Generator
* can only be used by a student, or a member of an academic community. If
* however you want to use Parser Generator for commercial purposes then you
* will need to purchase a license. For more information see the online help or
* go to the Bumble-Bee Software homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* lexer1.c
* C source file generated from lexer1.l.
* 
* Date: 06/05/05
* Time: 16:23:04
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#ifndef INITIAL
#define INITIAL 0
#endif

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 2 ".\\lexer1.l"
;
#line 161 "lexer1.c"
		}
		break;
	case 2:
		{
#line 4 ".\\lexer1.l"
 printf(" Identifier  %s\n",yytext); 
#line 168 "lexer1.c"
		}
		break;
	case 3:
		{
#line 6 ".\\lexer1.l"
 printf(" =\n"); 
#line 175 "lexer1.c"
		}
		break;
	case 4:
		{
#line 8 ".\\lexer1.l"
 printf(" +\n"); 
#line 182 "lexer1.c"
		}
		break;
	case 5:
		{
#line 10 ".\\lexer1.l"
 printf(" -\n"); 
#line 189 "lexer1.c"
		}
		break;
	case 6:
		{
#line 12 ".\\lexer1.l"
 printf(" -=\n"); 
#line 196 "lexer1.c"
		}
		break;
	case 7:
		{
#line 14 ".\\lexer1.l"
 printf(" +=\n"); 
#line 203 "lexer1.c"
		}
		break;
	case 8:
		{
#line 16 ".\\lexer1.l"
 printf(" ;\n"); 
#line 210 "lexer1.c"
		}
		break;
	case 9:
		{
#line 19 ".\\lexer1.l"
 printf(" PosInteger  %s\n",yytext); 
#line 217 "lexer1.c"
		}
		break;
	case 10:
		{
#line 21 ".\\lexer1.l"
 printf(" Decimal Number  %s\n",yytext); 
#line 224 "lexer1.c"
		}
		break;
	case 11:
		{
#line 23 ".\\lexer1.l"
 printf(" Unrecognized Character  %s\n",yytext); 
#line 231 "lexer1.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 190;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 4, 1 },
	{ 0, 1 },
	{ 4, 4 },
	{ 14, 8 },
	{ 12, 5 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 8, 8 },
	{ 13, 6 },
	{ 15, 14 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 4, 1 },
	{ 0, 0 },
	{ 4, 4 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 5, 1 },
	{ 0, 0 },
	{ 6, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 7, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 8, 1 },
	{ 0, 0 },
	{ 9, 1 },
	{ 0, 0 },
	{ 10, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 1 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 },
	{ 11, 11 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ -3, -8, 0 },
	{ 1, 0, 0 },
	{ 0, 0, 11 },
	{ 0, -6, 1 },
	{ 0, -56, 4 },
	{ 0, -45, 5 },
	{ 0, 0, 9 },
	{ 0, -42, 9 },
	{ 0, 0, 8 },
	{ 0, 0, 3 },
	{ 0, 67, 2 },
	{ 0, 0, 7 },
	{ 0, 0, 6 },
	{ 0, -31, 0 },
	{ 0, 0, 10 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 25 ".\\lexer1.l"


int main(){ yylex(); return 0; }

