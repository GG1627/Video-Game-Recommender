#include "Game.h"

class SortingAlgorithms {
public:
    // main sorting algorithms
    void cocktailSort(vector<Game>& games, int size);
    void quickSortMetacritic(vector<Game>& games, int low, int high);
    int partitionMetacritic(vector<Game>& games, int low, int high);

    // optional sorting algorithms
    void quickSortAchievmentCount(vector<Game>& games, int low, int high);
    int partitionAchievmentCount(vector<Game>& games, int low, int high);

    void quickSortPublishers(vector<Game>& games, int low, int high);  // not really sorting just take out of vector and reinsert at end FIX
    int partitionPublishers(vector<Game>& games, int low, int high);
};
