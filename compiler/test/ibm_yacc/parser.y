%{
    #include <stdio.h>

%}

%union{
    typedef struct entry{
        char type;
        double value;
    }entry;
    entry e;
};

%token NUMBER


%type <e> NUMBER

expr: NUM  {printf("%c , %f\n",$<e>1.type, $<e>1.value );}
    ;