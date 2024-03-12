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
        x += c;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    int m;
    cin >> m;
    int q;
    cin >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    vector<int> time(n), siz(n);
    int timestamp = 1;
    function<void(int)> dfs = [&](int u) {
        siz[u] = 1;
        time[u] = timestamp++;
        for (auto x : g[u])
        {
            dfs(x);
            siz[u] += siz[x];
        }
    };
    dfs(0);
    vector<pair<int, int>> has(m);
    for (int i = 0; i < m; i++)
        cin >> has[i].first >> has[i].second;
    for (int i = 0; i < m; i++)
        has[i].first--, has[i].second--;
    sort(has.begin(), has.end(), [&](pair<int, int> x, pair<int, int> y) { return time[x.first] > time[y.first]; });
    vector<int> a(q), b(q), ans(q);
    for (int i = 0; i < q; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < q; i++)
        a[i]--, b[i]--;
    vector<int> o(q);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return time[a[x]] > time[a[y]]; });

    Tree_array<int> tr(n + 1);
    function<void(int)> dfs2 = [&](int u) {
        vector<int> out;
        while (has.size() && has.back().first == u)
        {
            out.push_back(time[has.back().second]);
            tr.insert(time[has.back().second], 1);
            has.pop_back();
        }
        while (o.size() && a[o.back()] == u)
        {
            ans[o.back()] = tr.ask(time[b[o.back()]] + siz[b[o.back()]] - 1) - tr.ask(time[b[o.back()]] - 1);
            o.pop_back();
        }
        for (auto x : g[u])
        {
            dfs2(x);
        }
        for (auto x : out)
            tr.insert(x, -1);
    };
    dfs2(0);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}