/*#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("aoc10.in");
int v[1000];
int joltage=0;
int main(){
    int cnt=0;
    while(fin>>v[++cnt]);
    sort(v+1,v+cnt);
    int delta1=0,delta2=0,delta3=0;
    for(int i=1;i<cnt;i++){
        if(v[i]-1==joltage){
            delta1++;
            joltage=v[i];
        }
        if(v[i]-2==joltage)
            joltage=v[i];
        if(v[i]-3==joltage){
            delta3++;
            joltage=v[i];
        }
    }
    cout<<delta1*(delta3+1);
}*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;
ifstream fin("aoc10.in");
int v[1000];
long long d[1000];
int joltage=0;
int t,s;
long long previ;
int main(){
    int cnt=0;
    while(fin>>v[++cnt]);
    for(int i=0;i<=720;i++)
        d[i]=1;
    sort(v+1,v+cnt);

    for(int i=1;i<cnt;i++){
        previ=INT_MIN;
        if(i>=3)
            previ=v[i-3];
        if(v[i+1]-previ==4){
                s++;
                t-=2;
        }
    else
            if(v[i+1]-v[i-1]==2)
                t++;
    }
    cout<<t<<" "<<s;
}
