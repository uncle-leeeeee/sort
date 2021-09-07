#include <iostream>
#include "InsertionSort.h"
using namespace std;

//定义归并函数，将arr[l,mid]与arr[mid+1,r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
    //首先开辟一个辅助数组，将[l,r]范围元素放入，元素个数为l-r+1
    T aux[r - l + 1];
    for (int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i]; //一一赋值到辅助数组
    }

    int i = l;
    int j = mid + 1; //获取左右半区的第一个元素下标
    for (int k = l; k <= r; k++)
    {
        //先判断左右半区下标是否有越界，若越界了，证明该半区已经排好了，只需要排另一半区
        if (i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        //再判断哪个半区的元素较小，赋值到arr对应位置
        else if (aux[i - l] < aux[j - l])
        {
            arr[k] = aux[i - l];
            i++;
        }
        else
        {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

//递归使用归并排序，对arr[l....r]的范围进行排序。
template <typename T>
void __mergeSort(T arr[], int l, int r)
{
    //返回边界
    // if (l >= r)
    //     return;

    //如果需要排序的范围较小时，插入排序效率更高。
    if (r - l <= 15)
    {
        insertionSort(arr, l, r); //在此处需要include"insetionSort.h"头文件，而在main.cpp则无需再包含，否则会报错。
        return;
    }

    int mid = (l + r) / 2; //l+r值也有可能过大产生越界情况，这里暂时不作考虑
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    //第一步优化，当mid下标元素大于于mid+1元素时，才需要进行归并。
    if (arr[mid] > arr[mid + 1])
    {
        __merge(arr, l, mid, r); //归并函数，提供左，中，右下标
    }
}

//用户调用的归并排序函数
template <typename T>
void mergeSort(T arr[], int n)
{
    //实际系统调用的函数
    __mergeSort(arr, 0, n - 1); //左闭右闭区间。
}
//自底向上进行归并排序
template <typename T>
void mergeSortBU(T arr[], int n)
{
    //子集大小从1开始进行归并，每次size增加一倍
    for (int sz = 1; sz < n; sz += sz)
    {
        for (int i = 0; i + sz < n; i += sz + sz) //要避免越界，当i+sz<n时，证明左半区存在
        {
            if (arr[i + sz - 1] > arr[i + sz])                            //当mid下标元素大于左半区第一个元素时，才需要进行归并。
                __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1)); //i+sz+sz-1有可能会越界，所以需要在n-1之间取最小值。
        }
    }
}