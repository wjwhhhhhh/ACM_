#include <bits/stdc++.h>
#define int long long
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
struct DSU
{
    std::vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
struct EDGE
{
    int fr, to, w;
    void init(int a, int b, int c)
    {
        fr = a, to = b, w = c;
    }
    friend bool operator<(const EDGE &x, const EDGE &y)
    {
        return x.w < y.w;
    }
};
const int N=3100;
i64 dp[N][N]={};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> ff(n),col(n);
    for(int i=0;i<n;i++)cin>>col[i];
    for(int i=0;i<n;i++)cin>>ff[i];
    vector<EDGE> Edge(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        Edge[i].init(a,b,c);
    }
    sort(Edge.begin(),Edge.end());
    for(int i=0;i<n;i++)
    {
        dp[i][col[i]]=0;
        dp[i][!col[i]]=-ff[i];
    }
    DSU f(n);
    for(auto [x,y,z]:Edge)
    {
        int u=f.find(x),v=f.find(y);
        vector<i64> tmp(f.size(u)+f.size(v)+1,-1e16);
        for(int i=0;i<=f.size(u);i++)
        {
            for(int j=0;j<=f.size(v);j++)
            tmp[i+j]=max({tmp[i+j],dp[u][i]+dp[v][j]+(f.size(u)-i)*j*z+(f.size(v)-j)*i*z});
        }
        f.merge(u,v);
        u=f.find(u);
        for(int i=0;i<=f.size(u);i++)dp[u][i]=tmp[i];
    }
    i64 ans=0;
    int tr=f.find(0);
    for(int i=0;i<=n;i++)ans=max(ans,dp[tr][i]);
        cout<<ans<<endl;
    return 0;
}