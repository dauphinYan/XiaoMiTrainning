#include <iostream>
using namespace std;

int findMax(int *arr, int size)
{
    int max = *arr;
    for (int i = 0; i < size; i++)
    {
        max = *(arr + i) > max ? *(arr + i) : max;
    }
}

int main()
{
    int size = 5;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        int tmp;
        cin >> tmp;
        *(arr + i) = tmp;
    }

    cout<<"数组最大值为："<<findMax(arr,size)<<endl;

    delete arr;

    return 0;
}