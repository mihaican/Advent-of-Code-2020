#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("day23.in");
char x;
int timer=100,current,pos,nextcup,destination;
vector<int> cups;
int main(){
    while(fin>>x)
        cups.push_back(x-'0');
    nextcup=cups[0];
    while(timer--){
        current=nextcup;
        auto here=find(cups.begin(),cups.end(),current);
        int cup1,cup2,cup3;
        for(;;){
            if(here+1==cups.end()){
            here=cups.begin();
            cup1=*(here);
            cup2=*(here+1);
            cup3=*(here+2);
            nextcup=*(here+3);
            break;
            }
            else
                cup1=*(here+1);
            if(here+2==cups.end()){
                here=cups.begin();
                cup2=*(here);
                cup3=*(here+1);
                nextcup=*(here+2);
                break;
            }
            else
                cup2=*(here+2);
            if(here+3==cups.end()){
                here=cups.begin();
                cup3=*(here);
                nextcup=*(here+1);
                break;
            }
            else
                cup3=*(here+3);
            if(here+4==cups.end()){
                here=cups.begin();
                nextcup=*(here);
                break;
            }
            nextcup=*(here+4);
            break;
        }
        destination=current-1;
        for(;;){
            if(destination==0)
                destination=9;
            if(cup1==destination||cup2==destination||cup3==destination)
                destination--;
            else
                break;
        }
        cups.erase(find(cups.begin(),cups.end(),cup1));
        cups.erase(find(cups.begin(),cups.end(),cup2));
        cups.erase(find(cups.begin(),cups.end(),cup3));
        auto it=find(cups.begin(),cups.end(),destination);
        cups.insert(it+1,cup1);
        cups.insert(it+2,cup2);
        cups.insert(it+3,cup3);
        pos++;
    }
     for(auto& i:cups)
            cout<<i<<"";

}
