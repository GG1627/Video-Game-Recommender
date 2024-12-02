#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Similar.h"
#include "ParseData.h"
#include "SortingAlgorithms.h"
#include <chrono>

using namespace std;


int main(){
    ParseData op;
    SortingAlgorithms algo;
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
    similarGames = sim.extractPlatform(gameName, similarGames);  // Call the function to get similar games

    int selection = 0;
    cout << "Select 1 for a QuickSort, Select 2 for a CocktailSort." << endl;
    cin >> selection;

    auto start = std::chrono::high_resolution_clock::now();
    if (selection == 1) {
        algo.quickSort(similarGames, 0 ,similarGames.size()-1);
    }
    else {
        algo.cocktailSort(similarGames, similarGames.size());
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Printing first 5 similar games" << endl;
    for(int p=similarGames.size()-1; p > similarGames.size()-6 ; p--){
        similarGames[p].dispaly();
    }

    std::cout << "Elapsed time: " << elapsed.count() << " ms\n";
}