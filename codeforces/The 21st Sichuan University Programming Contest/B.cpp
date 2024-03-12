#include <bits/stdc++.h>
using namespace std;
using i64=long long;
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
            idx=0;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
  int n,m,s,t,k;
  cin>>n>>m>>s>>t>>k;
  s--,t--;
  UNdigraph gra(n,2*m);
  for(int i=1;i<=m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    gra.insert(a,b,c);
  }
  int l=0,r=k;
  vector<bool> st(n);
  function <bool(int,int)>check=[&](int u,int x)
  {
    for(int i=gra.h[u];~i;i=gra.ne[i])
    {
        int j=gra.e[i];
        if(st[j]||gra.w[i]<x)continue;
        if(j==t)return true;
        st[j]=true;
        if(check(j,x))return true;
    }
    return false;
  };
  while(l<r)
  {
    fill(st.begin(),st.end(),0);
    st[s]=true;
    int mid=l+r+1>>1;
    if(check(s,mid))l=mid;
    else r=mid-1;
  }
  cout<<l<<endl;
    return 0;
}