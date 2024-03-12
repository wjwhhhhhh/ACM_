#include <bits/stdc++.h>
const int bug=false;
#define dug(x) if(bug)cerr << "死了吧小丑" << x << endl
#define fir(i,a,b) for(int i=a;i<b;i++)
#define far(a,b)for(auto a:b)
using namespace std;
using i64=long long;
template<class T> void chkmax(T &a, T b) {a > b ? (a = a) : (a = b);}
template<class T> void chkmin(T &a, T b) {a > b ? (a = b) : (a = a);}

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
template <class T>
T randint(T l, T r = 0) // 生成随机数建议用<random>里的引擎和分布，而不是rand()模数，那样保证是均匀分布
{
    static mt19937 eng(time(0));
    if (l > r)
        swap(l, r);
    uniform_int_distribution<T> dis(l, r);
    return dis(eng);
}
i64 find_factor(i64 n)
{
    if (isprime(n)) // 特判素数
        return n;
    int x, d;
    do
    {
        x = randint(2, n - 1); // 生成2和n-1之间的随机数
        d = __gcd(n, x);       // 求gcd
    } while (d == 1);
    return d;
}
i64 Pollard_Rho(i64 N)
{
    if (N == 4)
        return 2;
    if (isprime(N))
        return N;
    while (1)
    {
        i64 c = randint(1, N - 1);
        auto f = [=](i64 x) { return ((i64)x * x + c) % N; };
        i64 t = 0, r = 0, p = 1, q;
        do
        {
            for (int i = 0; i < 128; ++i) // 令固定距离C=128
            {
                t = f(t), r = f(f(r));
                if (t == r || (q = (i64)p * abs(t - r) % N) == 0) // 如果发现环，或者积即将为0，退出
                    break;
                p = q;
            }
            i64 d = __gcd(p, N);
            if (d > 1)
                return d;
        } while (t != r);
    }
}
i64 max_prime_factor(i64 x)
{
    i64 fac = Pollard_Rho(x);
    if (fac == x)
        return x;
    else
        return max(max_prime_factor(fac), max_prime_factor(x / fac));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin>>t;
    while(t--)
    {
    }
    return 0;
}