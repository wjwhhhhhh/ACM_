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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    DSU f(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int id = i - a[i];
        if (mp.find(id) != mp.end())
        {
            f.merge(i, mp[id]);
        }
        else
            mp[id] = i;
    }
    map<int, vector<int>> has;
    for (int i = 0; i < n; i++)
    {
        has[f.find(i)].push_back(a[i]);
    }
    i64 ans = 0;
    for (auto [x, y] : has)
    {
        sort(y.begin(), y.end());
        if (y.size() == 1)
            continue;
        for (int i = y.size() - 2; i >= 0; i -= 2)
        {
            i64 tem = y[i] + y[i + 1];

            if (tem <= 0)
                break;
            else
                ans += tem;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}