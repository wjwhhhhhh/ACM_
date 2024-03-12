#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<i64> huo(n + 2), a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    i64 res = 0;
    for (int i = n; i > 0; i--)
    {
        res += a[i];
        huo[i] = max(res, huo[i + 1]);
    }
    res = 0;
    i64 ans = 0, id = 0;
    for (int i = 0; i <= n; i++)
    {
        res += a[i];
        if (ans < res + huo[i + 1])
        {
            ans = res + huo[i + 1];
            id = res;
        }
    }
    cout << id << endl;
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