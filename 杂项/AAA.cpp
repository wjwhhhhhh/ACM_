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
const int M = 998244353;
template <class Info, class Tag> struct Lazy_SegmentTree
{
    int n;
    vector<Info> info;
    vector<Tag> tag;
    Lazy_SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4 * n);
        tag.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(a[l - 1]);
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
            info[p] = info[p << 1] + info[p << 1 | 1];
        };
        build(1, 1, n);
    }
    void modify(int p, int l, int r, int x, int c)
    {
        if (x == l && l == r)
        {
            info[p].init(c);
            return;
        }
        pushdown(p, l, r);
        int mid = l + r >> 1;
        if (x <= mid)
            modify(p << 1, l, mid, x, c);
        else
            modify(p << 1 | 1, mid + 1, r, x, c);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int x, int c)
    {
        modify(1, 1, n, x, c);
    }
    void update(int p, int l, int r, int ll, int rr)
    {
        if (l == ll && r == rr)
        {
            info[p].val = info[p].val * 2 % M;
            tag[p].w = tag[p].w * 2 % M;
            return;
        }
        pushdown(p, l, r);
        int mid = l + r >> 1;
        if (ll <= mid)
            update(p << 1, l, mid, ll, min(rr, mid));
        if (rr > mid)
            update(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void update(int l, int r)
    {
        if (l > r)
            return;
        update(1, 1, n, l, r);
    }
    void pushdown(int p, int l, int r)
    {
        if (l != r)
        {
            int mid = l + r >> 1;
            info[p << 1].val = info[p << 1].val * tag[p].w % M, tag[p << 1].w = tag[p << 1].w * tag[p].w % M;
            info[p << 1 | 1].val = info[p << 1 | 1].val * tag[p].w % M,
                          tag[p << 1 | 1].w = tag[p << 1 | 1].w * tag[p].w % M;
        }
        tag[p].clear();
        return;
    }
    Info query(int p, int l, int r, int ll, int rr)
    {
        if (ll == l && rr == r)
        {
            return info[p];
        }
        pushdown(p, l, r);
        int mid = l + r >> 1;
        if (ll <= mid && rr <= mid)
            return query(p << 1, l, mid, ll, min(rr, mid));
        else if (rr > mid && ll > mid)
            return query(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
        else
            return query(p << 1, l, mid, ll, min(rr, mid)) + query(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr);
    }
    Info query(int l, int r)
    {
        if (l > r)
            return Info();
        return query(1, 1, n, l, r);
    }
};
struct Tag;
struct Info
{
    i64 val;
    Info() : val(0)
    {
    }
    void init(int x)
    {
        val += x;
        val %= M;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info c;
        c.val = a.val + b.val;
        c.val %= M;
        return c;
    }
};
struct Tag
{
    i64 w;
    Tag() : w(1)
    {
    }
    void clear()
    {
        w = 1;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n), col(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i] >> col[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return (l[x] == l[y] && r[x] < r[y]) || (l[x] < l[y]); });
    vector<int> has;
    for (int i = 0; i < n; i++)
        has.push_back(l[i]), has.push_back(r[i]);
    sort(has.begin(), has.end());
    has.erase(unique(has.begin(), has.end()), has.end());
    map<int, int> mp;
    int idx = 0;
    for (auto x : has)
    {
        mp[x] = ++idx;
    }
    vector<int> oo(idx);
    vector<Lazy_SegmentTree<Info, Tag>> seg(2, oo);
    i64 ans = 1;
    for (int i = 0; i < n; i++)
    {
        // cerr << "ok" << endl;
        int x = mp[l[o[i]]], y = mp[r[o[i]]], co = col[o[i]];
        auto get = seg[co].query(x, y).val + 1;
        get += seg[0].query(1, x - 1).val + seg[1].query(1, x - 1).val;
        get %= M;
        seg[co].modify(y, get);
        get += seg[co].query(y + 1, idx).val;
        get %= M;
        seg[co].update(y + 1, idx);
        ans = (get + ans) % M;
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