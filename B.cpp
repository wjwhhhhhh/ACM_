#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
const int N=1e5+10;
long long f[N];
long long p[N];
long long d[N];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>d[i];
    set<int> ans;
    vector<int>cnt;
    for(int i=m;i;i--)
    {
        ans.insert(m/i);
    }
    for(auto i:ans)cnt.push_back(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<cnt.size();j++)
        {
            f[cnt[j]/d[i]]=max(f[cnt[j]/d[i]],f[cnt[j]]+cnt[j]*p[i]);
        }
    }
    long long tem=0;
    for(int i=0;i<=m;i++)tem=max(tem,f[i]);
        cout<<tem<<endl;
    return 0;
}