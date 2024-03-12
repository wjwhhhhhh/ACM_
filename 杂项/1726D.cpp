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
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU f(n);
    vector<int> deg(n);
    string ans(m, '0');
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        x[i] = a, y[i] = b;
        if (!f.same(a, b))
        {
            f.merge(a, b);
            ans[i] = '1';
        }
    }
    int last, flag = 0;
    for (int i = 0; i < m; i++)
    {
        if (ans[i] == '0')
        {
            last = i;
            deg[x[i]]++, deg[y[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
        flag += (deg[i] == 2);
    if (flag == 3)
    {
        // cerr << "ok" << endl;
        f.init(n);
        f.merge(x[last], y[last]);
        for (int i = 0; i < m; i++)
        {
            if (ans[i] == '1')
            {
                if (!f.same(x[i], y[i]))
                {
                    f.merge(x[i], y[i]);
                }
                else
                    ans[i] = '0';
            }
        }
        ans[last] = '1';
    }
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