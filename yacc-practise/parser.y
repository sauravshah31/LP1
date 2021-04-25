
%{
    #include <stdio.h>
%}
%start addexpr
%token NUM
%left MUL DIV
%left ADD SUB
%%
addexpr :mulexpr 
        |
        addexpr ADD mulexpr 
            {$$ = $1+$3;  printf("%d + %d = %d\n",$1,$3,$$);}
        |
        addexpr SUB mulexpr 
            {$$ = $1-$3;  printf("%d - %d = %d\n",$1,$3,$$);}
        ;
mulexpr :primary
        |
        mulexpr MUL primary
            {$$ = $1*$3;  printf("%d * %d = %d\n",$1,$3,$$);}
        |
        mulexpr DIV primary 
            {$$ = $1/$3;  printf("%d / %d = %d\n",$1,$3,$$);}
        ;
primary :NUM 
            {$$ = $1;}
        ;

%%
main(){
    return (yyparse());
}

yyerror(s)
char *s;
{
    fprintf(stderr,"%s\n",s);
}

yywrap()
{
    return(1);
}