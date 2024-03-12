#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M=998244353;
struct Tree_array
{
    vector<int> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    void init(int n)
    {
        maxx = n;
        tr.assign(n + 1, 0);
    }
    void insert(int x, int c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(i, c);
    }
    int ask(int x)
    {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            (res += tr[i])%=M;
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int x, int c)
    {
        (tr[x] += c)%=M;
    }
};
void solve()
{
    int n;
    cin>>n;
    vector<int> l(n),r(n),col(n);
    for(int i=0;i<n;i++)cin>>l[i]>>r[i]>>col[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(),o.end(), [&](int x, int y) {return r[x]<r[y];
    });
    i64 ans=0;
    vector<int>has;
    int idx=1;
    map<int,int> li;
    for(int i=0;i<n;i++)
    {
        has.push_back(l[i]);
        has.push_back(r[i]);
    }
    sort(has.begin(),has.end());
    has.erase(unique(has.begin(),has.end()),has.end());
    for(auto x:has)li[x]=idx++;
    Tree_array bu(idx),re(idx);
    for(int i=0;i<n;i++)
    {
        
    }
}
signed main()
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