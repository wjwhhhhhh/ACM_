#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n * 4 - n; i++)
    {
        for (int i = 0; i < n; i++)
            cout << "*";
        for (int i = 0; i < 2 * n; i++)
            cout << ".";
        for (int i = 0; i < n; i++)
            cout << "*";
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << ".";
        for (int j = 0; j < n; j++)
            cout << "*";
        for (int j = 0; j < 2 * n - 2 * i; j++)
            cout << ".";
        for (int j = 0; j < n; j++)
            cout << "*";
        for (int j = 0; j < i; j++)
            cout << ".";
        cout << '\n';
    }
    return 0;
}