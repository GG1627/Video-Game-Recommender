//
// Created by johnl on 12/1/2024.
//

#include "SortingAlgorithms.h"
#include <utility>
using namespace std;

void SortingAlgorithms::cocktailSort(vector<Game>& games, int size) {
    {
        bool swapped = true;
        int start = 0;
        int end = size - 1;

        while (swapped) {
            // reset the swapped flag on entering
            // the loop, because it might be true from
            // a previous iteration.
            swapped = false;

            // loop from left to right same as
            // the bubble sort
            for (int i = start; i < end; ++i) {
                if (games[i].metacritic > games[i + 1].metacritic) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            // if nothing moved, then array is sorted.
            if (!swapped)
                break;

            // otherwise, reset the swapped flag so that it
            // can be used in the next stage
            swapped = false;

            // move the end point back by one, because
            // item at the end is in its rightful spot
            --end;

            // from right to left, doing the
            // same comparison as in the previous stage
            for (int i = end - 1; i >= start; --i) {
                if (games[i].metacritic > games[i + 1].metacritic) {
                    swap(games[i], games[i + 1]);
                    swapped = true;
                }
            }

            // increase the starting point, because
            // the last stage would have moved the next
            // smallest number to its rightful spot.
            ++start;
        }
    }
};

void SortingAlgorithms::quickSort(vector<Game>& games, int low, int high) {
    if (low < high)
    {
        int pivot = partition(games, low, high);
        quickSort(games, low, pivot - 1);
        quickSort(games, pivot + 1, high);
    }
}


int SortingAlgorithms::partition(vector<Game>& games, int low, int high) {
    double pivot = games[low].metacritic;
    int up = low, down = high;

    while(up < down)
    {
        for (int j = up; j < high; j++)
        {
            if (games[up].metacritic > pivot)
                break;
            up++;
        }
        for (int j = high; j > low; j--) {
            if(games[down].metacritic < pivot)
                break;
            down--;
        }
        if (up < down)
            swap(games[up], games[down]);
    }
    swap(games[low], games[down]);
    return down;
}
