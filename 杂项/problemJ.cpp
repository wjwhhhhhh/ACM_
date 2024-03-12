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

bool check(int l, int r, int x)
{
    for (int i = 30; ~i; i--)
    {
        if ((x | 1LL << i) <= r)
        {
            x |= 1LL << i;
        }
    }

    return (x >= l && x <= r ? true : false);
}
auto solve()
{
    int n;
    std::cin >> n;

    std::vector<int> l(n), r(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> l[i] >> r[i];
    }
    int ans = 0;
    for (int i = 30; ~i; i--)
    {
        bool fl = true;
        for (int j = 0; j < n; j++)
        {
            fl = check(l[j], r[j], ans + (1 << i));
            if (!fl)
                break;
        }
        if (fl)
            ans += (1 << i);
    }
    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int c = 1;
    std::cin >> c;

    for (int i = 1; i <= c; i++)
    {
        solve();
    }

    return 0;
}