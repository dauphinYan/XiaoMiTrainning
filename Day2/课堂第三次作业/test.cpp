#include <iostream>
using namespace std;

int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

int getMaxThree(int a, int b, int c)
{
    return (a > getMax(b, c)) ? a : getMax(b,c);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout<<getMaxThree(a,b,c)<<endl;
    return 0;
}