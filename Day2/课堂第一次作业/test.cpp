#include <iostream>
#include <math.h>
using namespace std;

void getMax(int a, int b, int c)
{
    int max = a;
    if (max <= b)
        max = b;
    if (max <= c)
        max = c;
    cout << max << endl;
}

void getValue(int a, int b, int c)
{
    double dt = pow(b, 2) - 4 * a * c;
    if (dt >= 0)
    {
        int x, y;
        x = (-b-sqrt(dt))/(2*a);
        y = (-b+sqrt(dt))/(2*a);
        cout<<"方程解为："<<x<<" "<<y<<endl;
    }
    else
    {
        cout<<"此方程无解"<<endl;
    }
}

int main()
{
    getMax(1,3,2);
    getValue(1,2,2);
    getValue(1,-1,-2);
    return 0;
}