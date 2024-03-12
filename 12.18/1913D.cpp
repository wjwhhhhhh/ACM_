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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // shuffle(a.begin(), a.end());
    int id = min_element(a.begin(), a.end()) - a.begin();
    mint l = 1, r = 1;
    vector<mint> dp(n, 0);
    vector<mint> su(n + 1, 0);
    vector<int> q;
    mint tem = 0;
    for (int i = n - 1; i > id; i--)
    {
        while (q.size() && a[q.back()] > a[i])
        {
            tem -= dp[q.back()];
            q.pop_back();
        }
        if (q.size() == 0)
        {
            dp[i] = su[i + 1] + 1;
        }
        else
        {
            dp[i] = su[i + 1] - su[q.back() + 1] + tem - dp[q.back()];
        }
        l += dp[i];
        // cout << dp[i] << endl;
        su[i] = su[i + 1] + dp[i];
        q.push_back(i);
        tem += dp[i];
    }
    vector<mint> s(n + 1);
    vector<mint> d(n + 1, 0);
    q.clear();
    tem = 0;
    for (int i = 0; i < id; i++)
    {
        while (q.size() && a[q.back()] > a[i])
        {
            tem -= d[q.back()];
            q.pop_back();
        }
        if (q.size() == 0)
        {
            d[i] = s[i] + 1;
        }
        else
        {
            d[i] = s[i] - s[q.back()] + tem - d[q.back()];
        }
        r += d[i];
        // cout << d[i] << endl;
        s[i + 1] = s[i] + d[i];
        q.push_back(i);
        tem += d[q.back()];
    }
    cout << l * r << '\n';
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