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
                info[p].id = l;
                info[p].init(a[l]);
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
    int w;
    int id;
    Info() : val(0), w(0), id(0)
    {
    }
    void init(int x)
    {
        val = w = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        if (a.w < b.w)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    void operator+=(const Info &a)
    {
        *this = *this + a;
    }
};
const int N = 100100;
int id[N];
int from[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    int ma = k;
    map<int, vector<int>> w;
    for (int i = 1; i <= n; i++)
    {
        ma = max(ma, l[i]);
        w[l[i]].push_back(i);
    }
    vector<i64> dp(N + 1, 1e16);
    vector<i64> all(N + 1, 0);
    vector<i64> ans(N + 1, 1e16);
    dp[k] = 0;
    SegmentTree<Info> seg(dp);
    for (int j = k + 1; j <= ma; j++)
    {
        if (w[j].size() == 0)
            continue;
        for (auto i : w[j])
        {
            all[j] += 1ll * (r[i] - 1ll) / ma * j;
        }
        for (auto i : w[j])
        {
            auto val = r[i];
            i64 need = 1e15, hh;
            int l = k, r = 1;
            while (l < j)
            {
                int te = (val - 1ll) / l;
                if (te == 0)
                    r = j - 1;
                else
                    r = max(l, min((val - 1) / te, j - 1));
                auto ans = seg.query(l, r);
                if (ans.w + te * j < need)
                {

                    hh = ans.id;
                    need = ans.w + te * j;
                }
                l = r + 1;
            }
            if (dp[j] > need)
            {
                dp[j] = need, from[j] = hh;
                ans[j] = all[j] - ((val - 1) / ma * j) + ((val - 1) / hh * j);
            }
            else if (dp[j] == need)
            {
                auto tem = all[j] - ((val - 1) / ma * j) + ((val - 1) / hh * j);
                if (ans[j] > tem)
                {
                    from[j] = hh;
                    ans[j] = tem;
                }
            }
        }
        seg.modify(j, dp[j]);
    }
    vector<int> use(n + 1);
    int it = ma;
    i64 cnt = 0;
    while (it != k)
    {
        for (auto i : w[it])
            use[i] = true;
        cnt += ans[it];
        it = from[it];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!use[i])
        {
            cnt += 1ll * (r[i] - 1ll) / ma * l[i];
        }
    }
    cout << cnt << endl;
    return 0;
}