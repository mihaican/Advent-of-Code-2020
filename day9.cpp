/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc9.in");
long long v[1010],x;
int main(){
    int cnt=0;
    while(fin>>v[++cnt]);
    for(int i=26;i<=1000;i++){
        long long target=v[i],found=0;
        for(int j=i-25;j<i;j++)
            for(int t=i-25;t<i;t++)
                if(t!=j&&v[j]+v[t]==target){
                    found=1;
                    j=696969696;
                    break;
                }
        if(found==0)
            cout<<v[i]<<" "<<i<<endl;

    }

}*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc9.in");
long long v[1010],x;
int main(){
    int cnt=0,id=1;
    while(fin>>v[++cnt]);
    long long intruder;
    for(int i=26;i<=1000;i++){
        long long target=v[i],found=0;
        for(int j=i-25;j<i;j++)
            for(int t=i-25;t<i;t++)
                if(t!=j&&v[j]+v[t]==target){
                    found=1;
                    j=696969696;
                    break;
                }
        if(found==0)
            intruder=v[i];
    }
    int pos1,pos2;
    for(int i=1;i<=1000;i++){
        unsigned long long sum=v[i];
        for(int j=i+1;j<=1000;j++){
            sum+=v[j];
            if(sum==intruder){
                pos1=i;
                pos2=j;
                break;
            }
            if(sum>intruder)
                break;
        }
    }
    long long smol,big;
    for(int i=pos1;i<=pos2;i++){
        smol=min(v[i],smol);
        big=max(v[i],big);
    }
    cout<<smol+big;


}
