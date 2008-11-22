%%
[ \t]+	; 

[A-Za-z]([A-Za-z]|[0-9])*		{ printf(" Identifier  %s\n",yytext); }

\=		{ printf(" =\n"); }

\+		{ printf(" +\n"); }

\-		{ printf(" -\n"); }

\-\=		{ printf(" -=\n"); }

\+\=		{ printf(" +=\n"); }

;		{ printf(" ;\n"); }


[0]|[1-9][0-9]*		{ printf(" PosInteger  %s\n",yytext); }

[0]|[1-9][0-9]*\.[0]|[1-9][0-9]*	{ printf(" Decimal Number  %s\n",yytext); }

.		{ printf(" Unrecognized Character  %s\n",yytext); }  

%%

int main(){ yylex(); return 0; }
