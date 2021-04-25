/*
    Simplify CFG 
    Consider  a  CFG  with  each  terminal  and  non-terminal  represented  as  single  alphabet  and each production is represented as a  string with left most symbol as left side  variable of the production.  Write  a  program  to  eliminate  useless  symbols,  €  -  productions  and  unit productions. From the resultant grammar remove immediate left recursion. Display the input and output grammars in a readable notation
   
   Input Format
   Start_Synbol[A-Z] prod1 prod2 prod3 ...
   $ => denotes epsilon  
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

#define EPSILON '$' 

typedef struct production{
    char start_symbol;
    vector<string> derivation;
}prodution;

typedef struct grammar{
    unordered_map<char,int> index;
    vector<production> rules; 
}grammer;


void take_input(grammar *G);
grammar* remove_useless_production(grammar *G, int del);
grammar * remove_eplison_production(grammar *G, int del);
void remove_unit_production(grammar *G);
void remove_immediate_left_recursion(grammar *G);
ostream& operator <<(ostream& stream,const grammar &G);

int main(){
    grammar *CFG = new grammar();
    take_input(CFG);
    cout<<"INPUT-----\n";
    cout<<*CFG;
    cout<<endl;

    CFG = remove_eplison_production(CFG,1);
    cout<<"EPSILON PROD REMOVED-----\n";
    cout<<*CFG;
    cout<<endl;

    remove_unit_production(CFG);
    cout<<"UNIT PROD REMOVED-----\n";
    cout<<*CFG;
    cout<<endl;

    CFG = remove_useless_production(CFG,1);
    cout<<"USELESS PROD REMOVED-----\n";
    cout<<*CFG;
    cout<<endl;

    remove_immediate_left_recursion(CFG);

    cout<<"IMMEDIATE LEFT RECURSION REMOVED-----\n";
    cout<<*CFG;
    cout<<endl;

    (void) getchar();
}

void take_input(grammar *G){
    int nprod;
    string raw_inp;

    cout<<"Enter no of productions : ";
    cin>>nprod;
    G->rules.reserve(nprod);
    
    auto split = [](const string &inp,const char delimiter,const bool ignore_space=true) {
        vector<string> res;
        string curr = "";
        for(char c:inp){
            if(c==delimiter){
                if(curr!="")
                    res.push_back(curr);
                    curr = "";
            }else if(c==' '|| c=='\t' || c=='\n');
            else
                curr += c;
        }
        if(curr!="")
            res.push_back(curr);
        return res;
    };

    cout<<"Enter productions S aSb | aS | $"<<endl;
    (void)getchar();
    for(int i=0; i<nprod; i++){
        getline(cin, raw_inp);
        vector<string> res = split(raw_inp,' ');
        G->rules.push_back(production());
        G->rules[i].start_symbol = res[0][0];
        G->rules[i].derivation.reserve(res.size()-1);
        
        for(int j=1;j<res.size();j++){
            G->rules[i].derivation.push_back(res[j]);
        }
        G->index.insert({G->rules[i].start_symbol,i});
    }
}

void __check_useless(grammar *G, int *is_useless, int row=0){
    if(is_useless[row] == 0 || is_useless[row]==-1)
        return;
    is_useless[row] = 0;
    for(int i=0; i<G->rules[row].derivation.size(); i++){
        for(char alpha:G->rules[row].derivation[i]){
            if(alpha >='A' && alpha <='B'){
                //non terminal
                __check_useless(G, is_useless, G->index[alpha]);
            }
        }
    }
}

grammar* remove_useless_production(grammar *G, int del){
    int is_useless[G->rules.size()];
    for(int i=0;i<G->rules.size();i++)
        is_useless[i] = 1;
    

    //remove non terminating
    for(int i=0;i<G->rules.size();i++){
        int nnterm = 0;
        int nnterm_diff = 0;
        bool has_term = false;
        for(const string &p : G->rules[i].derivation){
            bool temp = true;
            for(const char alpha : p){
                if(alpha>='A' && alpha<='Z'){
                    temp = false;
                    nnterm += 1;
                    if(alpha != G->rules[i].start_symbol){
                        nnterm_diff += 1;
                    }
                }
            }
            has_term |= temp;
        }
        if(!has_term && nnterm != 0 && nnterm_diff == 0){
            is_useless[i] = -1;
        }
    }
    unordered_set<char> __ul;
    for(int i=0;i<G->rules.size(); i++){
        if(is_useless[i] == -1)
            __ul.insert(G->rules[i].start_symbol);
    }

    //remove non reachable
    __check_useless(G,is_useless);
    for(int i=0;i<G->rules.size(); i++)
        if(is_useless[i] != 0)
            __ul.insert(G->rules[i].start_symbol);


    grammar * new_g = new grammar();
    int ind=0;
    for(int i=0;i<G->rules.size(); i++){
        if(is_useless[i] == 0){
            new_g->rules.push_back(production());
            for(const string &der: G->rules[i].derivation){
                bool chk = false;
                for(char c:der){
                    if(__ul.find(c) != __ul.end()){
                        chk = true;
                        break;
                    }
                }
                if(!chk){
                    new_g->rules[ind].derivation.push_back(der);
                }
            }
            new_g->rules[ind].start_symbol = G->rules[i].start_symbol;
            new_g->index[G->rules[i].start_symbol] = ind++;
        }
    }

    if(del)
        delete G;
    return new_g;
}

int __is_nullable(grammar *G, unordered_set<int> &ind, int row, unordered_set<int> &seen){
    if(ind.find(row) != ind.end())  
        return 1;
    if(seen.find(row) != seen.end())  
        return 0;

    seen.insert(row);
    int res = 0;
    for(const string &der:G->rules[row].derivation){
        bool flag = false;
        for(const char alpha:der){
            if(alpha == EPSILON){
                flag = true;
                break;
            }
            /*else if(alpha >='A' && alpha <= 'Z'){
                int chk = __is_nullable(G,ind,G->index[alpha],seen);
                if(chk==1){
                    flag = true;
                    break;
                }
            }*/
        }
        if(flag){
            ind.insert(row);
            res = 1;
            break;
        }
    }
    seen.erase(row);
    return res;
}

