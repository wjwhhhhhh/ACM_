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
std::map<int, int> mp;
void dfs(vector<int>&dep,int root,Graph &gra)
{
    for(int i=gra.h[root];~i;i=gra.ne[i])
    {
        int j=gra.e[i];
        dep[j]=dep[root]+1;
        mp[dep[j]]++;
    }
}
void solves()
{
    int n;
    Graph gra(n,n);
    mp.clear();
    vector<int> dep(n+1);
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        gra.add(a,i);
    }
    dep[1]=1;
    mp[1]++;
    dfs(dep,1,gra);
    int ans=mp.size();
    vector<int> res;
    for(auto [x,y]:mp)
    {
        res.push_back(y);
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        ans=min(ans,res[i]+res.size()-i);
    }
    cout<<ans<<'\n';
}
int main()
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