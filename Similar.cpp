#include "Similar.h"

vector<Game> Similar::extractGenre(const string &gameName) {
    vector<Game> filteredGames;
    unordered_set<string> targetGenres = getGenres(gameName);

    for (int i = 0; i < gamesRef.size(); i++) {
        unordered_set<string> currentGameGenres = getGenres(gamesRef[i].name);

        for (auto it = currentGameGenres.begin(); it != currentGameGenres.end(); ++it) {
            if (targetGenres.find(*it) != targetGenres.end()) {
                filteredGames.push_back(gamesRef[i]);
                break;
            }
        }
    }

    return filteredGames;
}


vector<Game> Similar::extractPlatform(const string &gameName, vector<Game> filteredGames) {
    vector<Game> finalFilteredGames;
    unordered_set<string> targetPlatforms = getPlatforms(gameName);

    for (int i = 0; i < filteredGames.size(); i++) {
        unordered_set<string> currentGamePlatforms = getPlatforms(filteredGames[i].name);

        for (auto it = currentGamePlatforms.begin(); it != currentGamePlatforms.end(); ++it) {
            if (targetPlatforms.find(*it) != targetPlatforms.end()) {
                finalFilteredGames.push_back(filteredGames[i]);
                break;
            }
        }
    }

    return finalFilteredGames;
}


