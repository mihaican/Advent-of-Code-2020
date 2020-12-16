#include <iostream>
#include <fstream>
#include <map>
using namespace std;
ifstream fin("aoc15.in");
ofstream fout("aoc15.out");
long long v[100],n,lastspoken;
long long last;
map<long long,long long>f;
map<long long,long long>firstturn;
map<long long,long long>turn;
char skip;
int main(){
    for(int i=1;i<=6;i++){
        fin>>v[i]>>skip;
        f[v[i]]++;
        turn[v[i]]=i;
        last=v[i];
        lastspoken=v[i];
    }
    for(int i=7;i<=30000000;i++){
        fout<<i<<" ";
        if(f[lastspoken]>1){
            lastspoken=i-1-firstturn[lastspoken];
            f[lastspoken]++;
            firstturn[lastspoken]=turn[lastspoken];
            turn[lastspoken]=i;
            continue;
        }
        if(f[lastspoken]==1){
            lastspoken=0;
            f[lastspoken]++;
            firstturn[lastspoken]=turn[lastspoken];
            turn[lastspoken]=i;
            continue;
        }
        if(f[lastspoken]==0){
            f[lastspoken]++;
            firstturn[lastspoken]=turn[lastspoken];
            turn[lastspoken]=i;
            continue;
        }
    }
    cout<<lastspoken;
}
/* unoptimized */
