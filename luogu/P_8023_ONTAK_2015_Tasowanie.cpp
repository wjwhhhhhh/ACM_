#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N=6100;
array<int,3> f[N][N];
bool v[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++)cin>>l[i]>>r[i];
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int z=j+1;z<n;z++)
    {
        int dx=l[i]+l[j]+l[z]+3000,dy=r[i]+r[j]+r[z]+3000;
        if(v[dx][dy])
        {
            cout<<"Yes"<<'\n';
            cout<<f[dx][dy][0]<<" "<<f[dx][dy][1]<<" "<<f[dx][dy][2]<<'\n';
            cout<<i<<" "<<j<<" "<<z<<'\n';
        }
        v[dx][dy]=true;
        f[dx][dy]={i,j,z};
    }
    cout<<"No";
    return 0;
}