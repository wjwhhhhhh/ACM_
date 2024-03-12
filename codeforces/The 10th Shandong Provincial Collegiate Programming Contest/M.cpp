#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k && n; i++)
    {
        if (n == 1)
            break;
        n = (n + 1) / 2;
    }
    cout << n << '\n';
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