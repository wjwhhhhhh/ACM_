#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e6 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx = 0;
int n;
int fa[N], fa_w[N];
bool v[M];
bool in[N];
int ans = 0, anssum = 0;
int cir[2 * N], en[2 * N], cnt, cir_size;
int f[2 * N][2], dp[2 * N][2], w[M];
bool st[N];
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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
        fa[j] = u;
        if (!st[j])
            dfs_h(j, u);
        else if (in[j])
        {
            cir[cnt++] = fa[j];
            for (int k = u; k != j; k = fa[k], cnt++)
            {
                cir[cnt] = fa[k];
            }
            en[cir_size++] = cnt;
            cir[cnt++] = u;
        }
    }
    in[u] = false;
}
PII dfs_c(int u)
{
    st[u] = true;
    dp[u][1] = w[u], dp[u][0] = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            dfs_c(j);
            dp[u][1] += dp[j][0];
            dp[u][0] += max(dp[j][1], dp[j][0]);
        }
    }
    // if (u == 2)
    //     cout << dp[u][0] << "kl";
    return {dp[u][0], dp[u][1]};
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
        int b;
        cin >> w[i] >> b;
        add(i, b), add(b, i);
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
        for (int i = l; i < r; i++)
            st[cir[i]] = true;
        for (int i = l; i < r; i++)
        {
            auto tem = dfs_c(cir[i]);
            f[i][0] = tem.x, f[i][1] = tem.y;
            // cout << cir[i] << endl;
        }
        // cout << endl;
        int sum = 0;
        dp[l][1] = 0, dp[l][0] = f[l][0];
        for (int i = l + 1; i < r; i++)
        {

            dp[i][1] = f[i][1] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) + f[i][0];
        }
        sum = max(dp[r - 1][1], dp[r - 1][0]);
        // cout << f[l + 2][0] << endl;
        dp[l][1] = f[l][1], dp[l][0] = 0;
        for (int i = l + 1; i < r; i++)
        {
            dp[i][1] = f[i][1] + dp[i - 1][0];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) + f[i][0];
        }
        sum = max(sum, dp[r - 1][0]);
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}