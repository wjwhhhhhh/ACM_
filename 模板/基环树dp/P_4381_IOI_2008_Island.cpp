#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e6 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx = 0;
int n;
int fa[N], fa_w[N];
bool v[M];
bool in[N];
int ans = 0, anssum = 0;
int cir[2 * N], en[2 * N], cnt, cir_size;
int sum[2 * N], f[2 * N], cir_sum[2 * N], dp[2 * N];
bool st[N];
void add(int a, int b, int c) // 添加一条边a->b
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs_h(int u, int fath) // 找环
{
    st[u] = in[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        if (v[i])
            continue;
        v[i] = v[i ^ 1] = true;
        int j = e[i];
        fa[j] = u, fa_w[j] = w[i];
        if (!st[j])
            dfs_h(j, u);
        else if (in[j])
        {
            cir_sum[cnt] = 0;
            cir[cnt++] = fa[j];
            for (int k = u; k != j; k = fa[k], cnt++)
            {
                // cout << k << fa[k] << " " << fa_w[k] << endl;
                cir[cnt] = fa[k];
                cir_sum[cnt] = cir_sum[cnt - 1] + fa_w[k];
            }
            en[cir_size++] = cnt;
            cir_sum[cnt] = cir_sum[cnt - 1] + fa_w[j];
            cir[cnt++] = u;
            // cout << fa_w[j] << endl;
        }
    }
    in[u] = false;
}
int dfs_c(int u)
{
    st[u] = true;
    int dist1 = 0, dist2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j])
            continue;
        dfs_c(j);
        if (dist1 < dp[j] + w[i])
            dist2 = dist1, dist1 = dp[j] + w[i];
        else if (dist2 < dp[j] + w[i])
            dist2 = dp[j] + w[i];
    }
    ans = max(dist1 + dist2, ans);
    dp[u] = dist1;
    return dp[u];
}
int q[M], tt, hh;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int a = i, b, c;
        cin >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            dfs_h(i, -1);
        }
    }
    memset(st, 0, sizeof st);
    for (int i = 0; i < cir_size; i++)
    {
        int l, r, le;
        if (i == 0)
            l = 0, r = en[i];
        else
            l = en[i - 1] + 1, r = en[i];
        le = r - l;
        for (int j = l; j < r; j++)
            st[cir[j]] = true;
        for (int j = l; j < r; j++)
            f[j] = dfs_c(cir[j]), sum[j] = cir_sum[j];
        sum[r] = cir_sum[r], f[r] = f[l];
        for (int j = r + 1; j < 2 * (r - l) + l; j++)
            sum[j] = sum[r] + sum[j - r + l] - sum[l];
        tt = hh = 0, q[tt] = l;
        int tem = 0;
        for (int i = l + 1; i <= 2 * (r - l) + l; i++)
        {
            while (tt >= hh && i - q[hh] >= le)
                hh++;
            tem = max(tem, f[i] + sum[i] + f[q[hh]] - sum[q[hh]]);
            while (tt >= hh && f[i] - sum[i] >= f[q[tt]] - sum[q[tt]])
                tt--;
            q[++tt] = i;
        }
        anssum += tem;
        // cout << tem << endl;
    }
    ans = max(ans, anssum);
    cout << ans << endl;
    return 0;
}