//两个指针去实现数组删除
//1.定义两个指针，fast和slow
//2.快指针用于去确定新数组所需要的元素
//3.慢指针用于确定新数组需要更改的下标
//例如：[1,2,3,4,5]删除3,当fast = 1,2时，是需要的元素，那么更新数组slow代表的下标也自然更新+1。
//当 fast=3时，不是新数组需要的元素，则slow任然 = 3,当fast=4时，在更新数组元素后，slow+1,更新下一个需要更新的位置

#include <iostream>
using namespace std;

int *delete_num(int arr[],int numsize,int target)
{
    int slow = 0;
    for(int fast = 0 ; fast < numsize ; fast++)
    {
        if(arr[fast] != target)
        {
            arr[slow] = arr[fast];
            slow ++;
        }
    }

}

int main(){
    int arr[5] = {1,2,3,4,5};
    int numsize = 5;
    int target;
    cout <<"请输入想要删除的元素" ;
    cin >> target;
    delete_num(arr,numsize,target);
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << arr[i];
    }
    return 0;
}

