#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    i64 a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        a += tem;
    }
    for (int i = 0; i < m; i++)
    {
        int tem;
        cin >> tem;
        b += tem;
    }
    if (a > b)
        cout << "Tsondu" << '\n';
    else if (a == b)
        cout << "Draw" << '\n';
    else
        cout << "Tenzing" << '\n';
    ;
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