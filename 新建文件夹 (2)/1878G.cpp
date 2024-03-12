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
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<vector<int>> edg(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    vector<array<int, 25>> fa(n), val(n);
    vector<int> depth(n);
    depth[0] = 1;
    function<void(int, int)> dfs = [&](int u, int fath) {
        fa[u][0] = fath;
        val[u][0] = w[u];
        for (auto v : edg[u])
        {
            if (v == fath)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, -1);
    fa[0][0] = 0;
    for (int i = 1; i < 25; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            val[j][i] = val[j][i - 1] | val[fa[j][i - 1]][i - 1];
        }
    }
    function<int(int, int, int &)> lca = [&](int x, int y, int &la) {
        if (depth[x] < depth[y])
            swap(x, y);
        int ans = 0;
        for (int i = __lg(depth[x] - depth[y]); ~i; i--)
        {
            if (depth[fa[x][i]] >= depth[y])
                ans |= val[x][i], x = fa[x][i];
        }
        if (x == y)
        {
            ans |= w[x];
            la = x;
            return ans;
        }
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                ans |= val[x][i], ans |= val[y][i];
                x = fa[x][i], y = fa[y][i];
            }
        }
        ans |= w[fa[x][0]];
        ans |= w[x], ans |= w[y];
        la = fa[x][0];
        return ans;
    };
    auto get = [&](int x) {
        int si = 0;
        while (x)
        {
            si++;
            x -= x & -x;
        }
        return si;
    };
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        int ci = 0;
        cin >> x >> y;
        x--, y--;
        if (depth[x] < depth[y])
            swap(x, y);
        int zx = x, zy = y;
        int la, cf, cnt = 0;
        lca(x, y, la);
        int last=0;
        while (depth[x] > depth[la])
        {

            int cn1 = last|w[x], cn2 = lca(zy, x, cf), cn3 = lca(la, zy, cf);
            for (int i = __lg(depth[x] - depth[la]); i >= 0; i--)
            {
                int tm = fa[x][i];
                if ((lca(x, tm, cf)|last) == cn1 && (lca(la, tm, cf) | cn3) == cn2)
                {
                    x = fa[x][i];
                }
            }
            cn1 = lca(zx, x, cf), cn2 = lca(zy, x, cf);
            chmax(cnt, get(cn1) + get(cn2));
            x = fa[x][0];
        }
        int cn1 = lca(zx, la, cf), cn2 = lca(zy, la, cf);
        chmax(cnt, get(cn1) + get(cn2));
        if (y != la)
        {
            while (depth[y] > depth[la])
            {
                int cn1 = lca(zx, y, cf), cn2 = lca(zy, y, cf), cn3 = lca(la, zx, cf);
                for (int i = __lg(depth[y] - depth[la]); i >= 0; i--)
                {
                    int tm = fa[y][i];
                    if ((lca(la, tm, cf) | cn3) == cn1 && lca(zy, tm, cf) == cn2)
                    {
                        y = fa[y][i];
                    }
                }
                cn1 = lca(zx, y, cf), cn2 = lca(zy, y, cf);
                chmax(cnt, get(cn1) + get(cn2));
                y = fa[y][0];
            }
        }
        cout << cnt << " ";
    }
    cout << '\n';
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