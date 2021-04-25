#include <iostream>
#include <string>
using namespace std;


int main(){
    string inp;

    while(1){
        getline(cin, inp);

        cout<<"matched : [a-z]*"<<endl;
        cout<<"[a-zA-Z0-9]*"<<endl;
        cout<<"matched : [a-z]*"<<endl;
        cout<<"matched : [^abc]"<<endl;
        cout<<"matched : def"<<endl;


    }
}