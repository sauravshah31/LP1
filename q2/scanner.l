%{
    #include <regex.h>
    #include <string.h>
    #include <stdio.h>

    char *file_regex[100];
    int total = 0;

    void check_regex(char *inp);
    void store_regex(char *file_path);

%}

%%
.*          {check_regex(yytext);}
\n          ;    
%%

int yywrap(){
    return 1;
}

void check_regex(char *inp){
    for(int i=0; i<total; i++){
        regex_t chk;
        regcomp(&chk, file_regex[i], 1);
        if(regcomp(&chk, inp,0) == 0){
            printf("matched : %s",file_regex[i]);
        }
    }
}

void store_regex(char *file_path){
    char re[100];
    FILE *fp = fopen(file_path, "r");

    while(fgets(re, 100, fp)!=NULL){
        strcpy(file_regex[total++], re);
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Invalid argument\n");
        printf("Usage: ./a.out  input.txt");
        return -1;
    }

    store_regex(argv[1]);
    yylex();

    return 0;
}