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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Tree_array<i64> tr(n);
    i64 sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += tr.ask(a[i]);
        tr.insert(a[i], 1);
    }
    cout << sum << endl;
    int ans = sum % 10;
    int si = 0, fa = 1;
    string mi;
    cin >> mi;
    i64 su = 1ll * n * (n - 1) / 2 % 10;
    for (int i = 0; i < m; i++)
    {
        if (mi[i] == 'S')
        {
            ans = (ans - (a[si] - 1) + (n - a[si]) + 10) % 10;
            si = (si + fa + n) % n;
        }
        else
        {
            fa = (fa == 1 ? -1 : 1);
            si = (si + fa + n) % n;
            ans = (su - ans + 10) % 10;
        }
        cout << ans;
    }
    return 0;
}