/*#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("aoc5.in");
string x;
int low=0,high=127,sidelow=0,sidehigh=7,seatid,maxid;
int main(){
    while(getline(fin,x)){
        for(int i=0;i<=6;i++){
            if(x[i]=='F')
                high=(high+low)/2;
            if(x[i]=='B')
                low=(high+low)/2+1;
        }
        for(int i=7;i<=9;i++){
            if(x[i]=='L')
                sidehigh=(sidehigh+sidelow)/2;
            if(x[i]=='R')
                sidelow=(sidehigh+sidelow)/2+1;
            }
        seatid=low*8+sidelow;
        maxid=max(maxid,seatid);
        low=0,high=127;
        sidelow=0,sidehigh=7;
    }
    cout<<maxid;
    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("aoc5.in");
string x;
int low=0,high=127,sidelow=0,sidehigh=7,seatid;
int f[1024];
int main(){
    while(getline(fin,x)){
        for(int i=0;i<=6;i++){
            if(x[i]=='F')
                high=(high+low)/2;
            if(x[i]=='B')
                low=(high+low)/2+1;
        }
        for(int i=7;i<=9;i++){
            if(x[i]=='L')
                sidehigh=(sidehigh+sidelow)/2;
            if(x[i]=='R')
                sidelow=(sidehigh+sidelow)/2+1;
            }
        seatid=low*8+sidelow;
        f[seatid]=1;
        low=0,high=127;
        sidelow=0,sidehigh=7;
    }
    for(int i=1;i<=1023;i++)
        if(!f[i]&&f[i-1]&&f[i+1])
            cout<<i;
    int * x=&f[524];
    cout<<" "<<f[1]<<" "<<*x;

}
