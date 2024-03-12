#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int tem;
            cin >> tem;
            a[i].push_back(tem);
        }
    }
    int m;
    cin >> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        chmax(ans, a[i][min(m - 1, (int)a[i].size() - 1)]);
    }
    cout << ans << endl;

    return 0;
}