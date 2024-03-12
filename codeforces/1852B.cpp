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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        if (a[0] <= 1)
        {
            cout << "YES" << endl;
            if (a[0] == 0)
                cout << "-1" << endl;
            else
                cout << "1" << endl;
        }
        else
            cout << "NO" << endl;
        return;
    }
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    Tree_array<int> tr(n + 1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        tr.insert(1, 1);
        tr.insert(a[o[i]] + 1, -1);
    }
    for (int i = 0; i < n; i++)
    {
        if (tr.ask(n - i) != a[o[i]])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[o[i]] >= n - i)
        {
            last = i;
            break;
        }
    }
    // vector<int> ans(n);
    int r = n;
    int th = n;
    int idx = 0;
    while (idx < n && a[o[idx]] == 0)
    {
        ans[o[idx]] = -n;
        r = n - 1;
        idx++;
    }
    for (int i = idx; i < last; i++)
    {
        if (n - a[o[i]] < th)
        {
            ans[o[i]] = -r + 1;
            for (int j = n - a[o[i]]; j < th; j++)
                ans[o[j]] = r;
            r -= 2;
            th = n - a[o[i]];
        }
        else
        {
            ans[o[i]] = -r;
            r--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[o[i]] == 0)
        {
            // cerr << r << endl;
            if (i < last)
                ans[o[i]] = -r;
            else
                ans[o[i]] = r;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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