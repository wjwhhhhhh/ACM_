#include <bits/stdc++.h>

template <typename T, std::size_t N> std::istream &operator>>(std::istream &is, std::array<T, N> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T, std::size_t N> std::ostream &operator<<(std::ostream &os, std::array<T, N> &v)
{
    for (auto &i : v)
        os << i << " ";
    return os;
}
template <typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T> std::ostream &operator<<(std::ostream &os, std::vector<T> &v)
{
    for (auto &i : v)
        os << i << " ";
    return os;
}
template <typename T> auto dbug(const std::initializer_list<T> &a)
{
    std::cerr << "dbug: ";
    for (auto &i : a)
        std::cerr << i << " ";
    std::cerr << std::endl;
}

using i64 = long long;
using i128 = __int128;

constexpr i128 power(i128 a, i128 b, i128 P = 998244353)
{
    i128 res = 1;
    for (; b; b /= 2, a = a * a % P)
    {
        if (b % 2)
        {
            res = res * a % P;
        }
    }
    return res;
}

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

__int128 get(__int128 x, __int128 m, __int128 y, __int128 p)
{
    if ((y - x) % (std::__gcd(m, p)))
    {
        return -1;
    }
    i64 k1, k2;
    exgcd(m, p, k1, k2);
    k1 *= (y - x) / (std::__gcd(m, p));
    return k1;
}

auto solve()
{
    i64 a, P;
    std::cin >> a >> P;
    std::set<i64> S;
    std::vector<i64> v;

    for (int u = 1;; u++)
    {
        auto t = power(a, u, P);
        if (S.count(t))
        {
            break;
        }
        S.insert(t);
        v.push_back(t);
    }

    int m = v.size();

    for (int i = 0; i < v.size(); i++)
    {
        i64 x = i + 1, y = v[i];
        if (x == y)
        {
            std::cout << x << "\n";
            return;
        }
        i64 k1 = get(x, m, y, P);
        if (k1 == -1)
            continue;
        i64 x1 = ((__int128)k1 * m % P + x % P + P) % P;
        if (x1 < P)
            x1 += P;
        if (x1 % P == y % P && power(a, x1, P))
        {
            assert(power(a, x1, P) == x1);
            std::cout << x1 << "\n";
            return;
        }
    }
    assert(false);
    return;
}
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int c;
    std::cin >> c;

    while (c--)
    {
        solve();
    }

    return 0;
}