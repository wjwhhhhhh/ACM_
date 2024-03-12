#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cerr << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e6 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx = 0;
int n, m;
int fa[N], fa_w[N];
bool v[M];
bool in[N];
int cir[2 * N], en[2 * N], cnt, cir_size;
int sum[2 * N], f[2 * N], cir_sum[2 * N], dp[2 * N];
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
        fa[j] = u, fa_w[j] = w[i];
        if (!st[j])
            dfs_h(j, u);
        else if (in[j])
        {
            cir_sum[cnt] = 0;
            cir[cnt++] = fa[j];
            for (int k = u; k != j; k = fa[k], cnt++)
            {
                cir[cnt] = fa[k];
                cir_sum[cnt] = cir_sum[cnt - 1] + fa_w[k];
            }
            en[cir_size++] = cnt;
            cir_sum[cnt] = cir_sum[cnt - 1] + fa_w[j];
            cir[cnt++] = u;
        }
    }
    in[u] = false;
}
vector<vector<int>> son(N);
vector<int> ans;
void dfs_c1(int u)
{
    st[u] = true;
    ans.push_back(u);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            son[u].push_back(j);
        }
    }
    sort(son[u].begin(), son[u].end());
    for (auto i : son[u])
    {
        dfs_c1(i);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> b >> a;
        add(a, b), add(b, a);
    }
    if (m == n + 1)
    {
        dfs_c1(1);
    }
    else
    {
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
        }
    }
    for (auto i : ans)
        cout << i << " ";
    return 0;
}