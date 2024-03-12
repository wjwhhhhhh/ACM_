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
template <class Info> struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4 * (n + 1));
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
        return query(1, 1, n, l, r);
    }
};
struct Info
{
    int val;
    Info() : val(0)
    {
    }
    void init(int x)
    {
        val = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        ans.init(min(a.val, b.val));
        return ans;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    vector<int> cnt;
    int su = 0;
    string a;
    cin >> a;
    cnt.push_back(su);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
            su++;
        else
            su--;
        cnt.push_back(su);
    }
    SegmentTree<Info> seg(cnt);
    map<int, vector<int>> mp;
    for (int i = 0; i < cnt.size(); i++)
    {
        mp[cnt[i]].push_back(i + 1);
    }
    int res = 0, cn = 0;
    for (auto [x, has] : mp)
    {
        if (has.size() == 1)
            continue;
        int k = has[0];
        for (int i = 1; i < has.size(); i++)
        {
            if (seg.query(k, has[i]).val < x)
            {
                // cout << k << endl;
                if (has[i - 1] - k > res)
                {
                    res = has[i - 1] - k;
                    cn = 1;
                }
                else if (has[i - 1] - k == res)
                    cn++;
                k = has[i];
            }
        }
        if (has.back() - k > res)
        {
            res = has.back() - k;
            cn = 1;
        }
        else if (has.back() - k == res)
            cn++;
    }
    if (res == 0)
        cn = 1;
    cout << res << ' ' << cn << endl;
    return 0;
}