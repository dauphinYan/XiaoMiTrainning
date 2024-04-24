#include <iostream>
using namespace std;

void addValue(int n)
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
        cout << "当前sum：" << sum << endl;
    }
    cout << "前" << n << "和为：" << sum << endl;
}

void calculator(long double a, string str, long double b)
{
    long double value;
    if (str == "+")
    {
        value = a + b;
        cout << "计算结果为：" << value << endl;
        return;
    }
    if (str == "-")
    {
        value = a - b;
        cout << "计算结果为：" << value << endl;
        return;
    }
    if (str == "*")
    {
        value = a * b;
        cout << "计算结果为：" << value << endl;
        return;
    }
    if (str == "/")
    {
        if (b != 0)
        {
            value = a / b;
            cout << "计算结果为：" << value << endl;
            return;
        }
        else
        {
            cout << "除数错误！" << endl;
            return;
        }
    }
    cout<<"操作符错误。"<<endl;
}

int main()
{
    // addValue(100);

    while (1)
    {
        long double a, b;
        string str;
        cin >> a >> str >> b;
        calculator(a, str, b);
        cout << "是否继续计算？Y/N" << endl;
        char j;
        cin >> j;
        if (j == 'N')
            return 0;
    }

    return 0;
}