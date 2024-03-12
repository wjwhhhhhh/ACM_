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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<Tree_array<int>> tr(31, Tree_array<int>(n));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (a[i] >> j & 1)
                tr[j].insert(i, 1);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int si = r - l + 1;
        array<int, 31> ans = {};
        for (int j = 0; j < 31; j++)
        {
            int tem = tr[j].ask(r) - tr[j].ask(l - 1);
            if (si - tem <= tem)
                ans[j] = 0;
            else
                ans[j] = 1;
        }
        i64 an = 0;
        for (int i = 0; i < 31; i++)
        {
            an += (ans[i] << i);
        }
        cout << an << endl;
    }
    return 0;
}