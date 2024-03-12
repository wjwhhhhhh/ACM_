#include <bits/stdc++.h>
using namespace std;
template <class Info> struct SegmentTree
{
    int n;
    vector<Info> info;
    SegmentTree(vector<int> &a)
    {
        n = a.size();
        info.resize(4*n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
            {
                info[p].init(a[l - 1]);
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
            info[p]=info[p<<1]+info[p<<1|1];
        };
        build(1, 1, n);
    }
    // void modify(int p, int l, int r, int x, int c)
    // {
    //     if (x == l && l == r)
    //     {
    //         info[p].init(c);
    //         return;
    //     }
    //     int mid = l + r >> 1;
    //     if (x <= mid)
    //         modify(p << 1, l, mid, x, c);
    //     else
    //         modify(p << 1 | 1, mid + 1, r, x, c);
    //     info[p] = info[p << 1] + info[p << 1 | 1];
    // }
    // void modify(int x, int c)
    // {
    //     modify(1, 1, n, x, c);
    // }
    void query(int p, int l, int r, int ll, int rr, Info &ans)
    {
        if (ll == l && rr == r)
        {
            if(ans.use)ans += info[p];
            else 
            {
                ans=info[p];
                ans.use=true;
            }
            return;
        }
        int mid = l + r >> 1;
        if (ll <= mid)
             query(p << 1, l, mid, ll, min(rr, mid),ans);
        if (rr > mid)
             query(p << 1|1, mid + 1, r, max(ll, mid + 1), rr,ans);
        return;
    }
    Info query(int l, int r)
    {
        Info ans;
        query(1, 1, n, l, r, ans);
        return ans;
    }
};
struct Info
{
    int val;
    int w;
    bool use;
    Info() : val(0), w(0),use(0)
    {
    }
    void init(int x)
    {
        val = w = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info c;
        c.w = max(a.w ,b.w);
        c.use=a.use|b.use;
        return c;
    }
    void operator+=(const Info &a)
    {
        *this = *this + a;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    SegmentTree<Info> seg(a);
    while(m--)
    {
        
    }
    return 0;
}