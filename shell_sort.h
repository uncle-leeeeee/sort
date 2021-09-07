#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
void shell_sort(T arr[], int n)
{
    for (int k = n / 2; k > 0; k /= 2) //希尔增量序列
    {
        for (int i = k; i < n; i++)
        {                 //进行增量序列下的插入排序
            T e = arr[i]; //记录下当前选中数
            int j;
            for (j = i; j >= k && arr[j - k] > e; j -= k) //前面序列中每个数与当前选中数进行比较排序。
            {
                arr[j] = arr[j - k];
            }
            arr[j] = e;
        }
    }
}