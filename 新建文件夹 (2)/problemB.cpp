
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

    int operator[](int i)
    {
        return find(i);
    }
};
const int N = 2e5 + 10;
int h[N], ne[2 * N], e[2 * N], idx = 0;
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }
    i64 ans = 0;
    for (int j = 0; j < 30; j++)
    {
        DSU f(n);
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < m; i++)
        {
            if (!(c[i] >> j & 1))
            {
                f.merge(a[i], b[i]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (c[i] >> j & 1)
            {
                if (f.same(a[i], b[i]))
                {
                    cout << "-1" << '\n';
                    return 0;
                }
                else
                    add(f.find(a[i]), f.find(b[i])), add(f.find(b[i]), f.find(a[i]));
            }
        }
        vector<int> color(n, -1);
        i64 res1, res0;
        std::function<bool(int, int)> dfs = [&](int u, int c) {
            color[u] = c;
            if (c)
                res1 += f.size(u);
            else
                res0 += f.size(u);
            for (int i = h[u]; ~i; i = ne[i])
            {
                int v = e[i];
                if (color[v] == c || color[v] == -1 && !dfs(v, c ^ 1))
                {
                    return false;
                }
            }
            return true;
        };
        vector<int> st(n);

        for (int i = 0; i < n; i++)
        {
            // if (st[f.find(i)])
            //     continue;
            // st[f.find(i)] = true;
            res1 = 0, res0 = 0;
            if (color[i] == -1 && !dfs(i, 0))
            {
                std::cout << "-1\n";
                return 0;
            }
            ans += min(res1, res0) * (1 << j);
        }
    }
    cout << ans << endl;
    return 0;
}