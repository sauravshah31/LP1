%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
%}

%union{
    char *c;
    int i;
}



%token <i> K_INTEGER K_UINTEGER K_BOOLEAN K_REAL K_IF K_ELSE K_SWITCH K_CASE K_DEFAULT K_WHILE K_FOR K_CONTINUE K_BREAK
%token <i> O_ASSIGN O_ASSIGN_PLUS O_ASSIGN_MINUS O_ASSIGN_MUL O_ASSIGN_DIVIDE O_PLUS O_MINUS O_MUL O_DIVIDE O_EXP O_BOR O_BAND O_BNOT O_BXOR O_REQ O_RNEQ O_RLT O_RLEQ O_RGTH O_RGEQ O_UMINUS O_AND O_OR O_NOT
%token <c> N_ID
%token <c> V_TRUE V_FLASE V_INTEGER V_REAL

%%
P           :   %empty
            |   '{' G '}' {printf("G\n");}
            ;
G           :   declaration
            |   block
            ;
declaration :   assignment
            ;
assignment  :   K_INTEGER N_ID '=' V_INTEGER
                {
                    printf("%s = %s",$2,$4);
                }   
            |   K_REAL N_ID '=' V_REAL
                {
                    printf("%s = %s",$2,$4);
                }   
            |
                K_BOOLEAN N_ID '=' V_TRUE
                {
                    printf("%s = %s",$2,$4);
                }   
            |   K_BOOLEAN N_ID '=' V_FLASE
                {
                    printf("%s = %s",$2,$4);
                }   
            ;
block       :%empty   
            ;
            
%%

int yyerror(char *msg){
    fprintf(stderr,"%s\n",msg);
    return -1;
}
int main(void){
    yyparse();
}