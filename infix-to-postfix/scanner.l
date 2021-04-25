%{
    #include "tokens.h"
%}
%%
"um"?[0-9]+         return OPERAND;
\+                  return ADD;
-                   return SUB;
\*                  return MUL;
\/                  return DIV;
@                   return EXP;
\(                  return OBRAC;
\)                  return CBRAC;
[ ]                 ;
\n                  return NEWLINE;
.                   printf("invalid expression\n");
%%
int yywrap(void){
    return 1;
}