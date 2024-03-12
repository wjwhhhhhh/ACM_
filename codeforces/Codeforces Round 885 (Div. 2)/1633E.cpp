#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
struct EDGE
{
    int fr, to, w;
    EDGE(int a, int b, int c)
    {
        init(a, b, c);
    }
    void init(int a, int b, int c)
    {
        fr = a, to = b, w = c;
    }
};
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
    int n, m;
    cin >> n >> m;
    vector<EDGE> ed;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        c *= 2;
        ed.emplace_back(EDGE(a, b, c));
    }
    auto Kruskal = [&](i64 xx) -> pair<i64, int> {
        sort(ed.begin(), ed.end(), [&](EDGE x, EDGE y) {
            i64 wa = abs(x.w - xx), wb = abs(y.w - xx);
            return wa < wb || (wa == wb && x.w > y.w);
        });
        DSU f(n);
        i64 ans = 0, cnt = 0;
        for (int i = 0; i < m; i++)
        {
            // cout << ed[i].w << endl;
            if (f.same(ed[i].fr, ed[i].to))
                continue;
            f.merge(ed[i].fr, ed[i].to);
            ans += abs(ed[i].w - xx);
            cnt += xx < ed[i].w;
        }
        return make_pair(ans, cnt);
    };
    vector<int> has(1, 0);
    for (int i = 0; i < m; i++)
        for (int j = i; j < m; j++)
        {
            has.push_back(ed[i].w + ed[j].w >> 1);
        }
    sort(has.begin(), has.end());
    has.erase(unique(has.begin(), has.end()), has.end());
    vector<i64> res;
    vector<int> cnt;
    for (auto x : has)
    {
        auto get = Kruskal(x);
        // cout << get.first << endl;
        res.push_back(get.first);
        cnt.push_back(get.second);
    }
    i64 ans = 0;
    int P, k, a, b, c;
    cin >> P >> k >> a >> b >> c;
    for (int i = 1; i <= k; i++)
    {
        int x;
        if (i <= P)
            cin >> x;
        else
            x = (x * a + b) % c;

        int pos = upper_bound(has.begin(), has.end(), 2 * x) - has.begin() - 1;
        ans ^= (res[pos] + (n -1- 2 * cnt[pos]) * 1ll * (2 * x - has[pos])) / 2;
        // 加上左右两边点的个数的差值
    }
    cout << ans << endl;
    return 0;
}