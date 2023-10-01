#include "iostream"
using namespace std;
/*
 1.定义一个新数组，用于储存平方后的元素
 2.定义两个指针，分别位于旧数组的两头
 3.每次对两头先做平方处理
 4.比较大小，如果是left>right 那么就将改元素存入新数组，然后left++  ，反之取right的元素，right--

 */

void square(int *arr,int *new_arr,int numsize)
{
    int k=numsize-1;//这个k表示新数组最右边的元素

    for(int left=0,right=numsize-1;left <= right;)//left <= right而不善 < 的原因是，当left=right时,这个元素要存入新数组，如果不等则无法保存该元素
    {

        if(arr[left]*arr[left] > arr[right]*arr[right])
        {
            new_arr[k--] = arr[left]*arr[left];
            left ++;
        }
        else
        {
            new_arr[k--] = arr[right]*arr[right];
            right --;
        }
    }
}

int main(){
    int arr[4]={-5,1,2,3};
    int numsize = sizeof(arr)/sizeof(arr[0]);
    int  new_arr[numsize];
    square(arr,new_arr,numsize);
    for(int i = 0 ; i < numsize ; i++)
    {
        cout << new_arr[i] << ' ';
    }

    return 0;
}

