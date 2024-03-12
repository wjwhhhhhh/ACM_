#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int M=1e9+7;
i64 qmi(i64 p,i64 k,i64 M)
{
    i64 res=1;
    while(k)
    {
        if(k&1)res=res*p%M;
        p=p*p%M;
        k>>=1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    using tr=array<int,3>;
    vector<tr> all(m);
    for(int i=0;i<m;i++)
    for(int j=0;j<3;j++)cin>>all[i][j];
    vector<int> has(1,-1);
    has.push_back(t);
    for(int i=0;i<n;i++)
    {
        has.push_back(all[i][1]);
        has.push_back(all[i][1]-1);
        has.push_back(all[i][2]);
        has.push_back(all[i][2]+1);
    }
    sort(has.begin(),has.end());
    has.erase(unique(has.begin(),has.end()),has.end());
    vector<int> ss(has.size());
    auto get=[&](int x)
    {
        return lower_bound(has.begin(),has.end(),x)-has.begin();
    };
    ss[0]=n;
    for(int i=0;i<m;i++)
    {
        ss[get(all[i][1])]--;
        ss[get(all[i][2]+1)]++;
    }
    for(int i=1;i<ss.size();i++)ss[i]+=ss[i-1];
    i64 ans=1;
    while(s<=t)
    {
        int id=get(s);
        int tr=min(t,has[id])-s+1;
        ans*=qmi(ss[id],tr,M);
        ans%=M;
        s=min(t,has[id])+1;
    }
    cout<<ans<<endl;
}