#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
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
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int operator[](int x)
    {
        return find(x);
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};
using three = array<int, 3>;
int ans = 2e9;
int n, m;
const int N = 3e5 + 10;
int dist1[N], dist2[N];
int res = 2e9;
void get(int dist[N], int s, vector<three> &a)
{
    DSU f(n);
    vector<vector<two>> edg(n);
    for (auto [x, y, c] : a)
    {
        if (f.same(x, y))
            continue;
        f.merge(x, y);
        edg[x].push_back({y, c});
        edg[y].push_back({x, c});
    }
    function<void(int, int, int)> dfs = [&](int u, int fa, int res) {
        dist[u] = res;
        for (auto [c, x] : edg[u])
        {
            if (c == fa)
                continue;
            dfs(c, u, max(res, x));
        }
    };
    dfs(s, -1, 0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    cin >> n >> m;
    vector<three> all(m);
    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);
    for (int i = 0; i < m; i++)
    {
        cin >> all[i][0] >> all[i][1] >> all[i][2];
        all[i][0]--, all[i][1]--;
        if (all[i][0] > all[i][1])
            swap(all[i][0], all[i][1]);
        if (all[i][0] == 0 && all[i][1] == n - 1)
            chmin(res, all[i][2]);
    }
    sort(all.begin(), all.end(), [&](three x, three y) { return x[2] < y[2]; });
    get(dist1, 0, all);
    get(dist2, n - 1, all);
    for (int i = 0; i < m; i++)
    {
        int tem = 2e9;
        auto [x, y, c] = all[i];
        if (dist1[x] <= c && dist2[y] <= c)
            chmin(tem, c + max(dist1[x], dist2[y]));
        if (dist1[y] <= c && dist2[x] <= c)
            chmin(tem, c + max(dist1[y], dist2[x]));
        // cout << tem << x << " " << y << " " << dist2[2] << endl;
        chmin(ans, tem);
    }
    // cout << dist1[1] << endl;
    cout << min(res, ans) << endl;
    return 0;
}