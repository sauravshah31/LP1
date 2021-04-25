%{
    #include <stdio.h>
    #include <math.h>
    
    void rotate(char *inp, int n, int k);
    void replace_ascii(char *inp, int n, int k);
    void reverse(char *inp, int n);
    void swap_lr(char *inp, int n);

%}

sepcial_word            special1|special2|special3
word                    [a-zA-Z]+
number                  [0-9]+
white_space             [ \t]+

%%
{sepcial_word}      {rotate(yytext, yyleng, 2); reverse(yytext,yyleng);printf("%s",yytext);}
{word}              {replace_ascii(yytext, yyleng, 3); reverse(yytext, yyleng);printf("%s",yytext);}
{number}            {swap_lr(yytext, yyleng);printf("%s",yytext);}
{white_space}       {printf(" ");}
.|\n                {printf("%s",yytext);}
%%


void rotate(char *inp, int n, int k){
    char temp[n];
    int i;

    for(i=k;i<n;i++)
        temp[i-k] = inp[i];
    for(i=0;i<k;i++)
        temp[n-k+i] = inp[i];
    
    for(i=0;i<n;i++){
        inp[i] = temp[i];
    }
}

void replace_ascii(char *inp, int n, int k){
    int i;
    for(i=0;i<n;i++){
        inp[i] = (char)(inp[i]+k)%128;
    }
}

void reverse(char *inp, int n){
    int i;
    i = 0;
    n--;
    while(i<n){
        char c = inp[i];
        inp[i++] = inp[n];
        inp[n--] = c;
    }
}

void swap_lr(char *inp, int n){
    int j = ceil(n/2.0);
    int i = 0;
    while(j<n){
        char c = inp[i];
        inp[i++] = inp[j];
        inp[j++] = c;
    }

}

int main(void){
    yylex();
    return 0;
}