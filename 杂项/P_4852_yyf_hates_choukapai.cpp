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
    int n, m, c, d;
    cin >> n >> m >> c >> d;
    int all = c * n + m;
    vector<int> a(all + 1);
    for (int i = 1; i <= all; i++)
        cin >> a[i];
    vector<int> s(all + 1);
    for (int i = 1; i <= all; i++)
        s[i] = s[i - 1] + a[i];
    vector<vector<i64>> f(n + 1, vector<i64>(all + 1));
    vector<vector<i64>> fr(n + 1, vector<i64>(all + 1));
    for (int i = 0; i <= n; i++)
        fill(f[i].begin(), f[i].end(), -1e18);
    for (int i = 1; i + c - 1 <= all; i++)
    {
        if (i - 1 <= d)
            f[1][i] = a[i] + s[i - 1];
    }
    vector<int> q(all);
    int hh = 0, tt = -1;
    auto get = [&](int x, int y) { return f[x][y] - s[y + c - 1]; };
    for (int i = 2; i <= n; i++)
    {
        hh = 0, tt = -1;
        q[++tt] = 1;
        for (int j = c + 1; j + c - 1 <= all; j++)
        {
            while (hh <= tt && (q[hh] + c + d < j))
                hh++;
            int id = q[hh];
            fr[i][j] = id;
            f[i][j] = f[i - 1][id] + a[j] + s[j - 1] - s[id + c - 1];
            while (hh <= tt && get(i - 1, q[tt]) < get(i - 1, j - c + 1))
                tt--;
            q[++tt] = j - c + 1;
        }
    }
    i64 ans = -1e18, from;
    for (int i = 1; i <= all; i++)
    {
        if (all - (i + c - 1) <= d)
        {
            if (ans < f[n][i] + s[all] - s[i + c - 1])
            {
                ans = f[n][i] + s[all] - s[i + c - 1];
                from = i;
            }
        }
    }
    vector<int> cnt;
    for (int i = n; i >= 0; i--)
    {
        cnt.push_back(from);
        from = fr[i][from];
    }
    cout << ans << endl;
    for (int i = n - 1; i >= 0; i--)
        cout << cnt[i] << " ";
    return 0;
}