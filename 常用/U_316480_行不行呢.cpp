#include <bits/stdc++.h>
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
void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    DSU f(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<pair<int, int>> has;
    for (int i = 0; i < n; i++)
    {
        int mi = min(i + 1, n - i);
        if (d[i] > mi)
        {
            cout << "No" << endl;
            return;
        }
        for (int j = 1; j < d[i]; j++)
        {
            f.merge(i + j, i - j);
        }
        if (d[i] < mi)
        {
            has.push_back({i - d[i], i + d[i]});
        }
    }
    for (auto [x, y] : has)
    {
        // cout << x << " " << y << endl;
        if (f.same(x, y))
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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