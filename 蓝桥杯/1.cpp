#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2e5+10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    bool ans[N+10];
    for(int i=1;i<a.size();i++)
    {
        if(a[i]==a[i-1])ans[1]=true;
    }
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int j=0;j<a.size();j++)
    {
        for(int i=0;i<j&&a[i]*a[i]<=a[j];i++)
        {
            if(a[j]%a[i]==0)ans[a[j]/a[i]]=true;
        }
    }
    while(q--)
    {
        int aa;
        cin>>aa;
        if(aa>=N||ans[aa]==false)
        {
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}