/*#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("aoc13.in");
int n,x,earliest=INT_MAX,id;
char skip;
int v[100],cnt=1;
int main(){
    fin>>n;
    fin>>v[1];
    for(int i=1;i<=180;i++){
        char pk=fin.peek();
        if(isdigit(pk)){
            fin>>x;
            v[++cnt]=x;
        }
        else{
            fin>>skip;
            if(skip=='x')
                v[++cnt]=n;
        }
    }
    for(int i=1;i<=cnt;i++){
        int eta=n+(v[i]-n%v[i]);
        if(eta<earliest)
            earliest=eta,id=v[i];
    }
    cout<<id*(earliest-n);

}
*/
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("aoc13.in");
int n,x,earliest=INT_MAX,id;
char skip;
int v[100],cnt=1;
long long prod,pp[100],inv[100];
int skips[100];
long long reminder[100];
long long invmod(long long a,long long m){
    a%=m;
    for (long long x=1;x<m;x++)
        if ((a*x)%m)
            return x;
}
int main(){
    fin>>n;
    fin>>v[1];
    prod=v[1];
    for(int i=1;i<=200;i++){
        char pk=fin.peek();
        if(isdigit(pk)){
            fin>>x;
            v[++cnt]=x;
            prod*=x;
        }
        else{
            fin>>skip;
            if(skip=='x')
                skips[cnt+1]++;
        }
    }
    int down=-1;
    long long sum=0;
    for(int i=1;i<=cnt;i++){
        down+=skips[i]+1;
        reminder[i]=(v[i]-down)%v[i];
        pp[i]=prod/v[i];
        inv[i]=invmod(pp[i],v[i]);
        sum+=(reminder[i]*pp[i]*inv[i]);
    }
        cout<<sum%prod;
}
