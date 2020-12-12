/*#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("aoc6.in");
string x;
int cnt;
int f[80];
int main(){
    while(getline(fin,x)){
        for(int i=0;i<x.size();i++){
            if(f[x[i]-'0']==0)
                cnt++;
            f[x[i]-'0']=1;
        }
        if(x.empty())
            memset(f,0,sizeof(f));
    }
    cout<<cnt;
    return 0;
}
//49 74  28
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("aoc6.in");
string x;
int cnt,pers;
int f[80];
int main(){
    while(getline(fin,x)){
        pers++;
        for(int i=0;i<x.size();i++)
            f[x[i]-'0']++;
        if(x.empty()){
            for(char i='a';i<='z';i++)
                if(f[i-'0']==pers-1)
                    cnt++;
            memset(f,0,sizeof(f));
            pers=0;
        }
    }
    cout<<cnt;
    return 0;
}
