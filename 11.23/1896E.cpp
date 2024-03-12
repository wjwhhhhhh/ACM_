#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
        x++;
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        x++;
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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    vector<vector<int>> que(2 * n);
    vector<vector<two>> ask(2 * n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= i)
        {
            ask[i].push_back(two{a[i], a[i]}), que[i].push_back(a[i]);
            que[i + n].push_back(a[i] + n);
        }
        else
            ask[i].push_back(two{a[i] + n, a[i]}), que[i].push_back(a[i] + n);
    }
    Tree_array<int> tr(2 * n);
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        for (auto c : que[i])
            tr.insert(c, 1);
        for (auto [x, y] : ask[i])
            ans[y] = tr.ask(x);
    }
    // cout << ans[2] << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= i)
        {
            ans[a[i]] = a[i] - i - (ans[a[i]] - 1);
        }
        else
        {
            ans[a[i]] = a[i] + n - i - (ans[a[i]] - 1);
        }
    }
    for (auto c : ans)
        cout << c << " ";
    cout << '\n';
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