#include "Game.h"

class SortingAlgorithms {
public:
    void cocktailSort(vector<Game>& games, int size);
    void quickSort(vector<Game>& games, int low, int high);
    int partition(vector<Game>& games, int low, int high);
};
