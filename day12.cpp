/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc12.in");
char cmd;
int arg;
int x,y,angle=1;
pair <char,int> commands[10000];
int main(){
    for(int i=1;i<=786;i++){
        fin>>cmd>>arg;
        commands[i].first=cmd;
        commands[i].second=arg;
    }
    for(int i=1;i<=786;i++){
        if(commands[i].first=='N')
            x-=commands[i].second;
        if(commands[i].first=='S')
            x+=commands[i].second;
        if(commands[i].first=='W')
            y-=commands[i].second;
        if(commands[i].first=='E')
            y+=commands[i].second;
        if(commands[i].first=='R'){
            angle+=commands[i].second/90;
            angle%=4;
        }
        if(commands[i].first=='L'){
            angle-=commands[i].second/90;
            if(angle<0)
                angle+=4;
            angle%=4;
        }
        if(commands[i].first=='F'){
            if(angle==1) // East
                y+=commands[i].second;
            if(angle==2) //South
                x+=commands[i].second;
            if(angle==3)// West
                y-=commands[i].second;
            if(angle==0)// North
                x-=commands[i].second;
        }
       // cout<<x<<" "<<y<<" "<<angle<<endl;
    }
    cout<<abs(x)+abs(y);
}
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc12.in");
char cmd;
int arg;
int x,y,angle=1;
int wx=-1,wy=10,wangle;
pair <char,int> commands[10000];
int main(){
    for(int i=1;i<=786;i++){
        fin>>cmd>>arg;
        commands[i].first=cmd;
        commands[i].second=arg;
    }
    for(int i=1;i<=786;i++){
        if(commands[i].first=='N')
            wx-=commands[i].second;
        if(commands[i].first=='S')
            wx+=commands[i].second;
        if(commands[i].first=='W')
            wy-=commands[i].second;
        if(commands[i].first=='E')
            wy+=commands[i].second;
        if(commands[i].first=='R'){
            if(commands[i].second==90)
                swap(wx,wy),wy*=-1;
            if(commands[i].second==180)
                wy*=-1,wx*=-1;
            if(commands[i].second==270)
                swap(wx,wy),wx*=-1;
        }
        if(commands[i].first=='L'){
            if(commands[i].second==270)
                swap(wx,wy),wy*=-1;
            if(commands[i].second==180)
                wy*=-1,wx*=-1;
            if(commands[i].second==90)
                swap(wx,wy),wx*=-1;
        }
        if(commands[i].first=='F'){
           x+=commands[i].second*wx;
           y+=commands[i].second*wy;
        }
    }
    cout<<abs(x)+abs(y);
}
/*
Action N means to move north by the given value.
Action S means to move south by the given value.
Action E means to move east by the given value.
Action W means to move west by the given value.
Action L means to turn left the given number of degrees.
Action R means to turn right the given number of degrees.
Action F means to move forward by the given value in the direction the ship is currently facing.
*/
