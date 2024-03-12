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
struct DSU
{
    std::vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
struct EDGE
{
    int fr, to, w;
    void init(int a = 0, int b = 0, int c = 0)
    {
        fr = a, to = b, w = c;
    }
    friend bool operator<(const EDGE &x, const EDGE &y)
    {
        return x.w < y.w;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    DSU ds(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    vector<EDGE> ge(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ge[i].init(a, b);
    }
    int q;
    cin >> q;
    vector<array<int, 3>> st(q);
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> st[i][j];
        for (int j = 0; j < 2; j++)
            st[i][j]--;
    }
    vector<int> o(q);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return f[st[x][0]] + st[x][2] < f[st[y][0]] + st[y][2]; });
    vector<int> o1(m);
    iota(o1.begin(), o1.end(), 0);
    sort(o1.begin(), o1.end(),
         [&](int x, int y) { return max(f[ge[x].fr], f[ge[x].to]) < max(f[ge[y].fr], f[ge[y].to]); });

    int idx = 0;
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int id = o[i];
        while (idx < m && max(f[ge[o1[idx]].fr], f[ge[o1[idx]].to]) <= f[st[id][0]] + st[id][2])
        {
            ds.merge(ge[o1[idx]].fr, ge[o1[idx]].to);
            idx++;
        }
        ans[id] = ds.same(st[id][0], st[id][1]);
    }
    for (int i = 0; i < q; i++)
    {
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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