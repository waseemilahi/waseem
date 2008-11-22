%{

   /* The parser for the input to the agent. */

# include "myprojectheader1.h"

void combined1error(char*);

int combined1lex();

%}

%token LETTERS OPERATORS ODELIMETER CDELIMETER NOT ABORT SG QG COMMAS

%%

combined:	SG sequence

	|		QG query
	
	;
	
sequence:	sequence comma sentence  					{

														sequence[n][0]=0;
														 
														 strcpy(sequence[n],query);
														 
														 query[0]=0;
														 
														 sequencelanguage[n][0]=0;
														 
														 strcpy(sequencelanguage[n],querylanguage);
														 
														 strcat(sequencelanguage[n],"\0");
														 
														 querylanguage[0]=0;
														 
														 n=n+1;
														 
														}

	|		sentence									{
	
														sequence[n][0]=0;
														 
														 strcpy(sequence[n],query);
														 
														 query[0]=0;
														 
														 sequencelanguage[n][0]=0;
														 
														 strcpy(sequencelanguage[n],querylanguage);
														 
														 strcat(sequencelanguage[n],"\0");
														 
														 querylanguage[0]=0;
														 
														 n=n+1;
														 
														}
														
	|
	
	;

query:		sentence

	|									
	
	;

sentence:	odelim sentence operator sentence cdelim 

	|		psymbol									

	|		nots sentence
		   
	;
	
nots:		NOT
	
odelim:		ODELIMETER

	;
	
comma:		COMMAS

	;
	
cdelim:		CDELIMETER

	;
		
operator:	OPERATORS
	
	;
	
psymbol:	LETTERS

	;
	
aborts:		ABORT										{return 1;}
	
%%