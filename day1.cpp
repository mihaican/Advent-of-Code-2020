#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("aoc1.in");
long long v[1000];
int main(){
    int n=1;
    while(fin>>v[n])
        n++;
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
            for(int t=1;t<=n;t++)
                if(j!=i&&j!=t)
                    if(v[i]+v[j]+v[t]==2020)
                        cout<<v[i]*v[j]*v[t]<<endl;

    return 0;
}
