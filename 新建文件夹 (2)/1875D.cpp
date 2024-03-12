#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> has;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        has.insert(a[i]);
    int idx = 0;
    while (has.find(idx) != has.end())
    {
        idx++;
    }
    vector<i64> mp(idx), f(idx + 1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < idx)
            mp[a[i]]++;
    }
    // cout << idx << endl;
    for (int i = idx - 1; i >= 0; i--)
    {
        i64 ans = 0x3f3f3f3f;
        for (int j = i + 1; j <= idx; j++)
        {
            chmin(ans, 1ll * (mp[i] - 1) * j + f[j] + i);
        }
        // cout << mp[i] << endl;
        f[i] = ans;
    }
    cout << f[0] << endl;
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