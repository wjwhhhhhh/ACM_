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
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<EDGE> edg(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edg[i].init(a, b, c);
    }
    int l = 0, r = 2e9;
    auto check = [&](int x) {
        vector<vector<int>> w(n);
        DSU f(2 * n);
        for (int i = 0; i < m; i++)
        {
            if (edg[i].w < x)
            {
                if (f.same(edg[i].fr, edg[i].to) || f.same(edg[i].fr, edg[i].to))
                {
                    return false;
                }
                f.merge(edg[i].fr, edg[i].to + n);
                f.merge(edg[i].fr + n, edg[i].to);
                w[edg[i].fr].push_back(edg[i].w);
                w[edg[i].to].push_back(edg[i].w);
            }
        }
        for (int i = 0; i < n; i++)
        {
            sort(w[i].begin(), w[i].end());
            if (w[i].size() >= 2)
            {
                if (w[i][0] + w[i][1] < x)
                    return false;
            }
        }
        return true;
    };
    while (l < r)
    {
        int mid = 1LL + l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}