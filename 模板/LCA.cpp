#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e5+10,M=2*N;
int h[N],e[M],ne[M],idx=1;
void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
int depth[N],fa[N][32],lg[N];
void dfs(int u,int fath)
{
    fa[u][0]=fath,depth[u]=depth[fath]+1;
    for(int i=1;i<=lg[depth[u]];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=h[u];i!=0;i=ne[i])
    {
        int j=e[i];
        if(j!=fath)
        {
            dfs(j,u);
        }
    }
}
int lca(int x,int y)
{
      // cout<<x<<y<<endl;
    if(depth[x]<depth[y])swap(x,y);

    for(int i=lg[depth[x]];~i;i--)
    {
        if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
    }
    if(x==y)return x;
    for(int i=lg[depth[x]];~i;i--)
    {
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i],y=fa[y][i];
        }
    }
    return fa[x][0];
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    lg[0]=-1;
    for(int i=1;i<N;i++)lg[i]=lg[i>>1]+1;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin >> a>>b;
        add(a,b),add(b,a);
    }
    dfs(s,0);
    while (m -- )
    {
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}