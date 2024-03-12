#include <bits/stdc++.h>
#define dug(x) cerr << "death" << x << endl
using namespace std;
using i64=long long;
const int N=1010,M=1e9+7;
int g[N][N][4];
int mp[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>mp[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        bool fl=true;
        for(int k=0;k<4;k++)
        {
            int a=i+dx[k],b=j+dy[k];
            if(a>=0&&b>=0&&a<n&&b<m)
            {
                if(mp[a][b]+1==mp[i][j])fl=false;
            }
        }
        if(fl)g[i][j][0]=1;
    }
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> >>,greater<pair<int,pair<int,int> >>> st;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        st.push({mp[i][j],{i,j}});
    }
    while(st.size())
    {
        auto ing=st.top();
        auto x=ing.second.first,y=ing.second.second;
        st.pop();
        for(int k=0;k<4;k++)
        {
             int a=x+dx[k],b=y+dy[k];
            if(a>=0&&b>=0&&a<n&&b<m)
            {
               if(mp[a][b]==mp[x][y]+1)
               {
                   //cout<<a<<b<<x<<y<<endl;
                   for(int z=0;z<4;z++)
                   {
                       g[a][b][min(z+1,3)]=(g[a][b][min(z+1,3)]+g[x][y][z])%M;
                   }
               }
            }
        }
    }
    i64 ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
         bool fl=true;
        for(int k=0;k<4;k++)
        {
            int a=i+dx[k],b=j+dy[k];
            if(a>=0&&b>=0&&a<n&&b<m)
            {
                if(mp[a][b]==mp[i][j]+1)fl=false;
            }
        }
        if(fl)ans=(ans+g[i][j][3])%M;
    }
    cout<<ans<<endl;
    return 0;
}