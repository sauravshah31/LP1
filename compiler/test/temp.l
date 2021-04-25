%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

    extern YYSTYPE yylval;
%}

%%

#Comment 0:Basics
int             {return K_INTEGER;}
uint            {return K_UINTEGER;}
bool            {return K_BOOLEAN;}
real            {return K_REAL;}

#Comment 2:Assignment Operators
=               {return O_ASSIGN;}
\+=              {return O_ASSIGN_PLUS;}
-=              {return O_ASSIGN_MINUS;}
\*=              {return O_ASSIGN_MUL;}
\/=              {return O_ASSIGN_DIVIDE;}

#Comment 3:Binary Operator
\+               {return O_PLUS;}
-               {return O_MINUS;}
\*               {return O_MUL;}
\/               {return O_DIVIDE;}
@               {return O_EXP;}

#Comment 4:Bitwise Operator
\|              {return O_BOR;}
&              {return O_BAND;}
~              {return O_BNOT;}
\^              {return O_BXOR;}

Comment 5:Logical Operator
\|\|             {return O_OR;}
&&             {return O_AND;}

Comment 6:Relational Operator
==             {return O_REQ;}
!=             {return O_RNEQ;}
\<              {return O_RLT;}
\<=             {return O_RLEQ;}
\>              {return O_RGTH;}
\>=             {return O_RGEQ;}

Comment 7:other operator
uminus         {return O_UMINUS;}


Comment 8:Control Structure
Comment 9:conditional
if             {return K_IF;}
else           {return K_ELSE;}
switch         {return K_SWITCH;}
case           {return K_CASE;}
default        {return K_DEFAULT;}

Comment 10:repetitive
while          {return K_WHILE;}
for            {return K_FOR;}
continue       {return K_CONTINUE;}
break          {return K_BREAK;}



Comment 11:Identifiers Names(N)
[a-zA-Z][a-zA-Z_]*      {
                            yylval = strdup(yytext);
                            return N_ID;
                        }


Comment 12:values (V)
[1-9][0-9]*\.[0-9]+     {
                            yylval = strdup(yytext);
                            return V_REAL;
                        }
[1-9][0-9]*             {
                            yylval = strdup(yytext);
                            return V_INTEGER;
                        }

true                   {return V_TRUE;}
false                  {return V_FLASE;}

%%


int yywrap(){
    return 1;
}