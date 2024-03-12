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
    cout << setprecision(1) << fixed;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> o(n + 1);
    iota(o.begin(), o.end(), 0);
    sort(o.begin() + 1, o.end(), [&](int x, int y) { return a[x] < a[y]; });
    vector<double> ans(n + 1);
    Tree_array<int> tr(n);
    for (int i = 1; i <= n; i++)
        tr.insert(i, 1);
    if (n % 2 == 0)
    {
        int idx = n;
        for (int i = 1; i <= n; i++)
        {
            tr.insert(i, -1);
            while (tr.ask(idx - 1) != (n - 1) / 2)
                idx--;
            ans[o[i]] = a[o[idx]];
            tr.insert(i, 1);
        }
    }
    else
    {
        int idx = n;
        for (int i = 1; i <= n; i++)
        {
            tr.insert(i, -1);
            while (tr.ask(idx - 1) != (n - 1) / 2)
                idx--;
            int tem = idx - 1;
            if (tr.ask(tem) - tr.ask(tem - 1) == 0)
                tem--;
            ans[o[i]] = (a[o[idx]] + a[o[tem]]) / 2.0;
            tr.insert(i, 1);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return 0;
}