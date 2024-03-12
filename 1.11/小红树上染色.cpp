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
using mint = ModInt<1000000007>;
const int N = 1e5 + 10;
mint dp[N][2];
vector<int> cnt[N];
void dfs(int u, int fa)
{
    int si = 0;
    dp[u][0] = 1, dp[u][1] = 1;
    for (auto c : cnt[u])
    {
        if (c == fa)
            continue;
        si++;
        dfs(c, u);
        dp[u][0] *= dp[c][1];
        dp[u][1] *= dp[c][1] + dp[c][0];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a].push_back(b);
        cnt[b].push_back(a);
    }
    dfs(0, -1);
    cout << dp[0][0] + dp[0][1] << endl;
    return 0;
}