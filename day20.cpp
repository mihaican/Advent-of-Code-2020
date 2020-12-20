//day 20 attempt
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin("day20.in");
char skip,sym;
string read;
int x;
string v[20];
string aux[20];
map <int, vector <string> > a;
void input(int x){
    for(int i=0;i<=9;i++)
        a[x].push_back(v[i]);
}
void rotate(){
    for(int i=0;i<=9;i++){
            string k="";
            for(int j=9;j>=0;j--)
                k+=v[j][i];
        aux[i]=k;
    }
    for(int i=0;i<=9;i++)
        v[i]=aux[i];
}
void flip(){
    for(int i=0;i<=9;i++){
        string k="";
        for(int j=9;j>=0;j--)
            k+=v[i][j];
        aux[i]=k;
    }
    for(int i=0;i<=9;i++)
        v[i]=aux[i];

}
void upsidedown(){
    for(int i=9;i>=0;i--)
       aux[9-i]=v[i];
    for(int i=0;i<=9;i++)
        v[i]=aux[i];
}
int main(){
    for(int i=1;i<=9;i++){
        string original[20];
        fin>>skip>>skip>>skip>>skip>>x>>skip;
        for(int i=0;i<=9;i++){
            fin>>v[i];
            original[i]=v[i];
        }
        input(x);
        upsidedown();
        input(x*10+9);
        rotate(); //90
        input(x*10+1);
        rotate(); //180
        input(x*10+2);
        rotate(); //270
        input(x*10+3);
        for(int i=0;i<=9;i++)
            v[i]=original[i];
        flip();
        input(x*10+5); //flipped
        rotate();
        input(x*10+6); //flipped +90
        rotate();
        input(x*10+7); //flipped +180
        rotate;
        input(x*10+8); //flipped +270
    }

    for(auto& i:a){
        int keya,check=1;
        if(i.first/10000==0)
            keya=i.first;
        else
            keya=i.first/10;
        for(auto& j:a){
            int keyb;
            if(j.first/10000==0)
                keyb=j.first;
            else
                keyb=j.first/10;
            if(keya!=keyb)
                //cout<<i.second[0]<<" || "<<j.second[n]<<endl;
                if(i.second[0]==j.second[9]){
                  //  cout<<i.second[0]<<" || "<<j.second[n]<<endl;
                    check=0;
                    break;
                }
        }
        if(check==1)
            cout<<i.second[0]<<endl<<endl;
    }

}
