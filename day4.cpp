#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("aoc4.in");
string x;
int byr,iyr,eyr,hgt,hcl,ecl,pid,cid,valid,timer=9999;
int vbyr,viyr,veyr,vhgt,vhcl,vecl,vpid;
bool checkcolor(char x){
    if(x<'a'||x>'f')
        return 0;
    return 1;
}
int main(){
    while(timer--){
        getline(fin,x);
        if(x.find("byr")!=string::npos){
            byr++;
            for(int i=x.find("byr")+4;isdigit(x[i]);i++)
                vbyr=vbyr*10+(x[i]-'0');
            if(vbyr<1920||vbyr>2002)
                byr=0;
        }
        if(x.find("iyr")!=string::npos){
            iyr++;
            for(int i=x.find("iyr")+4;isdigit(x[i]);i++)
                viyr=viyr*10+(x[i]-'0');
            if(viyr<2010||viyr>2020)
                iyr=0;
        }
        if(x.find("eyr")!=string::npos){
            eyr++;
            for(int i=x.find("eyr")+4;isdigit(x[i]);i++)
                veyr=veyr*10+(x[i]-'0');

            if(veyr<2020||veyr>2030)
                eyr=0;
        }
        if(x.find("hgt")!=string::npos){
            hgt++;
            char unit;
            for(int i=x.find("hgt")+4;isdigit(x[i]);i++){
                vhgt=vhgt*10+(x[i]-'0');
                unit=x[i+1];
            }
            if(unit=='c')
                if(vhgt<150||vhgt>193)
                    hgt=0;
            if(unit=='i')
                if(vhgt<59||vhgt>76)
                    hgt=0;
            if(unit!='i'&&unit!='c')
                hgt=0;
        }
        if(x.find("hcl")!=string::npos){
            hcl++;
            if(x[x.find("hcl")+4]!='#')
                hcl=0;
            int digits=0,chars=0;
            for(int i=x.find("hcl")+5;;i++){
                if(isdigit(x[i]))
                   digits++;
                else
                    if(checkcolor(x[i]))
                        chars++;
                    else
                        break;
            }
            if(digits+chars!=6)
                hcl=0;
        }
        if(x.find("ecl")!=string::npos){
            ecl++;
            if(x.find("amb")==string::npos&&x.find("blu")==string::npos&&x.find("brn")==string::npos&&x.find("gry")==string::npos&&x.find("grn")==string::npos&&x.find("hzl")==string::npos&&x.find("oth")==string::npos)
                ecl=0;
        }
        if(x.find("pid")!=string::npos){
            pid++;
            int digits=0;
            for(int i=x.find("pid")+4;isdigit(x[i]);i++)
                digits++;
            if(digits!=9)
                pid=0;
        }
        if(x.find("cid")!=string::npos)
            cid++;
        if(x.empty()){
            if(byr&&iyr&&eyr&&hgt&&hcl&&ecl&&pid)
                valid++;
            byr=0,iyr=0,eyr=0,hgt=0,hcl=0,ecl=0,pid=0,cid=0;
            vbyr=0,viyr=0,veyr=0,vhgt=0,vhcl=0,vecl=0,vpid=0;
        }
        if(x.find("812583062")!=string::npos)
            timer=1;
    }
    cout<<valid;
}
/*
byr (Birth Year)                 1
iyr (Issue Year)                 2
eyr (Expiration Year)            3
hgt (Height)                     4
hcl (Hair Color)                 5
ecl (Eye Color)                  6
pid (Passport ID)                7
cid (Country ID)                 8
*/
