#include <bits/stdc++.h>
//#define int long long
using namespace std;
using i64 = long long;

const int lim = 893;
const i64 inf = 1e16;
struct dp_state
{
    vector<i64> a;
    vector<i64> b;
    void init()
    {
        a.resize(lim + 1, inf);
        b.resize(lim + 1, inf);
        a[1] = 1; //该节点为0
        b[1] = 2; //为 1
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int > > g(n + 1);
    vector<int> sz(n + 1);

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    function<int(int, int) >shuffle_kids = [&](int node, int fa)
    {
        int sz = 1;
        pair<int, int> best;
        for (int i = 0; i < (int)g[node].size(); i++)
        {
            if (g[node][i] == fa)continue;
            int sz2 = shuffle_kids(g[node][i], node);
            best = max(best, {sz2, i});
            sz += sz2;
        }
        if (!g[node].empty())
        {
            swap(g[node][0], g[node][best.second]);
        }
        return sz;
    };
    shuffle_kids(1, 0);

    vector<vector<i64> > merged(2 * lim + 1, vector<i64>(2, inf));
    function<dp_state(int, int)> dfs = [&](int node, int parent)
    {
        dp_state dp;
        sz[node] = 1;
        bool hasinit = false;
        for (auto i : g[node])
        {
            if (i != parent)
            {
                dp_state qui = dfs(i, node);
                if (!hasinit)
                {
                    dp.init();
                    hasinit = true;
                }
                for (int j = 0; j <= min(sz[node], lim) + min(sz[i], lim); ++j)
                {
                    merged[j][0] = merged[j][1] = inf;
                }
                for (int k = 1; k <= min(sz[node], lim); ++k)
                {
                    for (int l = 1; l <= min(sz[i], lim); ++l)
                    {
                        merged[k][0] = min(merged[k][0], dp.a[k] + qui.b[l]);
                        merged[k][1] = min(merged[k][1], dp.b[k] + qui.a[l]);
                        merged[k + l][0] = min(merged[k + l][0], dp.a[k] + qui.a[l] + 1ll*k * l);
                        merged[k + l][1] = min(merged[k + l][1], dp.b[k] + qui.b[l] + 2ll*k * l );
                    }
                }
                sz[node] += sz[i];
                for (int k = 1; k <= min(sz[node], lim); ++k)
                {
                    dp.a[k] = merged[k][0];
                    dp.b[k] = merged[k][1];
                }
            }
        }
        if (!hasinit)
        {
            dp.init();
            hasinit = true;
        }
        return dp;
    };
    dp_state dp = dfs(1, 0);
    i64 ans = inf;
    for (int i = 1; i <= lim; ++i)
    {
        ans = min(ans, dp.a[i]);
        ans = min(ans, dp.b[i]);
    }
    cout << 1ll*n * (n + 1) - ans << '\n';
}

signed main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);



    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}