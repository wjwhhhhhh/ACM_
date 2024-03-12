#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    string lu = "LRUD";
    map<char, int> get;
    for (int i = 0; i < 4; i++)
        get[lu[i]] = i;
    i64 x = 0, y = 0;
    vector<i64> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        x += dx[get[a[i]]], y += dy[get[a[i]]];
        l[i] = x, r[i] = y;
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(l[i]) + abs(r[i]));
        ans = max(ans, abs(l[i] + (k - 1) * x) + abs(r[i] + (k - 1) * y));
    }
    cout << ans << '\n';
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