%{
    #include <stdio.h>
    #include <math.h>
    
    double result=0.0;
    double assigned_var[26];
%}

%union {
    double val;
    int flag;
}
%start  G
%token  LET DISPLAY
%token  NEWLINE NUM IF THEN ELSE OBRC CBRC SIN COS TAN ASSIGN EQ NEQ GEQ LEQ GT LT
%right  EXP
%left   MUL DIV
%left   ADD SUB
%left   ID

%%
G:          /*empty */
        | G stmt NEWLINE
        | G error NEWLINE
        ;

stmt:   expr
            {printf("%f\n",$1);}
        |
        LET ID  ASSIGN  expr    
            {assigned_var[$2] = $4;}
        |
        DISPLAY expr NEWLINE    
            {printf("%s = %f\n",$2,assigned_var[$2]);}
        |
        conditional_stmt  
            {printf("result = %f\n",$$);}
        ; 
        
conditional_stmt:   IF OBRC expr CBRC THEN expr ELSE conditional_stmt
                        {
                            if((int)$3 !=0){
                                $$ = $6;
                            }else{
                                $$ = $8;
                            }
                        }
                    |
                    IF OBRC expr CBRC THEN expr ELSE expr
                        {
                            if((int)$3 !=0){
                                $$ = $6;
                            }else{
                                $$ = $8;
                            }
                        }
                    |
                    IF OBRC expr CBRC THEN expr 
                        {
                            if((int)$3 !=0){
                                $$ = $6;
                            }
                        }
                    ;

expr:   NUM             {$$ = $1;}
        |
        ID              {$$ = assigned_var[$1];}
        |
        SIN OBRC expr CBRC   {$$ = sin($3);}
        |
        COS OBRC expr CBRC     {$$ = cos($3);}
        |
        TAN OBRC expr CBRC     {$$ = tan($3);}
        |
        expr ADD expr   {$$ = $1 + $3;}
        |
        expr SUB expr   {$$ = $1 - $3;}
        |
        expr DIV expr   {$$ = $1 / $3;}
        |
        expr MUL expr   {$$ = $1 * $3;}
        |
        expr EQ expr   {$$ = ($1 == $3);}
        |
        expr NEQ expr   {$$ = ($1 != $3);}
        |
        expr GEQ expr   {$$ = ($1 >= $3);}
        |
        expr LEQ expr   {$$ = ($1 <= $3);}
        |
        expr LT expr   {$$ = ($1 < $3);}
        |
        expr GT expr   {$$ = ($1 > $3);}
        
        ;

%%
int main(){
    yyin = stdin;
    yyparse();
    return 0;
}


void yyerror(const char *s){
	printf( "error : %s\n",s);
}

int yywrap()
{
    return(1);
}