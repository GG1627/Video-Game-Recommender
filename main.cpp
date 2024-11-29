#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
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
}
