#include <bits/stdc++.h>
using namespace std;
void solves()
{
    int n;
    cin >> n;
    vector<int> f(n),a,ans;
    for(int i=0;i<n;i++)cin>>f[i];
        a.push_back(f[0]);
    for(int i=1;i<n;i++)
    {
        if(f[i]!=f[i-1])a.push_back(f[i]);
    }
    ans.push_back(a[0]);
    for(int i=1;i<a.size()-1;i++)
    {
        if((a[i]<a[i+1])^(a[i]>a[i-1]))ans.push_back(a[1]);
    }
    if(a.size()!=1)ans.push_back(a[a.size()-1]);
    cout<<ans.size()<<'\n';
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