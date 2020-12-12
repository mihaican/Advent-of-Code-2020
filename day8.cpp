/*#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc8.in");
pair <int,int> instructions[1000];
int visited[1000];
int accumulator;
int gothru(int pos){
    if(visited[pos]==1){
        cout<<accumulator;
        return 0;
    }
    visited[pos]=1;
    if(instructions[pos].first==1){
        ;//do nothing :)
    }
    if(instructions[pos].first==2)
        accumulator+=instructions[pos].second;
     if(instructions[pos].first==3)
        return gothru(pos+instructions[pos].second);
    gothru(pos+1);

}
int main(){
    string x;
    int it=0;
    while(getline(fin,x)){
            it++;
           // cout<<x<<endl;
            if(x.find("nop")!=string::npos)
                instructions[it].first=1;
            if(x.find("acc")!=string::npos)
                instructions[it].first=2;
            if(x.find("jmp")!=string::npos)
                instructions[it].first=3;
            int argument=0,i=5;
            while(isdigit(x[i++]))
                argument=argument*10+x[i-1]-'0';
          //  cout<<argument<<endl;
            instructions[it].second=argument;
            if(x[4]=='-')
                instructions[it].second*=-1;
    }
  // for(int i=1;i<=it;i++)
       // cout<<instructions[i].first<<" "<<instructions[i].second<<endl;
    gothru(1);
}

//nop =1
//acc =2
//jmp =3
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("aoc8.in");
pair <int,int> instructions[1000];
int visited[1000];
int accumulator,it;
int gothru(int pos){
    if(visited[pos]==1)
        return 0;
    visited[pos]=1;
    if(instructions[pos].first==1){
        ;//do nothing :)
    }
    if(instructions[pos].first==2)
        accumulator+=instructions[pos].second;
     if(instructions[pos].first==3)
        return gothru(pos+instructions[pos].second);
    if(pos+1>it)
        return 69;
    gothru(pos+1);

}
int main(){
    string x;
    while(getline(fin,x)){
            it++;
            if(x.find("nop")!=string::npos)
                instructions[it].first=1;
            if(x.find("acc")!=string::npos)
                instructions[it].first=2;
            if(x.find("jmp")!=string::npos)
                instructions[it].first=3;
            int argument=0,i=5;
            while(isdigit(x[i++]))
                argument=argument*10+x[i-1]-'0';
            instructions[it].second=argument;
            if(x[4]=='-')
                instructions[it].second*=-1;
    }

    for(int i=1;i<=it;i++){
        if(instructions[i].first==1){
            instructions[i].first=3;
            fill(visited,visited+999,0);
            accumulator=0;
            if(gothru(1)!=69)
                instructions[i].first=1;
            else{
                cout<<accumulator;
                return 0;
            }

        }
        if(instructions[i].first==3){
            instructions[i].first=1;
            fill(visited,visited+999,0);
            accumulator=0;
            if(gothru(1)!=69)
                instructions[i].first=3;
            else{
                cout<<accumulator;
                return 0;
            }

        }

    }

}
