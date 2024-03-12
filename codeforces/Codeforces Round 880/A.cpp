#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=10;
int f[N+N][N][N];
int mp[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d",&n);
    int x,y,c;
    while(scanf("%d%d%d",&x,&y,&c),x||y||c)
    {
        mp[x][y]=c;
    }
    for(int k=1;k<=(2*n-2);k++)
    {
        for(int i=1;i<=n&&i+1<=k;i++)
        {
            for(int j=1;j<=n&&j+1<=k;j++)
            {
                if(i==j)
                {
                    f[k][i][j]=max({f[k-1][i][j],f[k-1][i-1][j-1],
                        f[k-1][i][j-1],f[k-1][i-1][j]})+mp[i][k-i+2];
                }
                else
                {
                    f[k][i][j]=max({f[k-1][i][j],f[k-1][i-1][j-1],
                        f[k-1][i][j-1],f[k-1][i-1][j]})+mp[i][k-i+2]+mp[j][k-j+2];
                }
            }
        }
    }
    cout<<f[2*n-2][n][n];
    return 0;
}