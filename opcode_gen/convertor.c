#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokens.h"

extern int yylex();
extern char* yytext;

char output[100];
int _i;

void add(char *a, char *b){
    output[99] = '\0';
    _i = 98;
    int i = strlen(a)-1;
    int j = strlen(b)-1;
    int c=0;
    while (i>=0 && j>=0)
    {
        int s = (a[i]-'0') + (b[j]-'0') + c;
        c = 0;
        if(s == 2){
            s = 0;
            c = 1;
        }else if(s==3){
            s = 1;
            c = 1;
        }
        output[_i--] = s+'0';
        i--;j--;
    }

    while (i>=0)
    {
        int s = (a[i]-'0') + c;
        c = 0;
        if(s == 2){
            s = 0;
            c = 1;
        }else if(s==3){
            s = 1;
            c = 1;
        }
        output[_i--] = s+'0';
        i--;
    }
    while (j>=0)
    {
        int s = (b[j]-'0') + c;
        c = 0;
        if(s == 2){
            s = 0;
            c = 1;
        }else if(s==3){
            s = 1;
            c = 1;
        }
        output[_i--] = s+'0';
        j--;
    }
    if(c){
        output[_i--] = '1';
    }
    _i += 1;
}

void sub(char *a, char *b){
    char *tmp = malloc(100);
    int i=0;
    while(b[i]!='\0'){
        tmp[i] = (b[i]=='0'?'1':'0');
        i+=1;
    }
    add(tmp,"1");
    strcpy(tmp,output+_i);
    add(a,tmp);
    free(tmp);
    if((99-_i) >strlen(tmp))
        _i += 1;
    while(output[_i] == '0')
        _i += 1;
}



int main(){
    char* registers[26];
    for(int i=0;i<26;i++){
        registers[i] = (char *)malloc(100);
    }

    int tok;
    while((tok=yylex())){
        if(tok == MOV){
            tok = yylex();
            if(tok!=REG){
                fprintf(stderr,"error\n");
                return -1;
            }
            int r = yytext[0]-'A';
            tok = yylex();
            
            if(tok == REG){
                strcpy(registers[r],registers[yytext[0]-'A']);
            }else if(tok == OPERAND){
                strcpy(registers[r],yytext);
            }else{
                fprintf(stderr,"error\n");
                return -1;
            }

            printf("1101 %s\n",registers[r]);

        }else if(tok == ADD){
            tok = yylex();
            if(tok!=REG){
                fprintf(stderr,"error\n");
                return -1;
            }
            int r = yytext[0]-'A';
            tok = yylex();
            if(tok == REG){
                add(registers[r], registers[yytext[0]-'A']);
                printf("0100 %s\n",registers[yytext[0]-'A']);
            }else if(tok == OPERAND){
                add(registers[r], yytext);
                printf("0100 %s\n",yytext);
            }else{
                fprintf(stderr,"error\n");
                return -1;
            }
            strcpy(registers[r],output+_i);

            
        }else if(tok == SUB){
            tok = yylex();
            if(tok!=REG){
                fprintf(stderr,"error\n");
                return -1;
            }
            int r = yytext[0]-'A';
            tok = yylex();
            if(tok == REG){
                sub(registers[r], registers[yytext[0]-'A']);
                printf("0011 %s\n",registers[yytext[0]-'A']);
            }else if(tok == OPERAND){
                sub(registers[r], yytext);
                printf("0011 %s\n",yytext);
            }else{
                fprintf(stderr,"error\n");
                return -1;
            }
            strcpy(registers[r],output+_i);

        }else{
            fprintf(stderr,"error\n");
            return -1;
        }
    }
    return 0;
}