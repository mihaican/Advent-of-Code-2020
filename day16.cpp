#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc16.in");
string x;
char skip;
int low,high,ticket,n;
int check;
int f[10000];
int nearby[10000];
long long sum=0;
int main(){
    while(getline(fin,x)){
        if(x.find("your ticket:")==string::npos)
            for(int i=0;i<x.size();i++){
                int low=0,high=0;
                while(isdigit(x[i]))
                    low=low*10+x[i++]-'0';
                if(x[i]=='-')
                    i++;
                while(isdigit(x[i]))
                    high=high*10+x[i++]-'0';
                if(low&&high)
                    for(int j=low;j<=high;j++)
                        f[j]++;

            }
        if(x.find("nearby tickets:")!=string::npos){
            while(fin>>ticket){
                fin>>noskipws>>skip;
                nearby[++n]=ticket;
                }
        }
    }
    for(int i=1;i<=n;i++)
        if(!f[nearby[i]])
            sum+=nearby[i];
    cout<<sum;
}
