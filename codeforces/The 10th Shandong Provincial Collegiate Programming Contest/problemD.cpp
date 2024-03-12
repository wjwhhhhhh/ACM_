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
    int k;
    cin >> k;
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
        a[i]--;
    int n, m;
    cin >> n >> m;
    DSU f(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
    }
    int id = a[(m - n + 1) % k] - '0';
    id = !id;
    cout << id + 1 << '\n';
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