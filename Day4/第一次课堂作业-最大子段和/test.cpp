#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, a[200001], f[200001][4][2], ans1, ans2;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 128, sizeof(f));
    f[1][1][1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        f[i][1][0] = max(f[i - 1][1][0], f[i - 1][1][1]);
        f[i][1][1] = max(f[i - 1][1][1], 0) + a[i];
        f[i][2][0] = max(f[i - 1][2][0], f[i - 1][2][1]);
        f[i][2][1] = max(f[i - 1][1][0], max(f[i - 1][1][1], f[i - 1][2][1])) + a[i];
    }
    ans1 = max(f[n][2][0], f[n][2][1]);
    memset(f, 128, sizeof(f));
    f[1][1][1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        f[i][1][0] = max(f[i - 1][1][0], f[i - 1][1][1]);
        f[i][1][1] = f[i - 1][1][1] + a[i];
        f[i][2][0] = max(f[i - 1][2][0], f[i - 1][2][1]);
        f[i][2][1] = max(f[i - 1][1][0], max(f[i - 1][1][1], f[i - 1][2][1])) + a[i];
        f[i][3][0] = max(f[i - 1][3][0], f[i - 1][3][1]);
        f[i][3][1] = max(f[i - 1][2][0], max(f[i - 1][2][1], f[i - 1][3][1])) + a[i];
    }
    ans2 = f[n][3][1];
    cout << max(ans1, ans2) << endl;
}