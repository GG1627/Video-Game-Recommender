#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Similar.h"
#include "ParseData.h"
using namespace std;


int main(){
    ParseData op;
    op.ParseCSVFile();
    cout << "everything worked" << endl;

    // get user input
    string gameName;
    cout << "What game would you like to find?";
    getline(cin, gameName);

    // find the game
    bool gameFound = false;  // flag to see if game found

    for(size_t i=0; i < op.games.size(); i++){
        if(op.games[i].name == gameName){
            op.games[i].dispaly();
            gameFound = true;
            break;
        }
    }

    if (!gameFound) {
        cout << "Game not found." << endl;  // if game not found
    }

    Similar sim(op.games);

    vector<Game> similarGames = sim.extractGenre(gameName);  // Call the function to get similar games
    cout << "Size 1: "<< similarGames.size() << endl;
    similarGames = sim.extractPlatform(gameName, similarGames);  // Call the function to get similar games
    cout << "Size 2: "<< similarGames.size() << endl;

    cout << "Printing first 5 similar games" << endl;
    for(int p=0; p < 5; p++){
        similarGames[p].dispaly();
    }
}