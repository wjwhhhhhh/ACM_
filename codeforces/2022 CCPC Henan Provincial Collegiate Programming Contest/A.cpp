#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#include <bits/stdc++.h>
using namespace std;
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
    friend bool operator < (const EDGE &x, const EDGE &y) {
        return x.w < y.w;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    std::vector<EDGE> edge(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[i].init(a, b, c);
    }
    sort(edge.begin(), edge.end());
    int k;
    cin >> k;
    vector<vector<int> > at(k);
    for (int i = 0; i < k; i++)
    {
        int si = 0;
        cin >> si;
        for (int j = 0; j < si; j++)
        {
            int a;
            cin >> a;
            at[i].push_back(a);
        }
    }
    int l = 0, r = 1e9;
    auto check = [&](int x)
    {
        DSU f(n);
        for (int i = 0; i < m; i++)
        {
            if (edge[i].w > x)break;
            f.merge(edge[i].fr, edge[i].to);
        }
        for (int i = 0; i < k; i++)
        {
            for (auto i : at[i])
            {
                if (!f.same(at[i][0], i))return false;
            }
        }
        return true;
    };
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    return 0;
}