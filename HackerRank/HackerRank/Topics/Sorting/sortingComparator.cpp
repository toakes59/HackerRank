#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if(a.score<b.score){
            return -1;
        }
        else if(a.score==b.score){
			//slow way of comparing strings
            /*for(int i=0; i<a.name.size();i++){
                if(a.name.at(i)>b.name.at(i)){
                    return -1;
                }
                else if(a.name.at(i)<b.name.at(i)){
                    return 1;
                }
            }*/
            if(a.name>b.name){
                return -1;
            }
            else if(a.name<b.name){
                return 1;
            }
            return 0;
        }
        return 1;
    }
};



bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}