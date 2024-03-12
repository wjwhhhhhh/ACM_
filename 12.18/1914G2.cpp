#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
using LL = long long;
template <const int T> struct ModInt
{
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod)
    {
    }
    ModInt(long long x) : x(int(x % mod))
    {
    }
    int val()
    {
        return x;
    }
    ModInt operator+(const ModInt &a) const
    {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    ModInt operator-(const ModInt &a) const
    {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator*(const ModInt &a) const
    {
        return ModInt(1LL * x * a.x % mod);
    }
    ModInt operator/(const ModInt &a) const
    {
        return *this * a.inv();
    }
    bool operator==(const ModInt &a) const
    {
        return x == a.x;
    };
    bool operator!=(const ModInt &a) const
    {
        return x != a.x;
    };
    void operator+=(const ModInt &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
    }
    void operator-=(const ModInt &a)
    {
        x -= a.x;
        if (x < 0)
            x += mod;
    }
    void operator*=(const ModInt &a)
    {
        x = 1LL * x * a.x % mod;
    }
    void operator/=(const ModInt &a)
    {
        *this = *this / a;
    }
    friend ModInt operator+(int y, const ModInt &a)
    {
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator-(int y, const ModInt &a)
    {
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    friend ModInt operator*(int y, const ModInt &a)
    {
        return ModInt(1LL * y * a.x % mod);
    }
    friend ModInt operator/(int y, const ModInt &a)
    {
        return ModInt(y) / a;
    }
    friend ostream &operator<<(ostream &os, const ModInt &a)
    {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, ModInt &t)
    {
        return is >> t.x;
    }

    ModInt pow(int64_t n) const
    {
        ModInt res(1), mul(x);
        while (n)
        {
            if (n & 1)
                res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const
    {
        int a = x, b = mod, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0)
            u += mod;
        return u;
    }
};
using mint = ModInt<998244353>;
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
                // info[p].init(a[l-1]);
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
        x++;
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
        l++, r++;
        return query(1, 1, n, l, r);
    }
};
struct Info
{
    int val;
    int mma, mmi;
    Info() : val(0), mma(0), mmi(0x3f3f3f3f)
    {
    }
    void init(int x)
    {
        mma = mmi = x;
    }
    friend Info operator+(const Info &a, const Info &b)
    {
        Info ans;
        ans.mma = max(a.mma, b.mma);
        ans.mmi = min(a.mmi, b.mmi);
        return ans;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> val(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> val[i];
        val[i]--;
        a[val[i]].push_back(i);
    }
    int ans1 = 0;
    mint ans2 = 1;
    int si = 0;
    int l = 0;
    vector<two> all;
    all.push_back({0, 0});
    for (int i = 0; i < 2 * n; i++)
    {
        if (i > l)
        {
            ans1++;
            si = 0;
            all.back()[1] = i - 1;
            all.push_back({i, 0});
        }
        l = max(l, a[val[i]][1]);
        si++;
    }
    ans1++;
    cout << ans1 << ' ';
    all.back()[1] = 2 * n - 1;
    vector<int> ll(2 * n), rr(2 * n);
    vector<int> temp(2 * n);
    SegmentTree<Info> tr(temp);
    for (int i = 0; i < 2 * n; i++)
    {
        if (i == a[val[i]][1])
        {
            if (val[i - 1] == val[i])
                ll[i] = i - 1;
            else
                ll[i] = min(tr.query(a[val[i]][0] + 1, i - 1).mmi, a[val[i]][0]);
            tr.modify(i, ll[i]);
            ll[a[val[i]][0]] = ll[i];
        }
    }
    SegmentTree<Info> th(temp);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (i == a[val[i]][0])
        {
            if (val[i] == val[i + 1])
                rr[i] = i + 1;
            else
                rr[i] = max(th.query(i + 1, a[val[i]][1] - 1).mma, a[val[i]][1]);
            th.modify(i, rr[i]);
            rr[a[val[i]][1]] = rr[i];
        }
    }
    for (auto [x, y] : all)
    {
        for (int i = x; i <= y; i++)
        {
            if (i == a[val[i]][1])
            {
                if (ll[i] == x && rr[i] == y)
                    ans2 *= 2;
            }
        }
    }
    cout << ans2 << endl;
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
lower_bound