%{
  
   /* Lexer1 for the belief revision project. */
   
   # include "combinedinput1.tab.h"
   # include "myprojectheader1.h"
   
   unsigned int i;
   int l=0;
   
%}

letter		[A-EG-SU-Za-z]	

%%

[ \t]+		; /*Ignore Whitespaces.*/

"T"			{ l=0;
	
			  for(i=0;i<strlen(querylanguage);i++)
			      if(yytext[0]==querylanguage[i])
			        l=1;
			        
			  if(l==0)strcat(querylanguage,yytext);
			        
			  strcat(query,yytext);return TRUE;
			 }
			 
"F"			{ l=0;
	
			  for(i=0;i<strlen(querylanguage);i++)
			      if(yytext[0]==querylanguage[i])
			        l=1;
			        
			  if(l==0)strcat(querylanguage,yytext);
			        
			  strcat(query,yytext);return FALSE;
			 }

{letter}	{ l=0;
	
			  for(i=0;i<strlen(querylanguage);i++)
			      if(yytext[0]==querylanguage[i])
			        l=1;
			        
			  if(l==0)strcat(querylanguage,yytext);
			        
			  strcat(query,yytext);return LETTERS;
			  
			}

"~"			{ strcat(query,yytext);return NOT;}

"|"			{ strcat(query,yytext);return OPERATORS;}

"&"			{ strcat(query,yytext);return OPERATORS;}

"->"		{ strcat(query,yytext);return OPERATORS;}

"<=>"		{ strcat(query,yytext);return OPERATORS;}

"("			{ strcat(query,yytext);return ODELIMETER;}

")"			{ strcat(query,yytext);return CDELIMETER;}

","			{ return COMMAS;}

"Sequence"	{ return SG;}

"Query"		{ return QG;}

\n			; /* Ignore newline. */

"$"			{yyterminate();return 0; /*End of input.*/} 

.			{printf("\n Wrong Input. Please Try Again.\n");return ABORT;}

%%