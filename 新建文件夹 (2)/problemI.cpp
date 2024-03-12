#include <bits/stdc++.h>
const int bug = false;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
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
// template <class T> T min(T a, T b)
// {
//     return a > b ? b : a;
// }
// template <class T> T max(T a, T b)
// {
//     return a < b ? b : a;
//}
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
    int w;
    Info() : val(0), w(0)
    {
    }
    void init(int x)
    {
        val = w = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        ans.val = a.val | b.val;
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> all[20];
    array<int, 20> st = {};
    vector<int> aa(n + 1);
    SegmentTree<Info> seg(aa);
    for (int i = 0; i < n; i++)
        all[a[i] - 'a'].push_back(i);
    for (int i = 0; i < n; i++)
        seg.modify(i + 1, 1 << a[i] - 'a');
    string ans = "", res = "";
    function<void(int)> dfs = [&](int l) {
        if (l >= n || seg.query(l + 1, n).val == 0)
        {
            chkmax(ans, res);
            return;
        }
        int cnt = 0, tem = seg.query(l + 1, n).val;
        while (tem)
        {
            if (tem & 1)
                cnt++;
            tem >>= 1;
        }
        int ll = l, rr = n - 1;
        while (ll < rr)
        {
            int mid = ll + rr + 1 >> 1;
            if (seg.query(mid + 1, n).val == seg.query(l + 1, n).val)
                ll = mid;
            else
                rr = mid - 1;
        }
        array<array<int, 2>, 20> has = {};
        for (int i = 0; i < 20; i++)
            has[i][0] = has[i][1] = -1;
        for (int i = 0; i < 20; i++)
        {
            if (st[i])
                continue;
            auto x1 = lower_bound(all[i].begin(), all[i].end(), l), x2 = upper_bound(all[i].begin(), all[i].end(), ll);
            if (x1 == x2)
                continue;
            has[i][0] = x2 - x1, has[i][1] = all[i][x2 - all[i].begin() - 1];
        };
        vector<int> o(20);
        iota(o.begin(), o.end(), 0);
        sort(o.begin(), o.end(), [&](int x, int y) { return has[x][0] > has[y][0]; });
        for (int z = 0; z < 20; z++)
        {
            int i = o[z];
            cerr << has[o[0]][0];
            if (has[i][0] != has[o[0]][0])
                continue;
            int si = res.size();
            res += string(has[i][0], char(cnt + 'a' - 1));
            auto x1 = lower_bound(all[i].begin(), all[i].end(), l), x2 = upper_bound(all[i].begin(), all[i].end(), ll);
            while (x1 != x2)
            {
                int id = *x1;
                seg.modify(id + 1, 0);
                x1++;
            }
            st[i] = false;
            dfs(has[i][1] + 1);
            res.erase(si);
            st[i] = true;
            x1 = lower_bound(all[i].begin(), all[i].end(), l);
            while (x1 != x2)
            {
                int id = *x1;
                seg.modify(id + 1, (1 << a[id] - 'a'));
                x1++;
            }
        }
        return;
    };
    dfs(0);
    cout << ans << endl;
    return 0;
}