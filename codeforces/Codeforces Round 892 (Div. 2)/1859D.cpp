#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
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
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    vector<int> all;
    int q;
    cin >> q;
    vector<int> qe(q);
    for (int i = 0; i < q; i++)
        cin >> qe[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            all.push_back(a[i][j]);
    for (int i = 0; i < q; i++)
        all.push_back(qe[i]);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    map<int, int> mp;
    int idx = 0;
    for (int i = 0; i < all.size(); i++)
        mp[all[i]] = idx++;
    DSU f(all.size());
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x][3] < a[y][3]; });
    int l = all.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int id = o[i];
        int x1 = a[id][0], x2 = a[id][3];
        int ci = mp[x1], ci2 = mp[x2];
        if (l < ci)
            continue;
        // cout << i << endl;
        while (ci < l && ci < ci2)
        {
            // cout << ci << " " << ci2 << endl;
            f.merge(ci2, ci);
            ci++;
        }
        l = mp[x1];
    }

    for (int i = 0; i < qe.size(); i++)
    {
        int tr = f.find(mp[qe[i]]);
        // cout << tr << " kl";
        cout << all[tr] << " ";
    }
    cout << endl;
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