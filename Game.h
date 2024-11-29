#ifndef VIDEO_GAME_RECOMMENDER_GAME_H
#define VIDEO_GAME_RECOMMENDER_GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Game{
    public:
        string name;
        string metacritic;
        string rating;
        vector<string> gameGenres;

    Game(const string& name,double metacritic, double rating, const vector<string>& gameGenres){
            this->name = name;
            this->metacritic = to_string(metacritic);
            this->rating = to_string(rating);
            this->gameGenres = gameGenres;
        }

    void dispaly() const{
        cout << "Name: " << name << endl;
        cout << "Metacritic: " << metacritic << endl;
        cout << "Rating: " << rating << endl;
    }
};

#endif //VIDEO_GAME_RECOMMENDER_GAME_H
