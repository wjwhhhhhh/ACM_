#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> all(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, d, c;
        cin >> a >> b >> d >> c;
        a--, b--;
        all[b].push_back(array<int, 3>{a, d, c});
    }
    auto check = [&](double ans) {
        vector<double> dp(n, -1e9);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (auto [x, y, c] : all[i])
            {
                chmax(dp[i], dp[x] + y - ans * c);
            }
        }
        return dp[n - 1] >= 0;
    };
    int si = 1000;
    double l = 0, r = 2e8;
    while (si--)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}