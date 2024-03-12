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
void solve()
{
    int n;
    cin >> n;
    int ans=0;
    vector<int> a(n*n+1,-1);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i*j]=1;
    for(int i=n*n;i>=1;i--)
    {
        if(a[i]==-1)continue;
        vector<vector<int>> t(n);
        int cur=-i;
        bool fl=false;
        for(int j=n;j>0;j--)
        {
            int num=min(i/j,n);
            if(num<1)
            {
                fl=true;
                break;
            }
            t[num-1].push_back(j);
        }
        if(fl)break;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i+1);
            bool fl=false;
            for(auto x:t[i])
            {
                
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}