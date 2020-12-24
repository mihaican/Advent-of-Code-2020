#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("day22.in");
string read,selector;
int x;
deque<int> player1,player2,winner;
int game=1;
int rounds;
int combat(deque <int> player1, deque <int> player2,int no){
    vector <deque <int> > hands_played1, hands_played2;
    while(player1.size()!=0&&player2.size()!=0){
        rounds++;
        int round_win=0;
        //------------------------------------------------
        cout<<endl<<"-------------GAME:"<<no<<"-------------"<<endl;
        cout<<"Player 1's deck:"<<endl;
        for(auto& i:player1)
            cout<<i<<" ";
        cout<<endl<<"Player 2's deck:"<<endl;
        for(auto& i:player2)
            cout<<i<<" ";
        cout<<endl;
        //------------------------------------------------
        int card1=player1.front();
        int card2=player2.front();
        for(auto& i:hands_played1)
            if(i==player1)
                round_win=1;
        hands_played1.push_back(player1);
        for(auto& i:hands_played2)
            if(i==player2)
                round_win=1;
        hands_played2.push_back(player2);
        player1.pop_front();
        player2.pop_front();
         if(card1<=player1.size()&&card2<=player2.size()&&!round_win){
            deque <int> new_deck1,new_deck2,aux1=player1,aux2=player2;
            for(int i=1;i<=card1;i++){
                new_deck1.push_back(player1.front());
                player1.pop_front();
            }
            for(int i=1;i<=card2;i++){
                new_deck2.push_back(player2.front());
                player2.pop_front();
            }
            round_win=combat(new_deck1,new_deck2,++game);
            player1=aux1;
            player2=aux2;
        }
        if(!round_win){
            if(card1>card2){
                player1.push_back(card1);
                player1.push_back(card2);
            }
            if(card2>card1){
                player2.push_back(card2);
                player2.push_back(card1);
            }
        }
        else{
            if(round_win==1){
                player1.push_back(card1);
                player1.push_back(card2);
            }
            if(round_win==2){
                player2.push_back(card2);
                player2.push_back(card1);
            }
        }
        if(player1.size()==0){
            winner=player2;
            return 2;
        }
        if(player2.size()==0){
            winner=player1;
            return 1;
        }
    }
}
int main(){
    while(getline(fin,read)){
        if(read=="Player 1:")
            selector=read;
        if(read=="Player 2:")
            selector=read;
        if(isdigit(read[0]))
            if(selector=="Player 1:")
                player1.push_back(stoi(read));
            else
                player2.push_back(stoi(read));
    }
    combat(player1,player2,game);
    long long score=0;
    for(auto& i:winner){
        score+=i*winner.size();
        winner.pop_front();
        cout<<i<<" ";
    }
    cout<<endl<<score;
}
/// Part 1
/*#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("day22.in");
string read,selector;
int x;
deque<int> player1,player2,winner;
int rounds;
int main(){
    while(getline(fin,read)){
        if(read=="Player 1:")
            selector=read;
        if(read=="Player 2:")
            selector=read;
        if(isdigit(read[0]))
            if(selector=="Player 1:")
                player1.push_back(stoi(read));
            else
                player2.push_back(stoi(read));
    }
    while(player1.size()!=0&&player2.size()!=0){
        rounds++;
        int card1=player1.front();
        int card2=player2.front();
        player1.pop_front();
        player2.pop_front();
        if(card1>card2){
            player1.push_back(card1);
            player1.push_back(card2);
        }
        if(card2>card1){
            player2.push_back(card2);
            player2.push_back(card1);
        }
    }
    winner=player1.size()>player2.size()?player1:player2;
    long long score=0;
    for(auto&i:winner){
        score+=i*(winner.size());
        winner.pop_front();
    }
    cout<<score;
}
*/
