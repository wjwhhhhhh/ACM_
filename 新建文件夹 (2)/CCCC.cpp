#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int M = 998244353;
struct Comb
{
#define ll long long
    ll n, p;
    vector<ll> fac, inv; // 阶乘 逆元

    long long qmi(long long k, long long p, long long M)
    {
        long long res = 1;
        while (p)
        {
            if (p & 1)
                res = res * k % M;
            k = k * k % M;
            p >>= 1;
        }
        return res;
    }
    Comb()
    {
    }
    Comb(int a, int b)
    {
        init(a, b);
    }
    void init(int a, int b)
    {
        n = a, p = b;
        fac.resize(n + 1), inv.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;
        inv[n] = qmi(fac[n], p - 2, p);
        for (int i = n; i; i--)
            inv[i - 1] = inv[i] * i % p;
    }
    int C(int n, int m) // 在n里选m
    {
        if (n < m || m < 0)
            return 0;
        return (fac[n] * inv[m] % p) * inv[n - m] % p;
    }
    int lucas(int n, int m) // 要为质数
    {
        if (n < m || m < 0)
            return 0;
        if (m == 0)
            return 1;
        return 1ll * C(n % p, m % p) * lucas(n / p, m / p) % p;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<vector<int>> edg(n);
    Comb co(n + 10, M);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    vector<vector<int>> ans(n, vector<int>(n));
    vector<int> depth(n), w(n), siz(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        int si = 0;
        siz[u] = 1;
        for (auto c : edg[u])
        {
            if (c != fa)
            {
                si++;
                depth[c] = depth[u] + 1;
                dfs(c, u);
                w[u] += w[c];
                siz[u] += siz[c];
            }
        }
        if (si == 0)
            w[u]++;
    };
    dfs(0, -1);
    i64 res = 1;
    for (auto c : edg[0])
    {
        res *= co.fac[w[c]];
        res %= M;
    }
    vector<i64> ww, v;
    res *= co.fac[edg[0].size()];
    res %= M;
    ans[0][0] = res;
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (auto c : edg[u])
        {
            if (c == fa)
                continue;
            for (auto t : edg[u])
            {
                if (t == fa || c == t)
                    continue;
                v.push_back(siz[t]);
                ww.push_back(co.fac[w[t]]);
            }

            vector<vector<vector<i64>>> last(2, vector<vector<i64>>(n, vector<i64>(n)));
            last[0][0][0] = 1;
            for (int i = 0; i < ww.size(); i++)
            {
                vector<vector<vector<i64>>> ing(2, vector<vector<i64>>(n, vector<i64>(n)));
                for (int j = 0; j < n; j++)
                {
                    for (int z = 0; z < n; z++)
                    {
                        if (j + v[i] >= n || z + 1 >= n)
                            continue;
                        ing[0][j + v[i]][z + 1] += last[0][j][z] * ww[i];
                        ing[0][j + v[i]][z + 1] %= M;
                        ing[1][j][z] += last[0][j][z] * ww[i];
                        ing[1][j][z] %= M;
                        ing[0][j + v[i]][z + 1] += last[1][j][z] * ww[i];
                        ing[0][j + v[i]][z + 1] %= M;
                        ing[1][j][z] += last[1][j][z] * ww[i];
                        ing[1][j][z] %= M;
                    }
                }
                std::swap(last, ing);
            }

            // cout << last[1][0][0] << endl;
            for (int i = depth[c]; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ans[c][i] += last[0][i - depth[c]][j] * co.fac[j] * co.fac[ww.size() - j];
                    ans[c][i] %= M;
                    ans[c][i] += last[1][i - depth[c]][j] * co.fac[j] * co.fac[ww.size() - j];
                    ans[c][i] %= M;
                }
            }
            for (int i = 0; i < n; i++)
            {
                ans[c][i] *= co.fac[w[c]];
                ans[c][i] %= M;
            }
            dfs2(c, u);
            for (int zz = edg[u].size() - 1; zz >= 0; zz--)
            {
                int t = edg[u][zz];
                if (t == fa || c == t)
                    continue;
                ww.pop_back();
                v.pop_back();
            }
        }
    };
    dfs2(0, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}