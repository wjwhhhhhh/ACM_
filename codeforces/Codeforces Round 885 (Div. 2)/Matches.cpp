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
    for (auto &i : a)
        std::cout << i << " ";
    std::cout << std::endl;
}

using i64 = long long;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    std::cin >> a >> b;

    std::map<int, std::set<int>> mp;
    std::vector<std::array<int, 3>> t(n);
    i64 ans = 0;

    for (int i = 0; i < n; i++)
    {
        t[i] = {a[i], b[i], i};
        c[i] = std::abs(a[i] - b[i]);
        ans += c[i];
        mp[a[i]].insert(b[i]);
    }

    auto res = ans;

    std::sort(t.begin(), t.end());
    for (auto [x, y, i] : t)
    {
        auto it = mp.lower_bound(y);
        auto work = [&](const auto it) {
            auto w = it->first;
            auto s = it->second;
            if (s.empty())
                return;
            auto z = s.lower_bound(x);
            auto calc = [&]() {
                ans = std::min(ans, res - std::abs(x - y) - std::abs(w - *z) + std::abs(x - *z) + std::abs(w - y));
            };
            if (z != s.end())
            {
                calc();
            }
            --z;
            if (z != s.end())
            {
                calc();
            }
        };

        if (it != mp.end())
        {
            work(it);
        }
        --it;
        if (it != mp.end())
        {
            work(it);
        }
    }

    std::cout << ans << "\n";

    return 0;
}