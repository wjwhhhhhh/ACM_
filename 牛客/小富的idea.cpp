#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<array<int, 3>> has(n), all;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> has[i][j];
    DSU f(n);
    auto get = [&](int x, int y) {
        i64 d1 = abs(has[x][0] - has[y][0]), d2 = abs(has[x][1] - has[y][1]);
        int v = has[x][2] + has[y][2];
        if (v == 0)
            return (int)1e9;
        i64 l = 1, r = 1e4;
        while (l < r)
        {
            i64 mid = l + r >> 1;
            if (v * mid * v * mid >= d1 * d1 + d2 * d2)
                r = mid;
            else
                l = mid + 1;
        }
        return (int)l;
    };
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            all.push_back({get(i, j), i, j});
        }

    sort(all.begin(), all.end());
    vector<int> w;
    for (auto [x, y, z] : all)
    {
        if (f.same(y, z))
            continue;
        w.push_back(x);
        f.merge(y, z);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        cout << n - (upper_bound(w.begin(), w.end(), a) - w.begin()) << endl;
    }
    return 0;
}