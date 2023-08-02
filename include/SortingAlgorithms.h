#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
#include "Bar.h"
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstddef>
#pragma once

struct SortingAlgorithms
{
    int* ptrSortingDelay = nullptr;

    void bubbleSort( std::vector<Bar>& bars, bool& isSorting );
    void insertionSort( std::vector<Bar>& bars, bool& isSorting );
    void selectionSort( std::vector<Bar>& bars, bool& isSorting );

    void setSortDelay(int& delay);
};

#endif // !SORTINGALGORITHMS_H
