#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("aoc25.in");
long long public_key_card,public_key_door;
long long initial_card=6,subject_card=9,initial_door=1,subject_door=9,loop_size_card,loop_size_door;
long long encryption_key;
int main(){
    fin>>public_key_card>>public_key_door;
    for(int i=2;initial_card!=public_key_card;i++){   ///finding the subject and loop size of the card
        subject_card=i;
        initial_card=1;
        loop_size_card=0;
        while(initial_card!=public_key_card&&loop_size_card<=100000000){
            loop_size_card++;
            initial_card*=subject_card;
            initial_card%=20201227;
        }
    }
    ///finding the subject and loop size of the door
        subject_door=subject_card;
        while(initial_door!=public_key_door&&loop_size_door<=100000000){
            loop_size_door++;
            initial_door*=subject_door;
            initial_door%=20201227;
        }
    encryption_key=public_key_door;
    for(int i=1;i<loop_size_card;i++){
        encryption_key*=public_key_door;
        encryption_key%=20201227;
    }
    cout<<encryption_key<<endl;
    cout<<initial_card<<" "<<subject_card<<" "<<loop_size_card<<endl;
    cout<<initial_door<<" "<<subject_door<<" "<<loop_size_door<<endl;

}
