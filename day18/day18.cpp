/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc18.in");
string v;
unsigned long long sum=0;
long long term(),expression(),i;
long long expression(){
    long long result;
    result=term();
    while(v[i]=='+'||v[i]=='*'){
        if(v[i]=='+'){
            i++;
            result+=term();
        }
        if(v[i]=='*'){
            i++;
            result*=term();
        }
    }
    return result;
}
long long term() {
    long long result;
    if(v[i]=='('){
        i++;
        result=expression();
        i++;
    }
    else{
        result=0;
        while(isdigit(v[i])){
            result=result*10+(v[i]-'0');
            i++;
        }
    }
    return result;
}
int main () {
    while(getline(fin,v)){
        sum+=expression();
        i=0;
    }
    cout<<sum;
}
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc18.in");
long long sum;
string v;
long long term(),factor(),expression(),i;
long long expression(){
    long long result;
    result=factor();
    while(v[i]=='*')
        if(v[i]=='*'){
            i++;
            result*=factor();
        }
    return result;
}
long long factor(){
    long long result;
    result=term();
    while(v[i]=='+')
        if(v[i]=='+'){
            i++;
            result+=term();
        }
    return result;
}
long long term(){
    long long result;
    if(v[i]=='('){
        i++;
        result=expression();
        i++;
    }
    else{
        result=0;
        while(isdigit(v[i])){
            result=result*10+(v[i]-'0');
            i++;
        }
    }
    return result;
}
int main () {
   while(getline(fin,v)){
        sum+=expression();
        i=0;
    }
    cout<<sum;
}
