#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx = 1, w[M];
void add(int a, int b, int c) // 添加一条边a->b
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int depth[N], fa[N][32], lg[N];

int lca(int x, int y)
{
    // cout<<x<<y<<endl;
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
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    lg[0] = -1;
    for (int i = 1; i < N; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    vector<int> er(n+1,0);
    function<void(int, int)> dfs = [&](int u, int fath) {//点权下放
        fa[u][0] = fath, depth[u] = depth[fath] + 1;
        for (int i = 1; i <= lg[depth[u]]; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = h[u]; i != 0; i = ne[i])
        {
            int j = e[i],ww=w[i];
            if (j != fath)
            {
                er[u]-=ww;
                er[j]+=ww;
                dfs(j, u);
            }
        }
    };
    dfs(1, 0);
    while (m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int fath=lca(a,b);
        er[a]+=c,er[b]+=c,er[fath]-=2*c;
    }
    function<void(int, int)> dfs1 = [&](int u, int fath) {//根据差分求距离
        for (int i = h[u]; i != 0; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs1(j, u);
                er[u]+=er[j];
            }
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int fath) {//前缀和
        er[u]+=er[fath];
        for (int i = h[u]; i != 0; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs2(j, u);
            }
        }
    };
    dfs1(1,0);
    dfs2(1,0);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int fath=lca(x,y);
        cout<<er[x]+er[y]-2*er[fath]<<endl;
    }
}