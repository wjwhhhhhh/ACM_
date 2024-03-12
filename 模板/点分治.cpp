#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size, edge_size;
    Graph()
    {
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n, int m)
    {
        node_size = n;
        edge_size = m;
        idx = 0, e.resize(m), ne.resize(m), w.resize(m);
        h.resize(n, -1);
    }
    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c)
    {
        w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void clear(int si = 0) // 清空图
    {
        if (si == 0)
            si = node_size;
        idx = 0;
        fill(h.begin(), h.begin() + si, -1);
    }
    void dfs(int u, int fath = -1)
    {
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    }
};
struct UNdigraph : Graph // 无向图
{
    static const int W = 25;
    vector<array<int, W>> fa;
    vector<int> depth;
    bool is_use;
    int root;
    UNdigraph()
    {
    }
    UNdigraph(int n, int m) : Graph(n, 2 * m)
    {
        node_size = n, edge_size = m;
        is_use = false;
        root = 0;
    }
    void dfs(int u, int fath)
    {
        fa[u][0] = fath, depth[u] = depth[fath] + 1;
        // cerr<<depth[u]<<" "<<u<<endl;
        for (int i = 1; i < W; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    }
    int lca(int x, int y)
    {
        if (!is_use)
        {
            // cerr<<node_size;
            depth.resize(node_size);
            fa.resize(node_size);
            dfs(root, root);
            is_use = true;
        }
        if (depth[x] < depth[y])
            swap(x, y);
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (depth[fa[x][i]] >= depth[y])
                x = fa[x][i];
        }
        // cout<<x<<y<<endl;
        if (x == y)
            return x;
        for (int i = __lg(depth[x]); ~i; i--)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }

    vector<int> cut_point() // 割点
    {
        vector<int> dfn(node_size), low(node_size), vis(node_size), flag(node_size);
        int inde, res;

        function<void(int, int)> Tarjan = [&](int u, int father) { // u 当前点的编号，father 自己爸爸的编号
            vis[u] = true;                                         // 标记
            low[u] = dfn[u] = ++inde;                              // 打上时间戳
            int child = 0;                                         // 每一个点儿子数量
            for (int i = h[u]; ~i; i = ne[i])
            {
                int v = e[i];
                if (!vis[v])
                {
                    child++;                      // 多了一个儿子
                    Tarjan(v, u);                 // 继续
                    low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
                    if (father != u && low[v] >= dfn[u] && !flag[u])
                    {
                        flag[u] = true;
                        res++; // 记录答案
                    }
                }
                else if (v != father)
                    low[u] = min(low[u], dfn[v]); // 如果这个点不是自己，更新能到的最小节点编号
            }
            if (father == u && child >= 2 && !flag[u])
            {
                flag[u] = true;
                res++; // 记录答案
            }
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!vis[i])
            {
                inde = 0;
                Tarjan(i, i);
            }
        }
        vector<int> p;
        for (int i = 0; i < node_size; i++)
            if (flag[i])
                p.push_back(i);
        return p;
    };
    vector<int> cut_edge()
    {
        vector<int> dfn(node_size), low(node_size), vis(node_size), bridge(edge_size);
        int inde, res;
        function<void(int, int)> tarjan = [&](int x, int in_edge) {
            dfn[x] = low[x] = ++inde;
            for (int i = h[x]; ~i; i = ne[i])
            {
                int y = e[i];
                if (!dfn[y])
                {
                    tarjan(y, i);
                    low[x] = min(low[x], low[y]);
                    if (low[y] > dfn[x])
                        bridge[i / 2] = true;
                }
                else if (i != (in_edge ^ 1))
                    low[x] = min(low[x], dfn[y]);
            }
        };
        for (int i = 0; i < node_size; i++)
        {
            if (!vis[i])
            {
                inde = 0;
                tarjan(i, i);
            }
        }
        vector<int> p;
        for (int i = 0; i < edge_size; i++)
            if (bridge[i])
                p.push_back(i);
        return p;
    }
    friend istream &operator>>(istream &in, UNdigraph &gra)
    {
        // TODO: 在此处插入 return 语句
        for(int i=0;i<gra.edge_size;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            gra.insert(a,b);
        }
        return in;
    }
};
struct Point_divide:UNdigraph //点分治
{
    vector<int> vis,siz,mx;
    vector<int>que,st;
    set<int> has;
    Point_divide(int n):UNdigraph(n,n-1)
    {
        root=-1;
        vis.resize(n);
        siz.resize(n);
        mx.resize(n);
    }
    void get_dis(int u,int fa,int dis)
    {
        has.insert(dis);
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(j==fa||vis[j])continue;
            get_dis(j,u,dis+w[i]);
        }
    }
    void calc(int u)
    {
        set<int> ing;
        ing.insert(0);
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(vis[j])continue;
            has.clear();
            get_dis(j,u,w[i]);
            for(int i=0;i<que.size();i++)
            {
                if(st[i])continue;
                for(auto x:has)
                {
                    if(ing.find(que[i]-x)!=ing.end())
                    {
                        st[i]=true;
                        break;
                    }
                }
            }
        }
    }
    void find(int u,int fa=-1)
    {
        siz[u]=1,mx[u]=0;
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(j==fa||vis[j])continue;
            find(j,u);
            siz[u]+=siz[j];
            chkmax(mx[u],siz[j]);
        }
        chkmax(mx[u],node_size-siz[u]);
        if(root<0||mx[u]<mx[root])
        {
            root=u;
        }
    }
    void solve(int u)
    {
        vis[u]=true;
        calc(u);
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(vis[j])continue;
            root=-1;
            node_size=siz[j];
            find(j,-1);
            find(root,-1);
            solve(root);
        }
    }
    void work()
    {
        find(0,-1);
        find(root,-1);
        solve(root);
    }

};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    Point_divide po(n);
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        po.que.push_back(a);
        po.st.push_back(0);
        if(a==0)po.st.back()=true;
    }
    return 0;
}