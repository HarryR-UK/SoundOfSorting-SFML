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
    void bubbleSort( std::vector<Bar>& bars, int sortDelay, bool& isSorting );
    void insertionSort( std::vector<Bar>& bars, int sortDelay, bool& isSorting );
    void selectionSort( std::vector<Bar>& bars, int sortDelay, bool& isSorting );
};

#endif // !SORTINGALGORITHMS_H
