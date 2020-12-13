/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc11.in");
int a[100][100];
int original[100][100],occupied;
int di[]={1,-1,0,0,-1,-1,1,1};
int dj[]={0,0,1,-1,-1,1,-1,1};
char x;
int main(){
    for(int i=1;i<=90;i++)
        for(int j=1;j<=96;j++){
            fin>>x;
            if(x=='.')
                a[i][j]=0;
            if(x=='L')
                a[i][j]=1;
            if(x=='#')
                a[i][j]=2;
            original[i][j]=a[i][j];
        }
    int go=1;
    while(go){
    for(int i=1;i<=90;i++)
        for(int j=1;j<=96;j++){
            if(a[i][j]==1){
                occupied=0;
                for(int t=0;t<8;t++)
                    if(a[i+di[t]][j+dj[t]]==2)
                        occupied++;
                if(!occupied)
                    original[i][j]=2;
            }
            if(a[i][j]==2){
                occupied=0;
                for(int t=0;t<8;t++)
                    if(a[i+di[t]][j+dj[t]]==2)
                        occupied++;
                if(occupied>=4)
                    original[i][j]=1;
            }
    }   int check=0;
        for(int i=1;i<=90;i++)
        for(int j=1;j<=96;j++){
            if(a[i][j]==original[i][j])
                check++;
            a[i][j]=original[i][j];
        }
        if(check==90*96)
            go=0;
    }
     /*for(int i=1;i<=90;i++){
        for(int j=1;j<=96;j++){
            if(original[i][j]==0)
                cout<<".";
            if(original[i][j]==1)
                cout<<"L";
            if(original[i][j]==2)
                cout<<"#";
        }
        cout<<endl;
        }
    occupied=0;
    for(int i=1;i<=90;i++){
        for(int j=1;j<=96;j++){
            if(original[i][j]==2)
                occupied++;
        }
        }
        cout<<occupied;
}
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc11.in");
int a[110][110];
int original[100][100],occupied;
int di[]={1,-1,0,0,-1,-1,1,1};
int dj[]={0,0,1,-1,-1,1,-1,1};
char x;
int main(){
    for(int i=1;i<=90;i++)
        for(int j=1;j<=96;j++){
            fin>>x;
            if(x=='.')
                a[i][j]=0;
            if(x=='L')
                a[i][j]=1;
            if(x=='#')
                a[i][j]=2;
            original[i][j]=a[i][j];
        }
    int go=1;
    while(go){
    for(int i=1;i<=90;i++)
        for(int j=1;j<=96;j++){
            if(a[i][j]==1){
                occupied=0;
                for(int t=0;t<8;t++)
                    for(int q=1;q<=100&&i+di[t]*q>0&&i+di[t]*q<100&&j+dj[t]*q>0&&j+dj[t]*q<100;q++){
                        if(a[i+di[t]*q][j+dj[t]*q]==2){
                            occupied++;
                            break;
                        }
                        if(a[i+di[t]*q][j+dj[t]*q]==1)
                            break;
                    }
                if(!occupied)
                    original[i][j]=2;
            }
            if(a[i][j]==2){
                occupied=0;
                for(int t=0;t<8;t++)
                    for(int q=1;q<=100&&i+di[t]*q>0&&i+di[t]*q<100&&j+dj[t]*q>0&&j+dj[t]*q<100;q++){
                        if(a[i+di[t]*q][j+dj[t]*q]==2){
                                occupied++;
                                break;
                        }
                        if(a[i+di[t]*q][j+dj[t]*q]==1)
                            break;
                    }
                if(occupied>=5)
                    original[i][j]=1;
            }
    }   int check=0;
        for(int i=1;i<=90;i++)
        for(int j=1;j<=96;j++){
            if(a[i][j]==original[i][j])
                check++;
            a[i][j]=original[i][j];
        }
        if(check==96*90)
            go=0;
    }
    occupied=0;
    for(int i=1;i<=90;i++){
        for(int j=1;j<=96;j++){
            if(original[i][j]==2)
                occupied++;
        }
    }
        cout<<occupied;
    return 0;
}
