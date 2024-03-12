#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    DSU f(n * m);
    auto get = [&](int x) { return make_pair(x / m, x % m); };
    auto fan = [&](int x, int y) { return x * m + y; };
    string has = "snukes";
    for (int i = 1; i < has.size(); i++)
    {
        for (int j = 0; j < n * m; j++)
        {
            auto [x, y] = get(j);
            if (mp[x][y] != has[i])
                continue;
            for (int k = 0; k < 4; k++)
            {
                int a = x + dx[k], b = y + dy[k];
                if (a >= 0 && b >= 0 && a < n && b < m && mp[a][b] == has[i - 1])
                {
                    f.merge(j, fan(a, b));
                }
            }
        }
    }
    bool fl = (f.find(0) == f.find(n * m - 1));
    if (mp[0][0] != 's')
    {
        cout << "No" << endl;
        return 0;
    }
    if (fl)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}