#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Tree_array
{
    vector<int> tr,mi;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    void init(int n)
    {
        maxx = n;
        tr.assign(n + 1, 0);
        mi.assign(n+1,0x3f3f3f3f)
    }
    void insert(int x, int c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            tr[i]+=c,mi[i]=min(tr[i],mi[i]);
    }
    int ask(int x)
    {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int x, int c)
    {
        tr[x] ^= c;
    }
};
void solve()
{
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}