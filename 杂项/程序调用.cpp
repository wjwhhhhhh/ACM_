#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    i64 ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]] = i;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        // cout << b[i];
        ans += mp[b[i]] / k + 1;
        if (mp[b[i]] == 0)
            continue;
        int id = mp[b[i]];
        swap(a[id], a[id - 1]);
        mp[a[id]] = id, mp[a[id - 1]] = id - 1;
    }
    cout << ans << endl;
    return 0;
}