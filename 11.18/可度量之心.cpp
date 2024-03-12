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
const int N = 2e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx = 1;
void add(int a, int b, int c) // 添加一条边a->b
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int depth[N], fa[N][32], lg[N];
i64 dist[N];
void dfs(int u, int fath)
{
    fa[u][0] = fath, depth[u] = depth[fath] + 1;
    for (int i = 1; i <= lg[depth[u]]; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = h[u]; i != 0; i = ne[i])
    {
        int j = e[i];
        if (j != fath)
        {
            dist[j] = dist[u] + w[i];
            dfs(j, u);
        }
    }
}
int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    for (int i = lg[depth[x]]; ~i; i--)
    {
        if (depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    }
    if (x == y)
        return x;
    for (int i = lg[depth[x]]; ~i; i--)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
i64 get_dist(int x, int y)
{
    int la = lca(x, y);
    return dist[x] + dist[y] - 2 * dist[la];
}
int main()
{
    int n, m;
    cin >> n >> m;
    lg[0] = -1;
    for (int i = 1; i < N; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, 0);
    while (m--)
    {
        i64 ans = 2e18;
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= n; i++)
            chmin(ans, abs(get_dist(i, x) - get_dist(i, y)));
        cout << ans << endl;
    }
}