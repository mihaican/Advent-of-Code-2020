#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;
ifstream fin("aoc21.in");
string read;
map <int,vector <string> > ingredients;
map <int,vector <string> > alergens;
map <string ,set <string> > possible_alergens;
map <string,bool> check_alergen;
set <string> counter;
int id=1;
int main(){
    while(getline(fin,read)){
        int check=0;
        for(int i=0;i<read.size();i++){
            string word="";
            while(isalpha(read[i]))
                word+=read[i++];
            if(word=="contains"){
                check=1;
                continue;
            }
            if(word!="")
                if(!check)
                    ingredients[id].push_back(word);
                else
                    alergens[id].push_back(word);
        }
        id++;
    }
    for(auto& i:alergens){ // goes through all ids
        for(auto& j:i.second){ // goes through all alergens
            for(auto& q:alergens){ // goes through all ids bigger than i
                if(i.first<q.first)
                    for(auto& t:q.second){//goes through all alergens from id=q
                        if(j==t){ //if i find the same alergens i intersect the list of ingredients
                            set <string> intersection;
                            for(auto& k:ingredients[i.first]) //goes through all ingredients from the i recipe   
                                for(auto& p:ingredients[q.first]) //goes through all ingredients from the q recipe
                                    if(k==p)
                                        intersection.insert(k);
                                if(check_alergen[j]==false){ // Special case for the first intersection
                                    for(auto& l:intersection)
                                        possible_alergens[j].insert(l);
                                    check_alergen[j]=true;
                                }
                                else
                                    for(auto& l:possible_alergens[j]){
                                        int exists=0;
                                        for(auto& r:intersection)
                                            if(l==r)
                                                exists=1;
                                        if(!exists)
                                            possible_alergens[j].erase(l);
                                    }
                        }

                    }

            }

        }
    }
    for(auto& i:possible_alergens)
        for(auto& j:i.second)
            counter.insert(j);
    int sol=0;
    for(auto& i:ingredients)
        for(auto& j:i.second)
            if(!counter.count(j))
                sol++;
    cout<<"Part 1: "<<sol<<endl;
    ///Part 2
    cout<<"Part 2: "<<endl;

    for(auto& i:possible_alergens){
        cout<<i.first<<": ";
        for(auto& j:i.second)
            cout<<j<<" ";
        cout<<endl;
    }
}

