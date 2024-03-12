#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    int one, two;
    if (x == 1)
        one = 2;
    else
        one = 1;
    if (one + 1 == x)
        two = one + 2;
    else
        two = one + 1;
    if (one > k)
    {
        cout << "NO" << endl;
        return;
    }
    if (one == 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << "1 ";
        cout << endl;
        return;
    }
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (n & 1)
    {
        if (two > k)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << n / 2 << endl;
        for (int i = 1; i < n / 2; i++)
            cout << "2 ";
        cout << "3 ";
        cout << endl;
        return ;
    }
    cout << "YES" << endl;
    cout << n / 2 << endl;
    for (int i = 1; i <= n / 2; i++)
        cout << "2 ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}