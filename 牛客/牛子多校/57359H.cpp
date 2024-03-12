#include <bits/stdc++.h>
const int bug=true;
#define dug(x) if(bug)cerr << "death" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
int dp[210][210];
int f[210][210];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> si(n+1),wi(n+1);
    for(int i=1;i<=n;i++)cin>>si[i]>>wi[i];
    vector<int> wl(m),w;
    for(int i=0;i<m;i++)cin>>wl[i];
    int siz=1;
    for(int i=m-1;i>=0&&siz<=200;i--,siz++)w.push_back(wl[i]);
    reverse(w.begin(),w.end());

    for(int i=1;i<=n;i++)
    {
        for(int j=si[i];j<=200;j++)f[i][j]=wi[i];
        for(int j=1;j<i;j++)
        {
            for(int z=200;z>=si[i];z--)
            {
                f[j][z]=max(f[j][z],f[j][z-si[i]]+wi[i]);
            }
        }
        for(int j=0;j<w.size();j++)
        {
            int res=0;
            for(int z=i;z>0;z--)
            {
                res=max(res,f[z][w[j]]);
                dp[i][j]=max(dp[i][j],res+dp[z-1][j-1]);
            }
        }
    }
    //dug(dp[n][w.size()-1]);
    cout<<dp[n][w.size()-1]<<endl;
    return 0;
}