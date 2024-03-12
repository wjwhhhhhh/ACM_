#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace Eula
{
struct Tag;
struct Info // 信息
{
    i64 val;
    i64 w;
    Info() : val(0), w(0)
    {
    }
    void init(int x)
    {
        val = w = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info c;
        c.w = a.w + b.w;
        return c;
    }
}; // 标记
struct Tag
{
    i64 w;
    Tag() : w(0)
    {
    }
};
void add(int l, int r, Info &f, Tag &t, int k)
{
    f.w += (r - l + 1) * k;
    t.w += k;
}
void pushdown(int p, int l, int r, vector<Info> &info, vector<Tag> &tag)
{
    if (l != r)
    {
        int mid = l + r >> 1;
        add(l, mid, info[p << 1], tag[p << 1], tag[p].w);
        add(mid + 1, r, info[p << 1 | 1], tag[p << 1 | 1], tag[p].w);
    }
    tag[p].w = 0;
    return;
}
} // namespace Eula
template <class Info, class Tag> struct Lazy_SegmentTree
{
    int n;
    vector<Info> info;
    vector<Tag> tag;
    Lazy_SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4 * (n + 1));
        tag.resize(4 * (n + 1));
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
    void update(int p, int l, int r, int ll, int rr, int k)
    {
        if (l == ll && r == rr)
        {
            Eula::add(l, r, info[p], tag[p], k);
            return;
        }
        Eula::pushdown(p, l, r, info, tag);
        int mid = l + r >> 1;
        if (ll <= mid)
            update(p << 1, l, mid, ll, min(rr, mid), k);
        if (rr > mid)
            update(p << 1 | 1, mid + 1, r, max(ll, mid + 1), rr, k);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void update(int l, int r, int k)
    {
        update(1, 1, n, l, r, k);
    }
    Info query(int p, int l, int r, int ll, int rr)
    {
        // cerr<<p<<endl;
        if (ll == l && rr == r)
        {
            return info[p];
        }
        Eula::pushdown(p, l, r, info, tag);
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
        return query(1, 1, n, l, r);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Lazy_SegmentTree<Eula::Info, Eula::Tag> seg(a);
    // cout << seg.query(1, n).w << '\n';
    while (m--)
    {
        int fl;
        cin >> fl;
        if (fl == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            seg.update(l, r, k);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r).w << '\n';
        }
    }
}