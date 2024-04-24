#include <iostream>
using namespace std;

class T
{
public:
    int add(int a, int b)
    {
        cout << "和为：" << a + b << endl;
        return a + b;
    }
};

int add(int a, int b)
{
    cout << "和为：" << a + b << endl;
    return a + b;
}

int main()
{
    int (T::*ptr)(int, int) = &T::add;
    T t;
    (t.*ptr)(10, 200);

    int (*pt)(int, int) = add;
    pt(10, 20);
    return 0;
}
