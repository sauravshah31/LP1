/*
    convert infix to postfix using expression tree. Use lex
*/
#include <iostream>
#include <string>
#include <stack>

#include <stdlib.h>

#include "tokens.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

typedef struct node{
    union {
        char opr;
        int opd;
    }val;
    struct node *left,*right;
}node;


using namespace std;

struct node* get_node(){
    struct node *temp = new node();
    temp->left = temp->right = NULL;
    return temp;
}

void print_postfix(node *root){
    if(root==NULL)
        return;
    print_postfix(root->left);
    print_postfix(root->right);
    if(root->left)
        cout<<root->val.opr;
    else
        cout<<root->val.opd<<" ";

}

int main(){
    int token;
    struct node *root=NULL;

    stack<char> opr;
    stack<int> prec;
    stack<struct node*> tree;

    while((token=yylex())){

        if(token == NEWLINE){
            while(!opr.empty()){
                node *first,*second;
                second = tree.top();
                tree.pop();
                first = tree.top();
                tree.pop();
                node *temp = get_node();
                temp->val.opr = opr.top();
                temp->left=first;
                temp->right = second;
                tree.push(temp);
                opr.pop();
                prec.pop();
            }
            
            print_postfix(tree.top());
            cout<<endl;
            tree.pop();
            continue;
        }

        if(token == OPERAND){
            struct node *temp = get_node();
            if(yytext[0]!='u')
                temp->val.opd = atoi(yytext);
            else{
                yytext += 2;
                temp->val.opd = atoi(yytext)*-1;
            }

            tree.push(temp); 
        }else if(token == OBRAC){
            opr.push('(');
            prec.push(-1);
        }else if(token == CBRAC){
            char c;
            while(!opr.empty() && ((c=opr.top()) != '(')){
                node *first,*second;
                second = tree.top();
                tree.pop();
                first = tree.top();
                tree.pop();
                node *temp = get_node();
                temp->val.opr = c;
                temp->left = first;
                temp->right = second;
                tree.push(temp);
                opr.pop();
                prec.pop();
            }
            opr.pop();
            prec.pop();
        }else{
            while(!prec.empty() && token<prec.top()){
                node *first,*second;
                second = tree.top();
                tree.pop();
                first = tree.top();
                tree.pop();
                node *temp = get_node();
                temp->val.opr = opr.top();
                temp->left=first;
                temp->right = second;
                tree.push(temp);
                opr.pop();
                prec.pop();
            }
            prec.push(token);
            opr.push(yytext[0]);
        }
    }
}