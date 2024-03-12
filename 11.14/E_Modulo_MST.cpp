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
    i64 n, m, k;
    cin >> n >> m >> k;
    using ar = array<i64, 3>;
    vector<ar> ed;
    for (int i = 0; i < m; i++)
    {
        i64 a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        ed.push_back(ar{a, b, c});
    }
    i64 ans = k;
    vector<int> has;
    function<i64(void)> check = [&] {
        DSU f(n);
        i64 all = 0;
        for (auto c : has)
        {
            auto [x, y, w] = ed[c];
            // cerr << x << " " << y << c << endl;
            f.merge(x, y);
            all += w;
        }
        if (f.size(0) != n)
        {
            return k;
        }
        return all % k;
    };
    function<void(int)> dfs = [&](int idx) {
        if (has.size() == n - 1)
        {
            chmin(ans, check());
            return;
        }
        if (idx == m)
            return;
        has.push_back(idx);
        dfs(idx + 1);
        has.pop_back();
        dfs(idx + 1);
    };
    dfs(0);
    cout << ans << endl;
    return 0;
}