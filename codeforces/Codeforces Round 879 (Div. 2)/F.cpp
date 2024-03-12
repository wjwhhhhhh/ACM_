#include <bits/stdc++.h>
using namespace std;
using i64=long long;
vector<int> find(vector<int>a)
{
    int n=a.size();
    vector<int> q(n+1);
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=i+1)
        {
            int r=n-(i+1)+1,l=min(r,a[i]-i);
            q[l]++;
            q[r]--;
            //cout<<l<<" "<<r<<endl;
            //cout<<n-(i+1)<<endl;
        }
        else
        {
            q[0]++,q[n-i]--;
            //cout<<0<<" "<<n-i<<endl;
            q[n-i+a[i]]++;
           // cout<<n-i+a[i]<<endl;
        }
    }
    for(int i=1;i<n;i++)q[i]+=q[i-1];
    //for(int i=0;i<n;i++)cout<<q[i]<<" ";
    return q;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<a.size();i++)cin>>a[i];
    vector<int> ans[2];
    ans[0]=find(a);
    reverse(a.begin(),a.end());
    ans[1]=find(a);
    int k=1,b=0;
    cout<<ans[k==1?0:1][b]<<'\n';
    int t;
    cin>>t;
    while(t--)
    {
        int  flag;
        cin>>flag;
        if(flag==1)
        {
            int v;
            cin>>v;
            b=(b-k*v+n)%n;
        }
        else if(flag==2)
        {
            int v;
            cin>>v;
            b=(b+n+k*v)%n;
        }
        else
        {
            k=-1*k;
            b=(b+n+k)%n;
        }
        cout<<k<<b<<endl;
        cout<<ans[k==1?0:1][b]<<'\n';
    }
    return 0;
}