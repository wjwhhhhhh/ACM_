#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
pair<int,int> a[N];
int w[N];
void solves()
{
    int n,k,p;
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i,w[i]=a[i].first;
    if(k*p>=n)
    {
        sort(a+1,a+n+1);
        int si=n-(k-1)*p;
        if(si==1)
        {
            long long res=0;
            for(int i=1;i<=n;i++)res+=w[i];
            cout<<res<<'\n';
        }
        else
        {
            long long res=0,sum=0;
            for(int i=1;i<=n;i++)res+=w[i];
            for(int i=1;i<=k;i++)sum+=a[i].first;
                cout<<res<<' '<<sum<<'\n';
        }
    }
    else
    {
        int who=-1;
        vector<int> ans,tem,tem2;
        for(int i=1;i<=1+k*p;i++)
        {
            if(who==-1||w[who]>w[i])who=i;
        }
        sort(a+who+1,a+n+1);
        ans.push_back(w[who]);
        for(int i=1;i<who;i++)tem.push_back(w[i]);
        for(int i=1;i<k*p-who+1;i++)
        {
            tem.push_back(a[i+who].first);
        }
        sort(tem.begin(),tem.end());
        for(int i=k*p-who+1)
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}