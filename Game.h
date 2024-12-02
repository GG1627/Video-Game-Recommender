#ifndef VIDEO_GAME_RECOMMENDER_GAME_H
#define VIDEO_GAME_RECOMMENDER_GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;

class Game{
    public:
        string name;
        int metacritic;
        double rating;
        unordered_set<string> gameGenres;
        unordered_set<string> gamePlatforms;

    Game(const string& name,double metacritic, double rating, const unordered_set<string>& gameGenres, const unordered_set<string>& gamePlatforms){
            this->name = name;
            this->metacritic = metacritic;
            this->rating = rating;
            this->gameGenres = gameGenres;
            this->gamePlatforms = gamePlatforms;
        }

    void dispaly() const{
        cout << "Name: " << name << endl;
        cout << "Metacritic: " << metacritic << endl;
        cout << "Rating: " << rating << endl;
        cout << "----------GENRES----------" << endl;
        for(auto it : gameGenres){
            cout << it << endl;
        }
        cout << "----------PLATFORMS----------" << endl;
        for(auto it : gamePlatforms){
            cout << it << endl;
        }
    }
};

#endif //VIDEO_GAME_RECOMMENDER_GAME_H
