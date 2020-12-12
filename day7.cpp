/*#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string.h>
using namespace std;
ifstream fin("aoc07.in");
int total;
multimap <string,string> bags;
string x;
string alreadyfound;
int find(string target){
    for(auto itr = bags.begin(); itr != bags.end(); ++itr){
        string cmp=itr->second;
        if(itr->second==target){
            if(alreadyfound.find(itr->first)==string::npos){
                total++;
                alreadyfound+=(itr->first);
                find(itr->first);
                }
        }
    }
    return 1;
}
int main(){
    while(getline(fin,x)){
        string key;
        size_t found=x.find("bags");
        for(int i=0;i<found;i++)
            key+=x[i];
        for(int i=0;i<x.size();i++){
            if(isdigit(x[i])){
                string value;
                if(x[i]=='1')
                    found=x.find("bag",found+1);
                else
                    found=x.find("bags",found+1);
                for(int j=i+2;j<found;j++)
                    value+=x[j];
                bags.insert(pair<string,string>(key,value));
            }
        }

    }
    find("shiny gold ");
    cout<<total;

}
*/
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string.h>
using namespace std;
ifstream fin("aoc07.in");
int total;
multimap <string,string> bags;
string x;
map <string,int> coeficient;
int find(string target){
    int check=0;
    int sum=0;
    for(auto itr = bags.begin(); itr != bags.end(); ++itr){
        if(itr->first==target){
            check=1;
            sum+=coeficient[itr->first+itr->second]+coeficient[itr->first+itr->second]*find(itr->second);
    }
}
    return sum;
}
int main(){
    while(getline(fin,x)){
        string key;
        size_t found=x.find("bags");
        for(int i=0;i<found;i++)
            key+=x[i];
        for(int i=0;i<x.size();i++){
            if(isdigit(x[i])){
                string value;
                if(x[i]=='1')
                    found=x.find("bag",found+1);
                else
                    found=x.find("bags",found+1);
                for(int j=i+2;j<found;j++)
                    value+=x[j];
                bags.insert(pair<string,string>(key,value));
                coeficient[key+value]=x[i]-'0';
            }
        }

    }
    cout<<find("shiny gold ");
}
