%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "tokens.h"
    
    char output[100];
    
    void dec_bin(char *inp);
    void hex_bin(char *inp);
    void oct_bin(char *inp);
%}
DEC_NUM         [0-9]+D
BIN_NUM         [0-1]+B
HEX_NUM         [0-9A-F]+H
OCT_NUM         [0-7]+O
REGISTER        [A-Z]
%%
MOV         return MOV;
ADD         return ADD;
SUB         return SUB;
{DEC_NUM}   {yytext[strlen(yytext)-1] = '\0';dec_bin(yytext); yytext = output; return OPERAND;}
{BIN_NUM}   {yytext[strlen(yytext)-1] = '\0'; return OPERAND;}
{HEX_NUM}   {yytext[strlen(yytext)-1] = '\0';hex_bin(yytext); yytext = output; return OPERAND;}
{OCT_NUM}   {yytext[strlen(yytext)-1] = '\0';oct_bin(yytext); yytext = output; return OPERAND;}
{REGISTER}  {return REG;}
,           ;
\n          ;
[ \t]+      ;
%%

void dec_bin(char *inp){
    int num = atoi(inp), r,i=0;
    while(num){
        r = num % 2;
        num /= 2;
        if(r){
            output[i++] = '1';
        }else{
            output[i++] = '0';
        }
    }
    output[i] = '\0';
    i -= 1;
    int j = i;
    i = 0;
    while(i<j){
        char c = output[i];
        output[i] = output[j];
        output[j] = c;
        i++;
        j--;
    }
}

void hex_bin(char *inp){
    int i=0, num, j=0;
    while(inp[j] != '\0'){
        num = (inp[j]>='A'&&inp[j]<='E')?inp[j]-'A'+10:inp[j]-'0';
        if(num & 1<<3)
            output[i++] = '1';
        else
            output[i++] = '0';
        
        if(num & 1<<2)
            output[i++] = '1';
        else
            output[i++] = '0';

        if(num & 1<<1)
            output[i++] = '1';
        else
            output[i++] = '0';

        if(num & 1<<0)
            output[i++] = '1';
        else
            output[i++] = '0';
        j++;
    }
    output[i] = '\0';
}

void oct_bin(char *inp){
    int i=0, num,j=0;
    while(inp[j] != '\0'){
        num = inp[j]-'0';
        
        if(num & 1<<2)
            output[i++] = '1';
        else
            output[i++] = '0';

        if(num & 1<<1)
            output[i++] = '1';
        else
            output[i++] = '0';

        if(num & 1<<0)
            output[i++] = '1';
        else
            output[i++] = '0';
        j++;
    }
    output[i] = '\0';
}

int yywrap(){
    return 1;
}

