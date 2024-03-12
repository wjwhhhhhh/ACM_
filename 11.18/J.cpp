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
auto get(int x)
{
    if (x == 0)
        return 0;
    if (x & 1)
        return 1;
    return 2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> mp;
    DSU f(n);
    vector<vector<int>> edge(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        mp.push_back(two{a, b});
        f.merge(a, b);
    }
    i64 sum = 0;
    i64 ans = 0;
    set<int> has;
    for (int i = 0; i < n; i++)
    {
        if (has.find(f.find(i)) == has.end())
        {
            ans ^= get(f.size(i));
            has.insert(f.find(i));
        }
    }
    has.clear();
    vector<int> st(n);
    vector<int> siz(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        st[u] = true;
        siz[u] = 1;
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            dfs(c, u);
            siz[u] += siz[c];
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (!st[i])
        {
            dfs(i, -1);
        }
    }
    fill(st.begin(), st.end(), 0);
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        st[u] = true;
        i64 tem = ans;
        tem ^= get(f.size(u));
        tem ^= get(f.size(u) - siz[u]);
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            tem ^= get(siz[c]);
            dfs1(c, u);
        }
        if (tem == 0)
            sum++;
    };
    for (int i = 0; i < n; i++)
    {
        if (!st[i])
        {
            dfs1(i, -1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        auto [x, y] = mp[i];
        int mi = min(siz[x], siz[y]);
        i64 tem = ans ^ get(f.size(x));
        tem ^= get(mi);
        tem ^= get(f.size(x) - mi);
        if (tem == 0)
            sum++;
    }
    cout << sum << endl;
    return 0;
}