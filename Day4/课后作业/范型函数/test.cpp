#include <iostream>
using namespace std;

template <typename T>
void swapV(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{

    int a = 1, b = 2;

    swapV(a, b);

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    return 0;
}
