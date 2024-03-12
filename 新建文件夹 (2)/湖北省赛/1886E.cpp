#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define int long long
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
    int n, m;
    cin >> n >> m;
    vector<int> f(1 << m, 1e9);
    vector<int> from(1 << m, -1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    f[0] = -1;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<vector<int>> dp(m, vector<int>(n + 1, 1e9));
    vector<vector<int>> need(m, vector<int>(n + 1, -1));
    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (chmin(dp[j][i], dp[j][i + 1]))
            {
                need[j][i] = need[j][i + 1];
            }
            if (chmin(dp[j][i], (b[j] - 1) / a[o[i]] + i))
            {
                need[j][i] = i;
            }
        }
    }
    for (int i = 0; i < 1 << m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!(i >> j & 1))
            {
                if (f[i] + 1 >= n)
                    continue;
                if (chmin(f[i | 1 << j], dp[j][f[i] + 1]))
                {
                    from[i | 1 << j] = i;
                }
            }
        }
    }
    if (f[(1 << m) - 1] < n)
    {
        cout << "YES" << endl;
        vector<vector<int>> ans(m);
        int ing = (1 << m) - 1;
        int id = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int i = 0; i < m; i++)
            {
                if (ing - from[ing] == 1 << i)
                {
                    id = i;
                }
            }
            for (int j = need[id][f[from[ing]] + 1]; j <= f[ing]; j++)
            {
                ans[id].push_back(o[j]);
            }
            ing = from[ing];
        }
        for (int i = 0; i < m; i++)
        {
            cout << ans[i].size() << " ";
            for (auto c : ans[i])
                cout << c + 1 << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}