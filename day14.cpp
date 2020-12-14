/*#include <bits/stdc++.h>
using namespace std;
ifstream fin("aoc14.in");
long long len,value,sum;
long long mem[70000];
string type,sgn;
pair<int,bool> mask[40];
int main(){
    while(fin>>type){
        if(type.find("mask")!=string::npos){
            memset(mask,35,0);
            fin>>sgn>>type;
            len=1;
            for(int i=0;i<type.size();i++)
                    if(type[i]!='X')
                        mask[len].first=36-i-1,mask[len++].second=type[i]-'0';
        }
        if(type.find("mem")!=string::npos){
            fin>>sgn>>value;
            int adress=0;
            for(int i=0;i<type.size();i++)
                if(isdigit(type[i]))
                    adress=adress*10+type[i]-'0';
            for(int i=1;i<len;i++)
                if(mask[i].second==1)
                    value=(value | (1LL<<mask[i].first));
                else
                    value=(value &~(1LL<<mask[i].first));
            mem[adress]=value;
        }

    }
    for(int i=0;i<70000;i++)
        sum+=mem[i];
    cout<<sum;
}

*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin("aoc14.in");
long long len,value,sum,cnt;
map<long long,long long> mem;
string type,sgn;
pair<int,int> mask[40];
int main(){
    while(fin>>type){
        if(type.find("mask")!=string::npos){
            memset(mask,35,0);
            fin>>sgn>>type;
            len=1;
            cnt=0;
            for(int i=0;i<type.size();i++){
                    if(type[i]=='1')
                        mask[len].first=36-i-1,mask[len++].second=type[i]-'0';
                    if(type[i]=='X')
                        mask[len].first=36-i-1,mask[len++].second=-1,cnt++;
            }
        }
        if(type.find("mem")!=string::npos){
            fin>>sgn>>value;
            long long adress=0;
            for(int i=0;i<type.size();i++)
                if(isdigit(type[i]))
                    adress=adress*10+type[i]-'0';
            for(int i=1;i<len;i++){
                if(mask[i].second==1)
                    adress=(adress | (1LL<<mask[i].first));
                if(mask[i].second==-1)
                    adress=(adress &~(1LL<<mask[i].first));
            }
            long long next;
            long long aux=adress;
            mem.insert(make_pair(aux,value));
            for(int i=1;i<=pow(2,cnt)-1;i++){
                int pos=0;
                next=0;
                for(int j=len-1;j>0;j--)
                    if(mask[j].second==-1){
                        int bit=0;
                        bit=(i>>pos)&1;
                        if(bit)
                            next |= (1LL<<mask[j].first);
                        pos++;
                    }
                aux=adress+next;
                if(mem.count(aux)==1)
                    mem.erase(aux);
                mem.insert(make_pair(aux,value));

            }
            mem[adress]=value;
        }

    }
         for (auto itr = mem.begin(); itr != mem.end(); ++itr) {
                sum+=itr->second;
    }
    cout<<sum;
}
