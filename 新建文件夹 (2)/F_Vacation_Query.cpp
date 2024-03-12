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
        os << i << ' ';
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
        os << i << ' ';
    return os;
}
template <typename... Args> void debug(Args... args)
{
    ((std::cerr << args << ' '), ...);
    std::cerr << '\n';
}
template <typename... Args> void println(Args... args)
{
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

using i64 = long long;

auto solve()
{
    int n, k;
    std::cin >> n >> k;
    if (k == 1)
    {
        if (n == 1)
        {
            println("Yes");
        }
        else
        {
            println("No");
        }
        return;
    }

    if (k % 2 == 0)
    {
        println("Yes");
        return;
    }

    if (n <= 2 * k - 1)
    {
        println("Yes");
        return;
    }

    if (n == 2 * k)
    {
        println("No");
        return;
    }
    n -= 2 * k + 1;
    int t = k + 1;
    int p = n / t;
    int si = n % t;
    if (si < k - 2 * (p + 1))
    {
        println("Yes");
    }
    else
        println("No");
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