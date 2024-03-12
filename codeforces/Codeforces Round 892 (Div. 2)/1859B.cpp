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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> get(n);
    vector<int> all(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int tr;
            cin >> tr;
            a[i].push_back(tr);
        }
        sort(a[i].begin(), a[i].end());
        get[i] = a[i][1];
        all[i] = a[i][0];
    }
    sort(all.begin(), all.end());
    sort(get.begin(), get.end());
    i64 ans = 0;
    for (int i = 1; i < n; i++)
        ans += get[i];
    ans += all[0];
    cout << ans << endl;
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