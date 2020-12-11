/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc3.in");
int a[500][500],trees;
char x;
int main(){
    for(int i=1;i<=323;i++)
    for(int j=1;j<=31;j++){
        fin>>x;
        if(x=='.')
            a[i][j]=0;
        else
            a[i][j]=1;
    }
     int j=1;
     for(int i=1;i<=323;i++){
           if(a[i][j]==1)
                trees++;
            j+=3;
            if(j>31)
                j=j%31;

        }
        cout<<trees;
}*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc3.in");
long long a[500][500];
char x;
long long vtraseu(int angle,int down){
    long long trees=0,j=1;
     for(int i=1;i<=323;i+=down){
           if(a[i][j]==1)
                trees++;
            j+=angle;
            if(j>31)
                j=j%31;

        }
    return trees;
}
int main(){
    for(int i=1;i<=323;i++)
    for(int j=1;j<=31;j++){
        fin>>x;
        if(x=='.')
            a[i][j]=0;
        else
            a[i][j]=1;
    }
    cout<<vtraseu(1,1)*vtraseu(3,1)*vtraseu(5,1)*vtraseu(7,1)*vtraseu(1,2);
}

