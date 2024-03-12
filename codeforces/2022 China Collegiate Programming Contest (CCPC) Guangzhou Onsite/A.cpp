#include <bits/stdc++.h>
#define int long long
using namespace std;
#include <bits/stdc++.h>
using namespace std;
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size;
    Graph()
    {
    }
    Graph(int n)
    {
        init(n);
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n)
    {
        node_size = n;
        idx = 0;
        e.resize(2 * n), ne.resize(2 * n), w.resize(2 * n);
        h.resize(n, -1);
    }
    void init(int n, int m)
    {
        node_size = n;
        idx = 0, e.resize(m), ne.resize(m), w.resize(2 * n);
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
        fill(h.begin(), h.begin() + si, -1);
    }
    void dfs(int u,int fath=-1)
    {
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(j!=fath)
            {
                dfs(j,u);
            }
        }
    }
};
struct UNdigraph : Graph // 无向图
{
    UNdigraph()
    {
    }
    UNdigraph(int a) : Graph(a)
    {
    }
    UNdigraph(int n, int m) : Graph(n, m)
    {
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }
};
const int N=2010;
int a[N];
int t[N];
UNdigraph gra(N);
int dp[N][N][2];
int leaf[N];
void dfs(int u,int fath)
{

}
void solves()
{
    int n;
    cin>>n;
    gra.clear(n+5);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        gra.insert(a,b);
    }
    dfs(1,0);
    cout<<dp[1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solves();
    }
    return 0;
}