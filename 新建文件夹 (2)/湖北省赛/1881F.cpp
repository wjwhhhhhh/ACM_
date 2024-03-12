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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ed(n);
    set<int> has;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        a--;
        has.insert(a);
    }
    if (n == 1)
    {
        cout << "0" << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    vector<int> va(n, -1e9);
    function<void(int, int)> dfs = [&](int u, int fa) {
        vector<int> inf;
        if (has.find(u) != has.end())
        {
            chmax(va[u], 0);
        }
        for (auto c : ed[u])
        {
            if (c == fa)
                continue;
            inf.push_back(c);
            dfs(c, u);
            chmax(va[u], va[c] + 1);
        }
        ed[u] = inf;
    };
    dfs(0, -1);
    int ans = va[0];
    sort(ed[0].begin(), ed[0].end(), [&](int x, int y) { return va[x] > va[y]; });
    function<void(int, int, int)> dfs2 = [&](int u, int fa, int res) {
        res++;
        if (has.find(u) != has.end())
            chmax(res, 0);
        chmin(ans, max(res, va[u]));
        for (auto c : ed[u])
        {
            if (c == fa)
                continue;
            dfs2(c, u, res);
        }
    };
    int fl = (has.find(0) != has.end() ? 0 : -1e9);
    if (ed[0].size() == 1)
    {
        dfs2(ed[0][0], 0, max(fl, -100000000 + 1));
    }
    else
        dfs2(ed[0][0], 0, max(fl, va[ed[0][1]] + 1));
    for (int i = 1; i < ed[0].size(); i++)
    {
        dfs2(ed[0][i], 0, max(fl, va[ed[0][0]] + 1));
    }
    chmax(ans, 0);
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