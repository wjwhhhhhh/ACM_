#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    bool fl=true;
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]!=a[n-i+1])fl=false;
    }
    if(fl)
    {
        cout<<"0"<<endl;
        return ;
    }
    queue<int> q;
    int res;
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]==a[n-i+1])continue;
        q.push(abs(a[i]-a[n-i+1]));
    }
    if(q.size()==1)cout<<q.front()<<'\n';
    else
    {
        int x=q.front();q.pop();
        res=x;
        while(q.size())
        {
            int y=q.front();
            q.pop();
            res=__gcd(res,y);
        }
        cout<<res<<'\n';
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
        solve();
    }
    return 0;
}