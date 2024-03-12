#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin>>n;
    string a;
    cin>>a;
    a=" "+a;
    int p;
    cin>>p;
    int idx=-1;
    vector<int> all(n+1,-1);
    for(int i=0;i<p;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1)
        {
            a[y]=char(z);
            all[y]=++idx;
        }
        else ++idx;
    }
    if(idx==-1)
    {
        for(int i=1;i<=n;i++)cout<<a[i];
    }
    else 
    {
        
    }
    return 0;
}