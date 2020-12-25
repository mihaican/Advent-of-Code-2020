#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin("day24.in");
string read,path;
struct int2{
    bool color;
    int l;
    int c;
};
map < pair<int,int>, bool >  a; // 0 means white tile 1 means black tile
vector <pair <int,int> > instructions;
bool at(int i, int j){
    if(a.find({i,j})!=a.end())
        return a[{i,j}];
    return 0;
}
int main(){
    while(getline(fin,read)){
        int l=100,c=100;
        for(int i=0;i<read.size();i+=2){
            string direction;
            int check=0;
            direction=read[i],direction+=read[i+1];
            if(direction=="se")
                check=1;
            if(direction=="sw")
                check=1;
            if(direction=="nw")
                check=1;
            if(direction=="ne")
                check=1;
            if(!check){
                direction=read[i];
                i--;
            }
            if(direction=="e")
                c++;
            if(direction=="w")
                c--;
            if(direction=="se")
                l++,c++;
            if(direction=="sw")
                l++;
            if(direction=="nw")
                l--,c--;
            if(direction=="ne")
                l--;
        }
        a[{l,c}]=!a[{l,c}];
    }
    for(int t=1;t<=100;t++){
            for(auto& q:a){
                int i=q.first.first;
                int j=q.first.second;
                if(a[{i,j}])
                    int trick=a[{i,j+1}]+a[{i,j-1}]+a[{i+1,j+1}]+a[{i+1,j}]+a[{i-1,j-1}]+a[{i-1,j}];  //if a[{x,y}] does not exist it is going to be created
            }
            for(auto& q:a){
                int i=q.first.first;
                int j=q.first.second;
                if (a[{i,j}]){
                    int neighbours=0;
                    neighbours=at(i,j+1)+at(i,j-1)+at(i+1,j+1)+at(i+1,j)+at(i-1,j-1)+at(i-1,j);
                    if(!neighbours||neighbours>2)
                        instructions.push_back(make_pair(i,j));
                }
                else{
                    int neighbours=0;
                    neighbours=at(i,j+1)+at(i,j-1)+at(i+1,j+1)+at(i+1,j)+at(i-1,j-1)+at(i-1,j);
                    if(neighbours==2)
                        instructions.push_back(make_pair(i,j));
                }
            }
        for(auto& i:instructions)
            a[{i.first,i.second}]=!a[{i.first,i.second}];
        instructions.clear();
        int changed_tiles=0;
        for(auto& i:a)
            if(i.second)
                changed_tiles++;
        cout<<changed_tiles<<endl;
    }
}
///Part 1:
/*


#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("day24.in");
string read,path;
int a[1000][1000]; // 0 means white tile 1 means black tile
int main(){
    while(getline(fin,read)){
        int l=100,c=100;
        for(int i=0;i<read.size();i+=2){
            string direction;
            int check=0;
            direction=read[i],direction+=read[i+1];
            if(direction=="se")
                check=1;
            if(direction=="sw")
                check=1;
            if(direction=="nw")
                check=1;
            if(direction=="ne")
                check=1;
            if(!check){
                direction=read[i];
                i--;
            }
            if(direction=="e")
                c++;
            if(direction=="w")
                c--;
            if(direction=="se")
                l++,c++;
            if(direction=="sw")
                l++;
            if(direction=="nw")
                l--,c--;
            if(direction=="ne")
                l--;
        }
        a[l][c]=!a[l][c];
    }
    int changed_tiles=0;
    for(auto& i:a)
        for(auto& j:i)
            if(j)
                changed_tiles++;
    cout<<changed_tiles;
}




*/
