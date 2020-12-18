#include <iostream>
#include <fstream>
#include <map>
using namespace std;
//fstream fin("coinchange.in");
long long n,x1[10010],y1[10010],fx[10010],fy[10010],airstrike,timer=5;
void updatefreq(){
    for(int i=1;i<=10000;i++)
        fx[x1[i]]++,
        fy[y1[i]]++;
}
int x[1000],f[100];
void afis(int k){
    for(int i=1 ; i<=k ; ++i)
        cout << x[i] << " ";
    cout << endl;
}
bool verif(int k){
    if(k==1)
        return true;
    if(x[k]<=(x[k-1]+1) )
        return false;
    if(f[x[k]]==1)
        return false;
    if(k<=n)
        return true;
    return false;


}
void back(int k){
    for(int i=1;i<=n;++i){
        x[k]=i;
        if(verif(k)){
            f[x[k]]=1;
            //if(k==n)
                afis(k);
            back(k+1);
            f[x[k]]=0;
        }

    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x1[i]>>y1[i];
    back(1);


}
