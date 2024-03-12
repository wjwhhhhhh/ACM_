#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
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
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);

    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    DSU f(n);
    for (int i = 0; i < m; i++)
    {
        if (w[l[i]] != w[r[i]])
            f.merge(l[i], r[i]);
    }
    bool fl = false;
    for (int i = 0; i < m; i++)
    {
        if (w[l[i]] == w[r[i]] && f.same(l[i], r[i]))
            fl = true;
    }
    if (fl)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}