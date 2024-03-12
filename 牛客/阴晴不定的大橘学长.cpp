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
    int n, x;
    cin >> n >> x;
    vector<i64> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    vector<i64> has;
    has.push_back(-1e18), has.push_back(1e18);
    for (int i = 0; i <= n; i++)
        has.push_back(s[i]);
    sort(has.begin(), has.end());
    has.erase(unique(has.begin(), has.end()), has.end());
    int idx = 0;
    map<i64, int> mp;
    for (int i = 0; i < has.size(); i++)
        mp[has[i]] = idx++;
    Tree_array<int> tr(idx);
    tr.insert(mp[0], 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        auto te = upper_bound(has.begin(), has.end(), s[i] - x) - has.begin();
        ans += tr.ask(te - 1);
        // cout << ans << endl;
        tr.insert(mp[s[i]], 1);
    }
    cout << ans << endl;
    return 0;
}