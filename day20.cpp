//day 20 part1
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
using namespace std;
ifstream fin("day20.in");
ofstream fout("day20.out");
char skip,sym;
string read;
int x,f[4001];
string v[20];
string aux[20];
set <string> margini;
map <int, vector <string> > a;
void input(int x){
    for(int i=0;i<=9;i++)
        a[x].push_back(v[i]);
}
int translatekey(int x){
    if(x/100000==0)
        return x;
    else
        return x/100;
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
    for(int i=1;i<=144;i++){
        string original[20];
        fin>>skip>>skip>>skip>>skip>>x>>skip;
        for(int i=0;i<=9;i++){
            fin>>v[i];
            original[i]=v[i];
        }
        input(x);
        rotate(); //90
        input(x*100+10);
        rotate(); //180
        input(x*100+20);
        rotate(); //270
        input(x*100+30);
        for(int i=0;i<=9;i++)
            v[i]=original[i];
        flip();
        input(x*100+40); //flipped
        rotate();
        input(x*100+50); //flipped +90
        rotate();
        input(x*100+60); //flipped +180
        rotate();
        input(x*100+70); //flipped +270

        for(int i=0;i<=9;i++)
            v[i]=original[i];
        upsidedown();
        input(x*100+80);// upsidedown
        rotate();
        input(x*100+90);  //upsidedown +90
        rotate();
        input(x*100+91); //upsidedown +180
        rotate();
        input(x*100+92); //upsidedown +270
    }
    for(auto& i:a){
        int keya=translatekey(i.first);
        int check=1;
        for(auto& j:a){
            int keyb=translatekey(j.first);
                if(keya!=keyb)
                    if(i.second[0]==j.second[9]){
                        check=0;
                        break;
                    }
        }
        if(check){
            f[keya]++;//margini.insert(i.second[0]);//cout<<i.second[0]<<endl<<endl;
        }

    }
    unsigned long long answ=1;
    for(int i=0;i<=4000;i++)
        if(f[i]==6)
            answ*=i;
    cout<<answ;
}
