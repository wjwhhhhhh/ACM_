#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> has, ing;
    int last = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        last ^= a[i];
        ans = max(ans, last);
        has.insert(last);
    }
    last = 0;
    for (int i = 0; i < n; i++)
    {
        last ^= a[i];
        last = max(ans, last);
    }
    for (auto x : has)
    {
        for (auto j : has)
        {
            ans = max(ans, x ^ j);
        }
    }
    cout << ans << endl;
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