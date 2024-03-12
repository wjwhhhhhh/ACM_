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
template <class T> struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n = a.size();
        init(n + 1);
        for (int i = 1; i < n; i++)
            insert(i, a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    virtual void op(T &x, T c)
    {
        chkmax(x, c);
    }
};
const int M = 2e5;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        b[i].push_back(a[i][0]);
        for (int j = 1; j < a[i].size(); j++)
        {
            if (a[i][j] > b[i].back())
                b[i].push_back(a[i][j]);
        }
    }
    map<int, int> lisan;
    int idx = 0;
    vector<int> has(1);
    for (int i = 0; i < n; i++)
    {
        for (auto x : b[i])
            has.push_back(x);
    }
    sort(has.begin(), has.end());
    has.erase(unique(has.begin(), has.end()), has.end());
    for (auto x : has)
        lisan[x] = ++idx;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        mp[b[i].back()].push_back(i);
    Tree_array<int> tr(idx);
    int ans = 0;
    for (auto [_x, cnt] : mp)
    {
        int res = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            int siz = b[cnt[i]].size();
            for (int id = 0; id < siz; id++)
            {
                int j = lisan[b[cnt[i]][id]];
                chkmax(res, tr.ask(lisan[has[j - 2]]) + siz - id);
            }
        }
        chkmax(ans, res);
        tr.insert(lisan[_x], res);
    }
    cout << ans << endl;
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