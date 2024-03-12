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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1" << '\n';
            continue;
        }
        if (n == 2)
        {
            cout << "2 1" << '\n';
            continue;
        }
        if (n == 3)
        {
            cout << "2 1 3" << '\n';
            continue;
        }
        vector<int> ans(n);
        ans[0] = 2, ans[n - 1] = 3, ans[n / 2] = 1;
        int l = 4;
        for (int i = 1; i < n - 1; i++)
        {
            if (i != n / 2)
                ans[i] = l++;
        }
        if (isprime(n))
            swap(ans[n - 1], ans[n - 2]);
        for (auto x : ans)
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}