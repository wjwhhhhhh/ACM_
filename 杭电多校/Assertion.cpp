#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    i64 n, m, k;
    cin >> n >> m >> k;
    if (n * (k - 1) <= m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}