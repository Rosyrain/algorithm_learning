
/*
手把手带你撕出正确的二分法 | 二分查找法 | 二分搜索法 | LeetCode：704. 1.二分查找
*/

/*
确定区间定义 ： 左闭右闭（包含两个端点）
*/

#include<iostream>
using namespace std;
#define NUMBERSIZE 0;//假设数组固定长所需长度定义

int Search(int* arr, int numsize ,int target)
{
    int left = 0, right = numsize - 1;
    int middle;

    //确保区间的合法性 根据开局的定义 左闭右闭 [1,1]，如果等于是合法的
    while (left <= right)
    {
        middle = (left + right) / 2;

        if (arr[middle] > target)
        {
            right = middle - 1;//因为定义的区间是左闭右闭，arr[middle]的值已经不满足条件
            //所以下一个区间的值不需要包含它，因此right = middle-1;
        }
        else if (arr[middle] < target)
        {
            left = middle + 1;//+1原因和上面相同
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