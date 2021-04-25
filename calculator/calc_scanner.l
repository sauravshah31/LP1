

%{
#include <stdio.h>
#include <string.h>

#include "calc_parser.tab.h"

%}

%option noyywrap
%%

[ \t]+	        ;    
[0-9]+		    {yylval.val = atoi(yytext); return IINT;}
\n		        {return NEWLINE;}
"display"       {return DISP;}
"let"           {return LET;}
"if"            {return IF; }
"else"          {return ELSE; }
"then"          {return THEN; }
"=" 	        {return ASSG;}
"+"		        {return PLUS;}
"-"		        {return MINUS;}
"*"		        {return MULTIPLY;}
"@"		        {return EXP;}	
"/"		        {return DIVIDE;}
"("		        {return LEFT;}
")"		        {return RIGHT;}
"<"		        {return LESS;}
">"		        {return GREATER;}
"=="	        {return EQUAL;}
"!="	        {return NOTEQUAL;}
[a-zA-Z][a-zA-Z0-9]* {strcpy(yylval.cval, yytext); return ID;}
.		        {return -1;}

%%