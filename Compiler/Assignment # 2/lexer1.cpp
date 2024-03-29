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
* lexer1.cpp
* C++ source file generated from lexer1.l.
* 
* Date: 06/06/05
* Time: 21:44:43
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\lexer1.h"

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

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 2 ".\lexer1.l"
;
#line 119 "lexer1.cpp"
		}
		break;
	case 2:
		{
#line 4 ".\lexer1.l"
 printf(" Identifier  %s\n",yytext); 
#line 126 "lexer1.cpp"
		}
		break;
	case 3:
		{
#line 6 ".\lexer1.l"
 printf(" =\n"); 
#line 133 "lexer1.cpp"
		}
		break;
	case 4:
		{
#line 8 ".\lexer1.l"
 printf(" +\n"); 
#line 140 "lexer1.cpp"
		}
		break;
	case 5:
		{
#line 10 ".\lexer1.l"
 printf(" -\n"); 
#line 147 "lexer1.cpp"
		}
		break;
	case 6:
		{
#line 12 ".\lexer1.l"
 printf(" -=\n"); 
#line 154 "lexer1.cpp"
		}
		break;
	case 7:
		{
#line 14 ".\lexer1.l"
 printf(" +=\n"); 
#line 161 "lexer1.cpp"
		}
		break;
	case 8:
		{
#line 16 ".\lexer1.l"
 printf(" ;\n"); 
#line 168 "lexer1.cpp"
		}
		break;
	case 9:
		{
#line 19 ".\lexer1.l"
 printf(" PosInteger  %s\n",yytext); 
#line 175 "lexer1.cpp"
		}
		break;
	case 10:
		{
#line 21 ".\lexer1.l"
 printf(" Decimal Number  %s\n",yytext); 
#line 182 "lexer1.cpp"
		}
		break;
	case 11:
		{
#line 23 ".\lexer1.l"
 printf(" Unrecognized Character  %s\n",yytext); 
#line 189 "lexer1.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 190;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
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
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
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
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
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
	yybackup = backup;
}
#line 25 ".\lexer1.l"


int main(){ yylex(); return 0; }

