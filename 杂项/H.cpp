#include <bits/stdc++.h>
#define int long long
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
    void init(int a, int b, int c)
    {
        fr = a, to = b, w = c;
    }
    friend bool operator<(const EDGE &x, const EDGE &y)
    {
        return x.w < y.w;
    }
};
const int N = 62;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n, m, q, V;
    cin >> n >> m >> q >> V;
    if (V == 0)
    {
        DSU f(n);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            f.merge(a, b);
        }
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (f.same(a, b))
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
        return 0;
    }

    vector<EDGE> ed(m);
    vector<DSU> f(N, DSU(n));
    int B = __lg(V);
    for (int j = 0; j < m; j++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        for (int i = N - 1; i >= B; i--)
        {
            if (c >> i & 1)
                f[i].merge(a, b);
        }
        ed[j].init(a, b, c);
    }
    vector<DSU> dsu(B + 1, DSU(n));
    vector<int> st(m);
    for (int i = 0; i < m; i++)
    {
        if (ed[i].w >> B & 1)
        {
            st[i] = true;
        }
    }
    for (int j = B; j >= 0; j--)
    {
        if ((V & -V) == (1LL << j))
        {
            for (int i = 0; i < m; i++)
            {
                if (st[i] && ed[i].w >> j & 1)
                    dsu[j].merge(ed[i].fr, ed[i].to);
            }
            break;
        }
        else if (V >> j & 1)
        {
            for (int i = 0; i < m; i++)
            {
                if (st[i] && (~ed[i].w >> j & 1))
                {
                    st[i] = false;
                }
            }
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                if (st[i] && ed[i].w >> j & 1)
                    dsu[j].merge(ed[i].fr, ed[i].to);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bool fl = false;
        for (int i = N - 1; i > B; i--)
        {
            if (f[i].same(a, b))
                fl = true;
        }
        if (fl)
        {
            cout << "Yes" << endl;
            continue;
        }
        for (int i = 0; i <= B; i++)
            if (dsu[i].same(a, b))
                fl = true;
        if (fl)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}