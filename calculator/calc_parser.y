%{
	#include<iostream>
	#include<string>
	#include <map>
	using namespace std;

	extern int yylex();
	extern int yyparse();
	map<string, int> vars;

	void yyerror(const char* s);
%}

%union {
	int val;
	char var[100];
}


%right EXP
%token<val> NUM
%token PLUS MINUS MULTIPLY DIVIDE LEFT RIGHT
%token NEWLINE QUIT DISP ASSG LET IF THEN ELSE EQUAL NOTEQUAL LESS GREATER
%left EQUAL NOTEQUAL LESS GREATER
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left ID

%type<val> expression iff els
%type<var> ID

%start calculation

%%

calculation: 
			| calculation line
			;

line: NEWLINE
	|	expression {printf("%d\n",$1);}
	| DISP expression NEWLINE { cout<<$2<<endl; }
	| LET ID ASSG expression { vars[$2] = $4; }
	| iff {cout<<$1<<endl;}
	;

iff: els ELSE iff {if($1 != INT_MIN){ $$ = $1; } else {$$ = $3;}}
	| els ELSE expression {if($1 != INT_MIN){ $$ = $1; } else {$$ = $3;}}
	| els {if($1 != INT_MIN){ $$ = $1; } else { }}


els: IF expression THEN expression { if($2 > 0) {$$ = $4;} else { $$ = INT_MIN; }}

expression: NUM	{ $$ = $1; }
	  | ID 			{ if(vars.find($1)!=vars.end()) {$$ = vars[$1];} else yyerror($1); }
	  | expression PLUS expression	{ $$ = $1 + $3; }
	  | expression MINUS expression	{ $$ = $1 - $3; }
	  | expression MULTIPLY expression	{ $$ = $1 * $3; }
	  | expression DIVIDE expression {$$ = $1 / $3; }
	  | expression LESS expression {$$ = $1 < $3; }
	  | expression GREATER expression {$$ = $1 > $3; }
	  | expression EQUAL expression {$$ = $1 == $3; }
	  | expression NOTEQUAL expression {$$ = $1 != $3; }
	  | LEFT expression RIGHT		{ $$ = $2; }
	  ;

%%

int main() {
	yyparse();

	return 0;
}

void yyerror(const char *s){
	printf("error\n");
}