#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> ans,a(n),q(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)ans.push_back(a[i-1]-a[i]);
    int t;
    cin>>t;
    sort(ans.begin(),ans.end());
    for(int i=1;i<=ans.size();i++)q[i]=q[i-1]+ans[i-1];
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            b=n-b;
            cout<<q[b]<<'\n';
        }
    }
    return 0;
}