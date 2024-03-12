#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
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
const int N = 2e5 + 10;
vector<vector<int>> fac(N);
int ans = -1;
int k;
struct graph
{
    int root;
    int node_size;
    vector<vector<int>> eg, w;
    graph(int n = 0)
    {
        node_size = n;
        root = 0;
        eg.resize(n);
        w.resize(n);
    }
    void add(int x, int y, int z = 0)
    {
        eg[x].push_back(y);
        w[x].push_back(z);
    }
};
unordered_set<int> has[N], all[N];
struct Point_divide : graph // 点分治
{
    vector<int> vis, siz, mx;
    Point_divide(int n) : graph(n)
    {
        root = -1;
        vis.resize(n);
        siz.resize(n);
        mx.resize(n);
    }

    void get_dis(int u, int fa, int dis, int depth, int &lim)
    {
        if (depth == k)
        {
            chmax(ans, dis);
            return;
        }
        chmax(lim, depth);
        for (auto c : fac[dis])
        {
            // cout << c << endl;
            has[depth].insert(c);
        }
        for (int i = 0; i < eg[u].size(); i++)
        {
            int j = eg[u][i];
            if (j == fa || vis[j])
                continue;
            get_dis(j, u, __gcd(dis, w[u][i]), depth + 1, lim);
        }
    }
    void calc(int u)
    {
        // cout << "ok" << u << endl;
        // cout << ans << endl;
        int zuilim = 0, lim;
        for (int i = 0; i < eg[u].size(); i++)
        {
            lim = 0;
            int j = eg[u][i];
            if (vis[j])
                continue;
            get_dis(j, -1, w[u][i], 1, lim);
            for (int i = 1; i <= lim; i++)
            {
                for (auto &c : has[i])
                {
                    if (all[k - i].count(c))
                        chmax(ans, c);
                }
            }
            for (int i = 1; i <= lim; i++)
            {
                for (auto &c : has[i])
                {
                    all[i].insert(c);
                }
                has[i].clear();
            }
            chmax(zuilim, lim);
        }
        for (int i = 1; i <= zuilim; i++)
        {
            all[i].clear();
        }
    }
    void find(int u, int fa = -1)
    {
        siz[u] = 1, mx[u] = 0;
        for (int i = 0; i < eg[u].size(); i++)
        {
            int j = eg[u][i];
            if (j == fa || vis[j])
                continue;
            find(j, u);
            siz[u] += siz[j];
            chmax(mx[u], siz[j]);
        }
        chmax(mx[u], node_size - siz[u]);
        if (root < 0 || mx[u] < mx[root])
        {
            root = u;
        }
    }
    void solve(int u)
    {
        vis[u] = true;
        calc(u);
        for (int i = 0; i < eg[u].size(); i++)
        {
            int j = eg[u][i];
            if (vis[j])
                continue;
            root = -1;
            node_size = siz[j];
            find(j, -1);
            find(root, -1);
            solve(root);
        }
    }
    void work()
    {
        find(0, -1);
        find(root, -1);
        solve(root);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n >> k;
    k--;
    for (int i = 1; i <= 2e5; i++)
    {
        for (int j = i; j <= 2e5; j += i)
            fac[j].push_back(i);
    }
    Point_divide po(n);
    for (int i = 1; i < n; i++)
    {
        int p, w;
        cin >> p >> w;
        p--;
        po.add(p, i, w);
        po.add(i, p, w);
    }
    po.work();
    cout << ans << endl;
    return 0;
}