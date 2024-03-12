#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int l = 0;
map<int, int> lisan;
int n, m;
void in(int tem)
{
    if (lisan.find(tem) == lisan.end())
    {
        lisan[tem] = ++l;
    }
}
int find(int tem)
{
    return lisan[tem];
}
int tr[N];
int lowbit(int x)
{
    return x & -x;
}
void appdate(int x)
{
    for (int i = x; i <= n; i += lowbit(i))tr[i]++;
}
int ask(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
        return res;
}
void solves()
{
    cin >> n >> m;
    vector< pair<int, int> > a(n + 5);
    vector<int> ans(n + 5), rk(n + 5), w(n + 5), q(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        w[i] = a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        q[i] = q[i - 1] + a[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        rk[a[i].second] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        in(a[i].first);
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = w[i] * rk[i] - q[rk[i]];
        int si=ask(find(w[i]));
        ans[i]+=si;
        appdate(find(w[i]));
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]>=m-1)cout<<"-1"<<'\n';
        else cout<<ans[i]<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solves();
    }
    return 0;
}