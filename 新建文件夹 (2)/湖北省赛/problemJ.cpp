#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
int chu(string &a,int m)
{
    int t=0;
    for(int i=0;i<a.size();i++)
    {
        t=t*10+a[i]-'0';
        t%=m;
    }
    return t;
}
void solve()
{
    string l,r;
    cin>>l>>r;
    int m;
    cin>>m;
    int n=r.size()+1;
    r=" "+r;
    int ans=chu(r,m);
    vector<vector<int>> val(n,vector<int>(m));
    val[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int z=0;z<10;z++)
            {
                val[i][(j+z)%m]+=val[i][j];
            }
        }
    }
    vector<vector<int>> val(n,vector<int>(m));
    val[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int z=0;z<10;z++)
            {
                val[i][(j+z)%m]+=val[i][j];
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}