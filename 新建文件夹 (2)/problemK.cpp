#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
template <class Info> struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(a[l] - a[l - 1]);
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
            // cerr << c << endl;
            return;
        }
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
    Info query(int p, int l, int r, int ll, int rr)
    {

        if (ll == l && rr == r)
        {
            return info[p];
        }
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
struct Info
{
    int val;
    int w;
    Info() : val(0), w(0)
    {
    }
    void init(int x)
    {
        w += x;
        val = (w >= 0 ? w : 0);
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        ans.val = a.val + b.val;
        return ans;
    }
};
struct Tree_array
{
    vector<int> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    void init(int n)
    {
        maxx = n;
        tr.assign(n + 1, 0);
    }
    Tree_array(vector<int> a)
    {
        int n = a.size();
        init(n + 1);
        for (int i = 1; i < n; i++)
            insert(i, a[i] - a[i - 1]);
    }
    void insert(int x, int c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    int ask(int x)
    {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int &x, int c)
    {
        x += c;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree<Info> seg(a);
    Tree_array tr(a);
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            // cerr << "kl";
            seg.modify(l, x), seg.modify(r + 1, -1 * x);
            tr.insert(l, x), tr.insert(r + 1, -1 * x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << tr.ask(l) + seg.query(l + 1, r).val << endl;
        }
    }
    return 0;
}