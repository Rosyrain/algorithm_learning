#include "iostream"
using namespace std;
#define N 10

int Get_small_array(int *a,int target)
{
    int result = N+1,i=0,sum = 0 , length = 0;
    int j;
    for(j=0;j<N;j++)
    {
        sum += *(a+j);

        while (sum > target)
        {
            length = j-i+1;
            result = min(result,length);
            sum -= a[i];
            i++;
        }
    }
    return result == N+1 ? 0:result;
}

int main()
{
    int a[N];
    int target;
    int result;
    for(int i = 0;i<N;i++)
    {
        cout << "请输入第" << i+1 <<"个元素: ";
        cin >> a[i];
        cout << endl;
    }

    cout << "请输入比较和：";
    cin >> target;

    result = Get_small_array(a,target);
    cout << result;
}