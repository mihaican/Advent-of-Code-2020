#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc2.in");
int a,b,cnt,position=0,j1,j2;
char c,criteria,sir=1,k=0;
int main(){
    for(int i=1;i<=1001;i++){
        fin>>skipws>>a>>c>>b>>criteria>>c;

        while(sir!='\n'){
            fin>>noskipws>>sir;
            if(criteria==sir&&position==a)
                j1=1;
            if(criteria==sir&&position==b)
                j2=1;
            position++;
        }
        if(j1^j2)
            cnt++;
        sir=1;
        k=0;
        position=0;
        j1=0;
        j2=0;
    }
    cout<<cnt;
    return 0;
}
