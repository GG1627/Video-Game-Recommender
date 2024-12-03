#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    cout << "What game would you like to find?" << endl;
    getline(cin, gameName);

    string gamePlatform;
    cout << "What platform is the game on?" << endl;
    getline(cin, gamePlatform);

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
    similarGames = sim.extractPlatform(gamePlatform, similarGames);  // Call the function to get similar games

    int selection = 0;
    cout << "Select 1 for a QuickSort, Select 2 for a CocktailSort." << endl;
    cin >> selection;

    auto start = std::chrono::high_resolution_clock::now();
    if (selection == 1) {
        algo.quickSortMetacritic(similarGames, 0 ,similarGames.size()-1);
    }
    else {
        algo.cocktailSort(similarGames, similarGames.size());
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    cout << "Printing first 5 similar games" << endl;

    // reverse the vector for in order printing
    reverse(similarGames.begin(), similarGames.end());
    for(int p=0; p < 5; p++){
            if(p==0){
                cout << "*******************  " << "1st  most similar game ->" << "  *******************" << endl;
                similarGames[p].dispaly();
            }
            else if(p==1){
                cout << "*******************  " << "2nd  most similar game ->" << "  *******************" << endl;
                similarGames[p].dispaly();
            }
            else if(p==2){
                cout << "*******************  " << "3rd  most similar game ->" << "  *******************" << endl;
                similarGames[p].dispaly();
            }
            else if(p==3){
                cout << "*******************  " << "4th  most similar game ->" << "  *******************" << endl;
                similarGames[p].dispaly();
            }
            else if(p==4){
                cout << "*******************  " << "5th  most similar game ->" << "  *******************" << endl;
                similarGames[p].dispaly();
            }
    }

    std::cout << "Elapsed time: " << elapsed.count() << " ms\n";
}