void __sub_epsilon(grammar *G, unordered_set<int> &ind, string &der, vector<string> &derivation){
    int j=0;
    if(der[0] == EPSILON)
        return;

    vector<int> index_eliminate;
    for(int j=0;j<der.size();j++){
        char alpha = der[j];
        if(alpha >='A' && alpha <='Z'){
            int i = G->index[alpha];
            if(ind.find(i) != ind.end())
                index_eliminate.push_back(j);
        }
    }

    if(index_eliminate.size()==0){
        derivation.push_back(der);
        return;
    }
    
    for(int i=pow(2,index_eliminate.size())-1;i>=0;i--){
        string curr = "";
        int cj = 0;
        for(int j=0;j<der.size();j++){
            if(index_eliminate[cj] == j){
                if(i & 1<<cj){
                    curr += der[j];
                }
                cj++;
            }else{
                curr += der[j];
            }
        }
        if(curr != "")
            derivation.push_back(curr);
    }
}

grammar * remove_eplison_production(grammar *G, int del){
    unordered_set<int> ind;
    for(int i=0;i<G->rules.size();i++){
        unordered_set<int> seen;
        __is_nullable(G,ind,i,seen);
    }

    grammar * new_g = new grammar(); 
    int __ind = 0;   
    for(int i=0;i<G->rules.size();i++){
        vector<string> derivation;
        for(string &der:G->rules[i].derivation){
            __sub_epsilon(G,ind,der,derivation);
        }
        new_g->rules.push_back(production());
        new_g->rules[__ind].start_symbol = G->rules[i].start_symbol;
        new_g->rules[__ind].derivation = derivation;
        new_g->index[G->rules[i].start_symbol] = __ind++;
    }
    if(del)
        delete G;
    return new_g;
}


void remove_unit_production(grammar *G){
    unordered_map<char,char> seen;
    for(int i=G->rules.size()-1;i>=0 ;i--){
        if(G->rules[i].derivation.size() == 1){
            //1 derivation
            string &first = G->rules[i].derivation[0];
            if(first.size()==1 && seen.find(first[0])!=seen.end()){
                //replace
                first[0] = seen[first[0]];
            }
            if(first[0]>='a' && first[0]<='z')
                seen[G->rules[i].start_symbol] = first[0];
        }else{
            for(string &p: G->rules[i].derivation){
                if(p.size()==1 && seen.find(p[0])!=seen.end()){
                    p[0] = seen[p[0]];
                    seen[G->rules[i].start_symbol] = p[0];
                }
            }
        }
    }
}


void remove_immediate_left_recursion(grammar *G){
    grammar tempG;
    for(int i=0;i<G->rules.size();i++){
        int has_ir = false;
        for(string &prod : G->rules[i].derivation){
            if(prod.size() == 2){
                int nnterm = 0;
                int temp=1;
                if(prod[0]>='A' && prod[0]<='Z'){
                    nnterm += 1;
                    temp = 0;
                }
                if(prod[1]>='A' && prod[1]<='Z')
                    nnterm += 1;

                if(nnterm == 1 && prod[temp]==G->rules[i].start_symbol){
                    //immediate left recursion
                    prod[temp] = (char)(G->rules[i].start_symbol+5);
                    has_ir = true;
                }
            }
        }
        if(has_ir){
            production p;
            p.start_symbol = (char)(G->rules[i].start_symbol+5);
            for(string &prod : G->rules[i].derivation){
                if(prod.size() == 1 && prod[0]>='a' && prod[0]<='z'){
                    p.derivation.push_back(prod + p.start_symbol);
                }
            }
            p.derivation.push_back("$");
            tempG.rules.push_back(p);
        }
    }
    for(auto r:tempG.rules){
        G->rules.push_back(r);
    }
}

ostream& operator <<(ostream& stream,const grammar &G){
    for(int i=0;i<G.rules.size();i++){
        cout<<G.rules[i].start_symbol<<" -> ";
        for(const string &s:G.rules[i].derivation)
            cout<<s<<" |";
        cout<<"\b \n";
    }
    return stream;
}
