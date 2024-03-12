#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
int fa[N];
bool in[N];
int ans = 0, anssum = 0;
int cir[2 * N], en[2 * N], cnt, cir_size;
int f1[2 * N][2], f2[N][2];
bool st[N];
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs_h(int u) // 找环
{
    st[u] = in[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        fa[j] = u;
        if (!st[j])
            dfs_h(j);
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
int ki;
int dfs_c(int u)
{
    st[u] = true;
    int tem1 = 0x3f3f3f3f, tem2 = 0x3f3f3f3f;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            dfs_c(j);
            f1[u][0] += max(f1[j][1], f1[j][0]);
            f2[u][0] += max(f2[j][1], f2[j][0]);
            tem1 = min(tem1, max(f1[j][1], f1[j][0]) - f1[j][0]);
            tem2 = min(tem2, max(f2[j][1], f2[j][0]) - f2[j][0]);
        }
    }
    f1[u][1] = f1[u][0] - tem1 + 1, f2[u][1] = f2[u][0] - tem2 + 1;

    if (u == ki)
        f2[u][1] = f2[u][0] + 1;
    // if (u == 10)
    //     cout << ki;
    return max({f1[u][0], f1[u][1], f2[u][0]});
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        add(b, i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            dfs_h(i);
        }
    }
    memset(st, 0, sizeof st);
    for (int i = 0; i < cir_size; i++)
    {
        int r = en[i], l = en[i] - 1;
        ki = cir[r];
        ans += dfs_c(cir[l]);
        // cout << cir[l] << endl;
    }
    cout << ans << endl;
    return 0;
}
// 5
// 1 2 1 5 4