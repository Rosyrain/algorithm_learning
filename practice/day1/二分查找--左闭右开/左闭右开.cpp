
/*
手把手带你撕出正确的二分法 | 二分查找法 | 二分搜索法 | LeetCode：704. 二分查找
*/

/*
确定区间定义 ： 左闭右开（包含左端点，不包含右端点）
*/

#include<iostream>
using namespace std;
#define NUMBERSIZE 0;//假设数组固定长所需长度定义

int Search(int* arr, int numsize ,int target)
{
    int left = 0, right = numsize ;//注意，此处由于是右开的，要包含最右边的值，所以right = numsize;
    int middle;

    //确保区间的合法性 根据开局的定义 左闭右开 [1,1)，如果等于是合法的
    while (left < right)
    {
        middle = (left + right) / 2;

        if (arr[middle] > target)
        {
            right = middle;//因为定义的区间是左闭右开，arr[middle]的值已经不满足条件
            //下一个区间是右开的，可以包含它，因此right = middle;
        }
        else if (arr[middle] < target)
        {
            left = middle + 1;//因为定义的区间是左闭右开，arr[middle]的值已经不满足条件
            //所以下一个区间是左闭的，不需要包含它，因此left = middle-1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

int main() {
    int numsize;
    int target;
    int result;

    cout << "请输入数组大小：";
    cin >> numsize;

    int* arr = new int[numsize];

    cout << "请输入数组元素：";
    for (int i = 0; i < numsize; i++)
    {
        cin >> arr[i];
    }
    cout << "请输入目标元素：";
    cin >> target;

    result = Search(arr , numsize , target);

    if (result == -1)
    {
        cout << "数组中不包含该目标值";
    }
    else
    {
        cout << "目标值对于数组下标：" << result << endl;
    }

    system("pause");
    return 0;
}