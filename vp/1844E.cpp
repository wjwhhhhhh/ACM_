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
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 4>> a(k);
    vector<int> col(k);
    vector<pair<int, int>> sh(k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    auto get = [&](int id) -> pair<int, int> {
        int l = min(a[id][0], a[id][2]), r = min(a[id][1], a[id][3]);
        return make_pair(l, r);
    };
    for (int i = 0; i < k; i++)
    {
        if ((a[i][0] < a[i][2]) ^ (a[i][1] < a[i][3]))
            col[i] = 1;
        else
            col[i] = 0;
    }
    for (int i = 0; i < k; i++)
        sh[i] = get(i);
    vector<int> o(k);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return get(x) < get(y); });
    for (int i = 1; i < k; i++)
    {
        if (get(o[i - 1]) == get(o[i])&&col[o[i-1]]!=col[o[i]])
        {
            //cout<<get(o[i]).first<<get(o[i]).second;
            cout << "NO" << '\n';
            return;
        }
    }
    map<int, vector<int>> lie;
    for (int i = 0; i < k; i++)
    {
        auto an = get(o[i]);
        lie[an.second].push_back(o[i]);
    }
    DSU same(n + 1), diff(n + 1);
    for (auto [x, cnt] : lie)
    {
        for (int i = 1; i < cnt.size(); i++)
        {
            if(sh[cnt[i]]==sh[cnt[0]])continue;
            if (col[cnt[i]] == col[cnt[0]])
            {

                if (diff.same(sh[cnt[0]].first, sh[cnt[i]].first))
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                    same.merge(sh[cnt[0]].first, sh[cnt[i]].first);
            }
            else
            {
                if (same.same(sh[cnt[0]].first, sh[cnt[i]].first))
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                    diff.merge(sh[cnt[0]].first, sh[cnt[i]].first);
            }
        }
    }
    cout << "YES" << endl;
    // cerr << "kll;";
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