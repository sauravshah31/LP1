
%{
    #include <stdlib.h>

    #include "parser.tab.h"

    char *temp;
%}

%%
"um"?[0-9]+("."?[0-9]+)|([0-9]*)    {yylval.val = strtod(yytext,&temp); return NUM;}
"sin"                               {return SIN;}
"cos"                               {return COS;}
"tan"                               {return TAN;}
"="                                 {return ASSIGN;}
"+"                                 {return ADD;}
"-"                                 {return SUB;}
"*"                                 {return MUL;}
"/"                                 {return DIV;}
"@"                                 {return EXP;}
"if"                                {return IF;}
"then"                              {return THEN;}
"else"                              {return ELSE;}
"=="                                {return EQ;}
"!="                                {return NEQ;}
">="                                {return GEQ;}
"<="                                {return LEQ;}
">"                                 {return GT;}
"<"                                 {return LT;}
"("                                 {return OBRC;}
")"                                 {return CBRC;}
"let"                               {return LET;}
"display"                           {return DISPLAY;}
[a-z]                               {yylval.val=yytext[0]-'a'; return ID;}
[\n]+                               {return NEWLINE;}
[ \t]+                              ;
.                                   {return -1;}                    
%%