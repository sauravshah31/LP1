/*
187157
Saurav Shah


Implement CYK algorithm for deciding membership of a string in CFG in CNF. Assume that
terminals and non-terminals are represented by a single alphabet and each grammar rule is
given as a string where the first symbol is left side and the remaining portion is the
corresponding right side of the production. Modify it to produce the number of non-identical
derivation sequences for a given string in the grammar. Also generate the distinct derivation
sequences, if possible.

Usage:
    g++ file_name.cpp
    ./a.out

Example Input:
4
S
2 AB BB
0
A
2 CC AB 
1 a
B
2 BB CA
1 b
C
2 BA AA
1 b
aab
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include <unordered_set>


using namespace std;

typedef struct non_terminal{
    pair<char,char> value;
    non_terminal();
    non_terminal(char first,char second){
        this->value = make_pair(first,second);
    } 
}non_terminal;

typedef struct terminal{
    char value;
    terminal();
    terminal(char c):value(c){}
}terminal;

typedef struct production{
    char left_symbol;
    vector<non_terminal> non_terminals;
    vector<terminal> terminals;
}production;

typedef struct grammar{
    vector<production> rules;
}grammar;


void search_start(grammar *G,terminal t, vector<production *> &ps);
void search_start(grammar *G, non_terminal t, vector<production *> &ps);
void search_start(grammar *G,unordered_set<production *> &p1,unordered_set<production *> &p2, vector<production *> &ps);

bool check_membership(grammar *G, string w);
void input(grammar *G);

ostream& operator <<(ostream& stream,const grammar &G);


int main(){
    grammar *G = new grammar();
    input(G);
    while(1){
        string w;
        cout<<"Enter input word : ";
        cin>>w;
        cout<<"word : "<<w<<endl;
        cout<<boolalpha<<check_membership(G, w)<<endl;
        break;
    }
}


void input(grammar *G){
    
    assert(G!=NULL);

    int nrules;
    cout<<"Enter no of rules : ";
    cin>>nrules;

    G->rules.reserve(nrules);

    for(int i=0; i<nrules; i++){
        production curr_rule;
        int nnterm,nterm;
        string nt;
        char term;

        cout<<"Enter left symbol : ";
        cin>>curr_rule.left_symbol;

        cout<<"Enter no of non terminals : ";
        cin>>nnterm;
        curr_rule.non_terminals.reserve(nnterm);
        cout<<"Enter Non terminals\n";
        while (nnterm--)
        {
            cin>>nt;
            curr_rule.non_terminals.push_back(non_terminal(nt[0],nt[1]));
        }

        cout<<"Enter no of terminals : ";
        cin>>nterm;
        curr_rule.terminals.reserve(nterm);
        cout<<"Enter terminals\n";
        while(nterm--)
        {
            cin>>term;
            curr_rule.terminals.push_back(terminal(term));
        }
        G->rules.push_back(curr_rule);
    }    
    
    cout<<endl;
    cout<<"input:"<<endl;
    cout<<*G;
}

bool check_membership(grammar *G, string w){
    const int n = w.size();
    int counter;
    vector<vector<unordered_set<production *>>> table;

    table.reserve(n);

    table.push_back(vector<unordered_set<production *>>());
    table[0].reserve(n);

    counter = 0;
    for(char c:w){
        table[0].push_back(unordered_set<production *>());
        vector<production *> ps;
        search_start(G,terminal(c),ps);

        for(production* p:ps){
            table[0][counter].insert(p);
        }
        counter++;
    }
    for(int i=1;i<n;i++){
        table.push_back(vector<unordered_set<production *>>());
        table[i].reserve(n-i);

        for(int j=0;j<n-i;j++){
            table[i].push_back(unordered_set<production *>());
            vector<production *> ps;
            counter = 1;
            for(int split = j+1;split<=(j+i+1-1);split++){
                search_start(G,table[counter-1][j],table[(i+1-counter-1)][split],ps);
                counter++;
            }
            cout<<endl;
            for(production* p:ps){
                table[i][j].insert(p);
            }
        }
    }
    bool result=false;
    char start_symbol = G->rules[0].left_symbol;
    for(production * p:table[table.size()-1][0]){
        if(p->left_symbol == start_symbol)
            result = true;
    }

    printf("CYK ALGORITHM TABLE\n");
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<table[i].size();j++){
            cout<<"{ ";
            for(production *p : table[i][j]){
                cout<<p->left_symbol<<" ";
            }
            cout<<"} ";
        }
        cout<<endl;
    }
    return result;
}

void search_start(grammar *G,terminal t, vector<production *> &ps){
    for(production &p : G->rules){
        for(terminal &tc:p.terminals){
            if(tc.value == t.value){
                ps.push_back(&p);
                break;
            }
        }
    }
}


void search_start(grammar *G, non_terminal t, vector<production *> &ps){
    for(production &p : G->rules){
        for(non_terminal &tc:p.non_terminals){
            if(tc.value.first == t.value.first && tc.value.second==t.value.second){
                ps.push_back(&p);
                break;
            }
        }
    }
}


void search_start(grammar *G,unordered_set<production *> &p1,unordered_set<production *> &p2, vector<production *> &ps){
    for(production* a:p1){
        for(production* b:p2){
            search_start(G, non_terminal(a->left_symbol,b->left_symbol),ps);
        }
    }
}



ostream& operator <<(ostream& stream,const grammar &G){
    for(int i=0;i<G.rules.size();i++){
        cout<<G.rules[i].left_symbol <<" -> ";
        for(int j=0;j<G.rules[i].non_terminals.size();j++){
            cout<<G.rules[i].non_terminals[j].value.first<<G.rules[i].non_terminals[j].value.second<<" ";
        }

        for(int j=0;j<G.rules[i].terminals.size();j++){
            cout<<G.rules[i].terminals[j].value<<" ";
        }
        cout<<endl;
    }
    return stream;
}