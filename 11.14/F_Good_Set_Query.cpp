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
    DSU f(n + 1);
    using ar = array<i64, 3>;
    vector<ar> ed;
    vector<int> all;
    vector<int> xu;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back(ar{a, b, c});
        if (!f.same(a, b))
        {
            f.merge(a, b);
            all.push_back(i);
        }
        else
            xu.push_back(i);
    }
    vector<vector<int>> edge(n + 1);
    vector<vector<int>> ww(n + 1);
    for (auto c : all)
    {
        auto [x, y, w] = ed[c];
        edge[x].push_back(y);
        ww[x].push_back(-w);
        edge[y].push_back(x);
        ww[y].push_back(w);
    }
    set<int> has;
    vector<i64> dist(n + 1);
    function<void(int, int)> dfs = [&](int u, int fath) {
        for (int i = 0; i < edge[u].size(); i++)
        {
            int j = edge[u][i];
            dist[j] = dist[u] + ww[u][i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (has.find(f.find(i)) == has.end())
        {
            dfs(i, 0);
            has.insert(f.find(i));
        }
    }
    for (auto id : xu)
    {
        auto [x, y, c] = ed[id];
        if (dist[x] - dist[y] == c)
            all.push_back(id);
    }
    sort(all.begin(), all.end());
    for (auto c : all)
        cout << c + 1 << " ";

    return 0;
}
