#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
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
            res += tr[i];
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int x, int c)
    {
        tr[x] += c;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return l[x] < l[y]; });
    int now = 0, id = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = 0;
    while (id < n || !q.empty())
    {
        if (q.size())
        {
            if (q.top() >= now)
                ans++, now++, q.pop();
            while (q.size() && q.top() < now)
                q.pop();
            while (id < n && l[o[id]] == now)
                q.push(r[o[id++]]);
            // cout << top(() << endl;
        }
        else
        {
            now = l[o[id]];
            while (id < n && l[o[id]] == now)
                q.push(r[o[id++]]);
        }
    }
    cout << ans << '\n';
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