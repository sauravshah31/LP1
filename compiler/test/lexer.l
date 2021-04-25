%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

%}


space       [ \n\f\t\r\v]+        

%%


int             {return K_INTEGER;}
uint            {return K_UINTEGER;}
bool            {return K_BOOLEAN;}
real            {return K_REAL;}


=               {return O_ASSIGN;}
\+=             {return O_ASSIGN_PLUS;}
-=              {return O_ASSIGN_MINUS;}
\*=             {return O_ASSIGN_MUL;}
\/=             {return O_ASSIGN_DIVIDE;}


\+              {return O_PLUS;}
-               {return O_MINUS;}
\*              {return O_MUL;}
\/              {return O_DIVIDE;}
@               {return O_EXP;}


\|             {return O_BOR;}
&              {return O_BAND;}
~              {return O_BNOT;}
\^             {return O_BXOR;}


\|\|           {return O_OR;}
&&             {return O_AND;}
!              {return O_NOT;}


==             {return O_REQ;}
!=             {return O_RNEQ;}
\<             {return O_RLT;}
\<=            {return O_RLEQ;}
\>             {return O_RGTH;}
\>=            {return O_RGEQ;}


uminus         {return O_UMINUS;}




if             {return K_IF;}
else           {return K_ELSE;}
switch         {return K_SWITCH;}
case           {return K_CASE;}
default        {return K_DEFAULT;}


while          {return K_WHILE;}
for            {return K_FOR;}
continue       {return K_CONTINUE;}
break          {return K_BREAK;}




[a-zA-Z][a-zA-Z_]*      {
                            yylval.c = strdup(yytext);
                            return N_ID;
                        }



[1-9][0-9]*\.[0-9]+     {
                            yylval.c = strdup(yytext);
                            return V_REAL;
                        }
[1-9][0-9]*             {
                            yylval.c = strdup(yytext);
                            return V_INTEGER;
                        }

'true'                   {return V_TRUE;}
'false'                  {return V_FLASE;}

{space}                  ;

.                        {return yytext[0];}

%%


int yywrap(){
    return 1;
}