#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
//使用newn一个新的变量优化冒泡排序,记住每一轮冒泡最后一次交换的位置，在后一轮冒泡中该下标后续的元素可以不考虑了。
void bubble_sort(T arr[], int n)
{
    int newn;
    do
    {
        newn = 0; //每轮冒泡前将该坐标标志初始化为0，若此变量没有发生变化，说明整个数列有序则退出循环。
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                newn = i;
            }
        }
        n = newn; //更新下一次的迭代范围
    } while (newn > 0);

    //对于完全有序的数列，优化后的冒泡排序和插入排序都是O(N)复杂度算法。
}