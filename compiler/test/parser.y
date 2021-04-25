%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    extern int yylex();
    int yyerror(char *msg);
    extern int yylineno;
%}

%union{
    char *c;
    int i;
}



%token <i> K_INTEGER K_UINTEGER K_BOOLEAN K_REAL K_IF K_ELSE K_SWITCH K_CASE K_DEFAULT K_WHILE K_FOR K_CONTINUE K_BREAK
%token <i> O_ASSIGN O_ASSIGN_PLUS O_ASSIGN_MINUS O_ASSIGN_MUL O_ASSIGN_DIVIDE O_PLUS O_MINUS O_MUL O_DIVIDE O_EXP O_BOR O_BAND O_BNOT O_BXOR O_REQ O_RNEQ O_RLT O_RLEQ O_RGTH O_RGEQ O_UMINUS O_AND O_OR O_NOT O_REL
%token <c> N_ID
%token <c> V_TRUE V_FLASE V_INTEGER V_REAL

%%
P           :   %empty
            |   block
            ;
block       : '{' marker_block code '}'
marker_block    :  %empty
            ;
code        :   %empty
            |   declaration code
            |   assignment code
            |   conditional code
            |   repetitive code
            ;
declaration :   declaration_int
            |   declaration_real
            |   declaration_bool
            ;
declaration_int :   K_INTEGER N_ID ';'
                ;
declaration_real:   K_REAL N_ID ';'
                ;
declaration_bool:   K_BOOLEAN N_ID ';'
                ;
assignment  :   inititalization
            |   value_change
            ;
inititalization :   inititalization_int
                |   inititalization_real
                |   inititalization_bool
                ;
inititalization_int     :   K_INTEGER N_ID '=' expr ';'
                        |   K_UINTEGER N_ID '=' expr ';'  
                        ;
inititalization_real    :   K_REAL N_ID '=' expr ';'
                        ;
inititalization_bool    :   K_BOOLEAN N_ID '=' expr ';'
                        ;
value_change    :   N_ID O_ASSIGN expr ';'
                |   N_ID O_ASSIGN_PLUS expr ';'
                |   N_ID O_ASSIGN_MINUS expr ';'
                |   N_ID O_ASSIGN_MUL expr ';'   
                |   N_ID O_ASSIGN_DIVIDE expr ';'
                ;

conditional :   conditional_if
            |   conditional_switch
            ;
conditional_if  :   conditional_if_compound
                |   conditional_if_simple
                ;
conditional_if_simple   :   K_IF '(' expr ')' block
                        ;
conditional_if_compound   :  conditional_if_simple K_ELSE '(' expr ')' block
                        ;

conditional_switch  : K_SWITCH '(' expr ')' block_switch
                    ;
block_switch        :  K_CASE expr ':' block block_switch
                    |  K_CASE expr ':' block
                    |  K_DEFAULT ':' block
                    ;
repetitive  :   repetitive_for
            |   repetitive_while
            ;
repetitive_for  :   K_FOR
                ;
repetitive_while:   K_WHILE '(' expr ')' block 
                ;


expr    :   expr_boolean
        |   expr_arithmetic
        ;

expr_boolean    :   expr_boolean_or
                |   expr_boolean_or O_REL expr_boolean_or
                ;
expr_boolean_or :   expr_boolean_and
                |   expr_boolean_or O_OR expr_boolean_and
                ;
expr_boolean_and:   expr_boolean_bor
                |   expr_boolean_and O_AND expr_boolean_bor
                ;
expr_boolean_bor:   expr_boolean_band
                |   expr_boolean_bor O_BOR  expr_boolean_band
                ;
expr_boolean_band:  expr_boolean_bxor
                 |  expr_boolean_band O_BAND expr_boolean_bxor   
                 ;
expr_boolean_bxor   :  expr_boolean_not
                    |  expr_boolean_bxor O_BXOR expr_boolean_not 
expr_boolean_not :  expr_boolean_bnot
                 |  O_NOT expr_boolean_not
                 ;
expr_boolean_bnot:  '(' expr_boolean ')'
                 |  value
                 |  O_BNOT expr_boolean_bnot
                 ;

expr_arithmetic :   expr_arithmetic_plus
                ;
expr_arithmetic_plus    :   expr_arithmetic_minus
                        |   expr_arithmetic_plus O_PLUS expr_arithmetic_minus
                        ;
expr_arithmetic_minus   :   expr_arithmetic_mul
                        |   expr_arithmetic_minus O_MINUS expr_arithmetic_mul
                        ;

expr_arithmetic_mul     :   expr_arithmetic_div
                        |   expr_arithmetic_mul O_MUL expr_arithmetic_div
                        ;   
expr_arithmetic_div     :   expr_arithmetic_pow
                        |   expr_arithmetic_div O_DIVIDE expr_arithmetic_pow
                        ; 
expr_arithmetic_pow     :   expr_arithmetic_uminus
                        |   expr_arithmetic_pow O_EXP expr_arithmetic_uminus
                        ; 
expr_arithmetic_uminus  :   %empty
;

value           :   value_term
                |   O_UMINUS value
                ;
value_term      :   V_TRUE
                |   V_FLASE
                |   V_REAL
                |   V_INTEGER
                ;
%%

int yyerror(char *msg){
    fprintf(stderr,"%s\n",msg);
    return -1;
}
int main(void){
    FILE *f = fopen("./input.l","r");
    size_t len = 0;
    char *line=NULL;
    while (getline(&line, &len, f) > 0) {
        printf("%s",line);
    }
    fclose(f);
}