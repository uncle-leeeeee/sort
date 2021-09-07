#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "MergeSort.h"
#include "quickSort.h"

using namespace std;

// 比较各种排序算法的性能效率
int main()
{

    int n = 50000;

    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    // int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10); //生成接近有序的数列，在这样情况下插入排序会接近O(n)的实践复杂度。
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n); //复制相同的数列来跑其他排序算法
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int *arr6 = SortTestHelper::copyIntArray(arr1, n);
    int *arr7 = SortTestHelper::copyIntArray(arr1, n);
    int *arr8 = SortTestHelper::copyIntArray(arr1, n);
    int *arr9 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Selection Sort", selection_sort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubble_sort, arr3, n);
    SortTestHelper::testSort("shell sort", shell_sort, arr4, n);
    SortTestHelper::testSort("merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("merge Sort BU", mergeSortBU, arr6, n);
    SortTestHelper::testSort("quickSort", quickSort, arr7, n);
    SortTestHelper::testSort("quickSort2", quickSort2, arr8, n);
    SortTestHelper::testSort("quickSort3", quickSort3, arr9, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;

    return 0;
}