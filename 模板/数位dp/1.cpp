#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
ll c[105][105];
map<array<int,10>,int>dp;
int find(array<int,10>f,int wei)
{
    if(wei==0)return 0;
    if(wei==1)return 1;
    sort(f.begin(),f.end());
    if(dp.find(f)!=dp.end())return dp[f];
    int res=0;
    for(int i=0;i<10;i++)
    {
        if(f[i])
        {
            f[i]--;
            res+=find(f,wei-1);
            f[i]++;
        }
    }
    return dp[f]=res;
}
int dfs(string a)
{
    if(a.size()==0)return 0;
    array<int,10> tem{0};
    for(auto i:a)tem[i-'0']++;
    int ans=0;
    for(int i=0;i<10;i++)
    {
        if(i>a[0]-'0')break;
        else if(i==a[0]-'0'&&a.size()>=1)ans+=dfs(a.substr(1));
        else if(tem[i])
        {
            tem[i]--;
            ans+=find(tem,a.size()-1);
            tem[i]++;
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    c[0][0]=1;
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=100;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=100;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1]);
    }
    cout<<dfs(a);
    return 0;
}