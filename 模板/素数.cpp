#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mul(i64 a, i64 b, i64 m)
{
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m)
{
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
bool isprime(i64 n)
{
    if (n < 2)
        return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A)
    {
        if (a == n)
            return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i)
        {
            x = mul(x, x, n);
            if (x == n - 1)
            {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}
std::vector<i64> factorize(i64 n)
{
    std::vector<i64> p;
    std::function<void(i64)> f = [&](i64 n) {
        if (n <= 10000)
        {
            for (int i = 2; i * i <= n; ++i)
                for (; n % i == 0; n /= i)
                    p.push_back(i);
            if (n > 1)
                p.push_back(n);
            return;
        }
        if (isprime(n))
        {
            p.push_back(n);
            return;
        }
        auto g = [&](i64 x) { return (mul(x, x, n) + 1) % n; };
        i64 x0 = 2;
        while (true)
        {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1)
            {
                y = g(y);
                ++lam;
                v = mul(v, std::abs(x - y), n);
                if (lam % 127 == 0)
                {
                    d = std::gcd(v, n);
                    v = 1;
                }
                if (power == lam)
                {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = std::gcd(v, n);
                    v = 1;
                }
            }
            if (d != n)
            {
                f(d);
                f(n / d);
                return;
            }
            ++x0;
        }
    };
    f(n);
    std::sort(p.begin(), p.end());
    return p;
}
vector<int> euler_function(i64 x)
{
    vector<int> q, s(x + 1), idx;
    vector<int> st(x + 1);
    st[1]=true;
    s[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
            q.push_back(i), s[i] = i - 1;
        for (int j = 0; q[j] <= x / i; j++)
        {
            st[q[j] * i] = true;
            if (i % q[j] == 0)
            {
                s[q[j] * i] = s[i] * q[j];
                break;
            }
            s[q[j] * i] = s[i] * (q[j] - 1);
        }
    }
    return s;
}
template <class T>
struct Tree_array
{
    vector<T> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    Tree_array(vector<T> a)
    {
        int n=a.size();
        init(n+1);
        for(int i=1;i<n;i++)insert(i,a[i]);
    }
    void init(int n)
    {
        maxx = n;
        tr.resize(n + 1);
    }
    void insert(int x, T c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(tr[i], c);
    }
    T ask(int x)
    {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            op(res, tr[i]);
        return res;
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    virtual  void p(T &x, T c)
    {
        x += c;
    }
};
i64 euler_phi(i64 n)
{ // 欧拉函数
    i64 res = 1;
    for (i64 i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            n /= i, res = res * (i - 1);
            while (n % i == 0)
                n /= i, res = res * i;
        }
    if (n > 1)
        res = res * (n - 1);
    return res;
}
vector<i64> divisor(i64 n)
{
    vector<i64> p;
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            p.push_back(i);
             if(n/i!=i)p.push_back(n / i);
        }
    }
    return p;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}