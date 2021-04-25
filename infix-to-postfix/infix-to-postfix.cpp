#include <iostream>
#include <stack>
#include <string>

#include "tokens.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


using namespace std;

int main(){
    int token;

    stack<char> opr;
    stack<int> prec;
    string postfix_expr = "";
    while((token=yylex())){
        if(token == NEWLINE){
            while(!opr.empty()){
                postfix_expr += opr.top();
                opr.pop();
                prec.pop();
            }
            cout<<postfix_expr<<endl;
            postfix_expr.clear();
            continue;
        }

        if(token == OPERAND){
            postfix_expr += yytext;
            postfix_expr += " ";
        }else if(token == OBRAC){
            opr.push('(');
            prec.push(-1);
        }else if(token == CBRAC){
            char c;
            while(!opr.empty() && ((c=opr.top()) != '(')){
                postfix_expr += c;
                opr.pop();
                prec.pop();
            }
            opr.pop();
            prec.pop();
        }else{
            while(!prec.empty() && token<prec.top()){
                postfix_expr += opr.top();
                opr.pop();
                prec.pop();
            }
            prec.push(token);
            opr.push(yytext[0]);
        }
    }
}