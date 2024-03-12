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
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    auto get = [&](int x) { return make_pair(x / m, x % m); };
    auto back = [&](int x, int y) { return x * m + y; };
    DSU f(n * m);
    for (int i = 0; i < n * m; i++)
    {
        auto te = get(i);
        if (mp[te.first][te.second] == '.')
            continue;
        for (int k = 0; k < 8; k++)
        {

            int x = te.first + dx[k], y = te.second + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && mp[x][y] == 'W')
                f.merge(i, back(x, y));
        }
    }
    set<int> ans;
    for (int i = 0; i < n * m; i++)
    {
        auto te = get(i);
        if (mp[te.first][te.second] == 'W')
            ans.insert(f.find(i));
    }
    cout << ans.size() << endl;
    return 0;
}