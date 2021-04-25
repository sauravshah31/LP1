%{
    #define YYSTYPE entry
    #include "parser.tab.h"

    extern entry yylval;
%}

%%
%%

int yywrap(){
    return 1;
}

int main(){
    yyparse();
}

