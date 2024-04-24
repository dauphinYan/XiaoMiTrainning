#include <iostream>
using namespace std;

int main()
{
    int data[3][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}};

    int *p[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *(*(p + i) + j) = &data[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << **(*(p + i) + j) << " ";
        }
    }

    return 0;
}