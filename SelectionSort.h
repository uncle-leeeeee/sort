#ifndef INSERTIONSORT_SELECTIONSORT_H
#define INSERTIONSORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
void selection_sort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) //应该是与minIndex判断
            {
                minIndex = j; //更新minIndex
            }
        }
        swap(arr[i], arr[minIndex]); //最后交换
    }
}
#endif