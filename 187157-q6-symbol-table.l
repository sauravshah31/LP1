%{
    #include <iostream>
    #include <string>
    #include <unordered_map>
    #include <set>
    #include <utility>

    #define NONE            0
    #define CONJUCTION      1
    #define INTERJECTION    2
    #define PREPOSITION     3

    using namespace std; 

    typedef struct symbol_node{
        string name;
        int type;
    }symbol_node;

    typedef struct symbol_table{
        symbol_node symbol;
        struct symbol_table *next=NULL;    
    }symbol_table;
    
    symbol_table *H=NULL ,*T=NULL;

    //container of word frequency: [word : (count,[line numbers])]
    unordered_map<string, pair<int,set<int>>> frequency;

    void insert(char *match, int lineno, int type);
    void print();
%}

conjuction              and|or|but|for|nor|so|yet|after|although|as
interjection            aah|ack|agreed|ah|aha|ahem|alas|amen|argh|aw|ay|aye|bah|blast|bother|boy|brr|bye|cheerio|cheers|crikey|curses|doggone|drat|duh|eek|egads|er|exactly|fiddle-dee-dee|fiddlesticks|fie|foo|fooey|gadzooks|gah|gangway|g'day|gee|geez|gesundheit|good|gosh|gracious|great|grr|gulp|ha|ha-ha|hah|hallelujah|harrumph|haw|hee|here|hey|hmm|hoo|hooray|how|huh|hum|humbug|hurray|huzza|ick|ixnay|jeez|kapish|la|la-di-dah|lo|look|lordy|man|meh|mmm|my|nah|naw|never|no|nooo|not|nuts|oh|oho|oh-oh|okay|okey-dokey|om|oof|ooh|oopsey|over|oy|oyez|peace|pff|pew|phew|psst|ptui|quite|rah|rats|ready|right|roger|rumble|say|shame|shh|shoo|shucks|sigh|snap|sorry|sssh|sup|ta|ta-da|tch|thanks|there|toodles|touche|tsk|tsk-tsk|tut|tut-tut|ugh|uh|uh-oh|um|ur|urgh|voila|vroom|wah|well|what|whatever|whee|when|whoa|whoo|whoopee|whoops|whoopsey|whew|why|word|wow|wuzzup|ya|yea|yeah|yech|yikes|yippee|yo|yoo-hoo|yow|yum|yummy|zap|zounds|zowie|zzz
proposition             a|abaft|aboard|about|above|absent|across|afore|after|against|along|alongside|amid|amidst|among|amongst|an|anenst|apropos|apud|around|as|aside|astride|at|athwart|atop|barring|before|behind|below|beneath|beside|besides|between|beyond|but|by|circa|concerning|despite|down|during|except|excluding|failing|following|for|forenenst|from|given|in|including|inside|into|lest|like|mid|midst|minus|modulo|near|next|notwithstanding|of|off|on|onto|opposite|out|outside|over|pace|past|per|plus|pro|qua|regarding|round|sans|save|since|than|through|throughout|till|times|to|toward|towards|under|underneath|unlike|until|unto|up|upon|versus|via|vice|with|within|without|worth
word                    [A-Za-z][a-z]*('[a-z])?

%option yylineno
%%
{conjuction}        {insert(yytext, yylineno, CONJUCTION);}
{interjection}      {insert(yytext, yylineno, INTERJECTION);}
{proposition}       {insert(yytext, yylineno, PREPOSITION);}
{word}              {insert(yytext, yylineno, NONE);}
.|\n        ;
%%

void insert(char *match, int lineno, int type){
    int ins = 0;
    string s = string(match);
    if(frequency.find(s)==frequency.end()){
        frequency[s] = pair<int,set<int>>();
        frequency[s].first = 1;
        ins=1;
    }else{
        frequency[s].first += 1;
    }
    frequency[s].second.insert(lineno);

    if(ins){
        if(type != NONE){
            if(H == NULL){
                H = new symbol_table();
                H->symbol.name = s;
                H->symbol.type = type;
                T=H;
            }else{
                T->next = new symbol_table();
                T = T->next;
                T->symbol.name = s;
                T->symbol.type = type;
            }
        }
    }
}

void print(){
    string type[] = {"","CONJUCTION","INTERJECTION","PREPOSITION"};
    cout<<"SYMBOL TABLE\n------------------------\n";
    cout<<"symbol\ttype\n------------------------\n";
    for(symbol_table *start = H; start!=NULL;start=start->next){
        cout<<start->symbol.name<<"\t"<<type[start->symbol.type]<<endl;
    }

    cout<<endl;
    cout<<"FRQUENCY TABLE\n--------------------------\n";
    cout<<"word\tcount\tlines\n-------------------------\n";
    for(auto entry:frequency){
        cout<<entry.first<<"\t"<<entry.second.first<<"\t";
        for(int ln:entry.second.second)
            cout<<ln<<",";
        cout<<"\b \n";
    }
}
int yywrap(){
    return 1;
}
int main(){
    yylex();
    print();
    return 1;
}
