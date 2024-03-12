#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<i64, 2>;
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
template <class T> struct stable
{
    static const int K = 20;
    vector<array<T, K>> f;
    int si;
    stable(vector<T> &a)
    {
        si = a.size();
        f.resize(si);
        work(a);
    }
    void work(vector<T> &a) // 默认从0开始
    {
        for (int i = 0; i < si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < si; i++)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual T op(const T &x, const T &y)
    {
        return max(x, y);
    }
};
template <class T> struct SST
{
    static const int K = 20;
    vector<array<T, K>> f;
    int si;
    SST(vector<T> &a)
    {
        si = a.size();
        f.resize(si);
        work(a);
    }
    void work(vector<T> &a) // 默认从0开始
    {
        for (int i = 0; i < si; ++i)
        {
            f[i][0] = a[i];
        }
        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < si; i++)
            {
                f[i][j] = op(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T ask(int l, int r)
    {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    }
    virtual T op(const T &x, const T &y)
    {
        return min(x, y);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> o(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto &[c, cnt] : mp)
    {
        sort(cnt.begin(), cnt.end());
    }
    stable<int> sa(a);
    SST<int> sb(b);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return b[x] < b[y]; });
    for (int i = 0; i < n; i++)
    {
        int id = o[i];
        if (b[id] == a[id])
            continue;
        if (b[id] < a[id])
        {
            cout << "NO" << endl;
            return;
        }
        if (mp[b[id]].size() == 0)
        {
            cout << "NO" << endl;
            return;
        }
        int l = 0, r = mp[b[id]].size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (mp[b[id]][mid] < id)
                l = mid;
            else
                r = mid - 1;
        }
        bool fl = false;
        l = mp[b[id]][l];
        if (l < id && sa.ask(l, id) <= b[id] && sb.ask(l, id) >= b[id])
        {
            fl = true;
        }
        l = 0, r = mp[b[id]].size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (mp[b[id]][mid] > id)
                r = mid;
            else
                l = mid + 1;
        }
        r = mp[b[id]][l];
        if (r > id && sa.ask(id, r) <= b[id] && sb.ask(id, r) >= b[id])
        {
            fl = true;
        }
        if (!fl)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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