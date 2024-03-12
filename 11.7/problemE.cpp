#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
const int M = 998244353;
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    fir(i, 0, n) cin >> a[i];
    vector<vector<two>> edg(n);
    vector<vector<int>> w(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        deg[a]++, deg[b]++;
        edg[a].push_back(two{b, c});
        edg[b].push_back(two{a, c});
    }
    vector<i64> dp(n);
    int blo = sqrt(m);
    vector<int> qq(q);
    fir(i, 0, q) cin >> qq[i], qq[i]--;
    // dug(1);
    for (int i = 0; i < n; i++)
    {
        if (deg[i] > blo)
        {
            nth_element(edg[i].begin(), edg[i].begin() + blo, edg[i].end(),
                        [&](two x, two y) { return dp[x[0]] + x[1] < dp[y[0]] + y[1]; });
        }
    }
    int si = 1;
    for (int i = q - 1; i >= 0; i--)
    {
        int x = qq[i];
        dp[x] = 1e18;
        for (int i = 0; i < min(blo + 1, deg[x]); i++)
        {
            chmin(dp[x], dp[edg[x][i][0]] + edg[x][i][1]);
        }
        if (si % blo == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (deg[i] > blo)
                {
                    nth_element(edg[i].begin(), edg[i].begin() + blo, edg[i].end(),
                                [&](two x, two y) { return dp[x[0]] + x[1] < dp[y[0]] + y[1]; });
                }
            }
        }
        si++;
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + a[i] * dp[i] % M) % M;
    }
    cout << ans << endl;
    return 0;
}