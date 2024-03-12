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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> edge(n);
    vector<int> w(n);
    fir(i, 0, n) cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<i64> ans(n);
    vector<i64> siz(n, 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            dfs(c, u);
            siz[u] += siz[c];
            ans[0] += siz[c] * (w[u] ^ w[c]);
        }
    };
    dfs(0, -1);
    //cout << ans[0] << endl;
    function<void(int, int, i64)> dfs1 = [&](int u, int fa, i64 tem) {
        ans[u] = tem;
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            dfs1(c, u, tem - siz[c] * (w[u] ^ w[c]) + (n - siz[c]) * (w[u] ^ w[c]));
        }
    };
    dfs1(0, -1, ans[0]);
    for (auto c : ans)
        cout << c << " ";
    cout << endl;
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