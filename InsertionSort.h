#include <iostream>
#include <algorithm>

using namespace std;
// template <typename T>
// void insertionSort(T arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
//             swap(arr[j], arr[j - 1]);
//     }
//     return;
// }

//优化版插入排序，将交换变量改成赋值，减低时间复杂度。
template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T e = arr[i]; //先记录下当前值
        int j;
        //如果前一个值比当前值小，则把前值向后移
        for (j = i; j > 0 && arr[j - 1] > e; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = e; //将之前记录的当前值放入迭代结束的位置。
    }
}
//重载插入排序函数，在归并排序中使用该版本，可以优化归并排序,对arr[l..r]范围的数组进行排序
template <typename T>
void insertionSort(T arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}