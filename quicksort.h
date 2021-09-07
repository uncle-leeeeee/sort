#include <iostream>
#include <ctime>
using namespace std;

//对arr[l...r]进行partition分割操作
//返回p，使得arr[l..p-1]<arr[p]； arr[p+1..r]>arr[p]
template <typename T>
int partition(T arr[], int l, int r)
{
    //随机选择数列中的元素，并放置最左边位置
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int j = l;                       //小半区下标j从l开始，j指的是小半区最后一个元素
    for (int i = l + 1; i <= r; i++) //大半区下标从l+1开始，当所指元素小于基准值时就与j+1位置元素进行交换，i指的是大半区最后一个元素。
    {
        if (arr[i] < v)
        {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[l]); //把基准值调整到j的位置

    return j; //返回
}

//对arr[l...r]进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if (l >= r)
        return;

    int p = partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(NULL)); //生成随机种子
    __quickSort(arr, 0, n - 1);
}

//双路快速排序
template <typename T>
int __partition2(T arr[], int l, int r)
{
    //先在数列中随机选值，并放在最左边位置
    swap(arr[l], arr[rand() % (r - l + 1) + l]); //不要漏了加l
    T v = arr[l];
    int j = r;
    int i = l + 1;
    while (true)
    {
        //还需要判断i与j是否越界了，这里要注意是<而不是<=，当找到==arr[l]时，也需要进行交换防止任意半区过于臃肿
        while (i <= r && arr[i] < v)
            i++;
        while (j >= l + 1 && arr[j] > v)
            j--; //注意j--而不是j++
        if (i > j)
            break;
        swap(arr[i], arr[j]);
        //交换后下标需要更新
        i++;
        j--;
    }
    //此时j所在位置是数列中从左往右，最后一个<=arr[l]的元素，因此交换arr[l]与arr[j]的值
    swap(arr[j], arr[l]);
    return j; //返回j的位置。
}

template <typename T>
void __quickSort2(T arr[], int l, int r)
{
    if (r - l <= 15)
    {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p - 1);
    __quickSort2(arr, p + 1, r);
}

template <typename T>
void quickSort2(T arr[], int n)
{
    srand(time(NULL));
    __quickSort2(arr, 0, n);
}

//三路快排，将数列分为>,=,<部分；之后对>v,<v部分进行递归，这样的方法对于数列中有大量重复数字时效率明显提高
template <typename T>
void __quickSort3(T arr[], int l, int r)
{
    //若该数列范围小于15个，则进行插入排序
    if (r - l >= 15)
    {
        insertionSort(arr, l, r);
        return;
    }
    //随机规定基准值，进行partition
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    //初始化三个下标，这一步非常关键，个人认为是难点
    int lt = l;     //arr[l+1...lt]<v
    int gt = r + 1; //arr[gt...r]>v
    int i = l + 1;  //arr[lt+1...i)==v，左开右闭，这三个下标的初始化，都必须使三个集合为空
    while (i < gt)
    {
        if (arr[i] < v)
        {
            swap(arr[lt + 1], arr[i]); //交换i与<v集合部分的后一个元素
            lt++;
            i++; //记得更新下标
        }
        else if (arr[i] > v)
        {
            swap(arr[i], arr[gt - 1]); //交换i与>v集合部分的前一个元素
            lt++;
            i++;
        }
        else
        {
            i++;
        }
    }

    swap(arr[l], arr[lt]);        //交换l与<v最后一个元素
    __quickSort3(arr, l, lt - 1); //递归<v部分
    __quickSort3(arr, gt, r);     //递归>v部分
}

template <typename T>
void quickSort3(T arr[], int n)
{
    srand(time(NULL));
    __quickSort3(arr, 0, n - 1);
}
