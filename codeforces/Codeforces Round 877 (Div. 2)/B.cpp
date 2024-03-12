#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int a1,a2,an;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)a1=i;
        if(a[i]==2)a2=i;
        if(a[i]==n)an=i;
    }
    if((a1>an&&an>a2)||(a1<an&&an<a2))
    {
        cout<<"1 1"<<endl;
        return ;
    }
    if(abs(a1-an)<abs(a2-an))
    {
        cout<<a1<<" "<<an<<endl;
        return ;
    }
    else
    {
        cout<<a2<<" "<<an<<endl;
        return ;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}