%{  
    #define YYSTYPE int
    #include <stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}

operand             [0-9]+
operator            [+-/*]   
space               [ \t]+
%%
{operand}          {yylval=atoi(yytext); return NUM; }
{operator}          {
                        switch(yytext[0]){
                            case '+':
                                return ADD;
                            case '-':
                                return SUB;
                            case '*':
                                return MUL;
                            case '/':
                                return DIV;
                        }
                    }
{space}             ;
.|\n                ;
%%
