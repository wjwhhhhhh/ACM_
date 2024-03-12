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

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << "0\n";
        return 0;
    }

    std::vector<std::array<int, 3>> ans;
    std::function<void(int, int, int, int)> dfs0;
    std::function<void(int, int, int)> dfs;

    dfs0 = [&](int x, int y, int z, int w) {
        int a = z - x, b = w - y;
        // dbug({ x, y, z, w });
        if (a == b)
        {
            dfs(x, y, a + 1);
        }
        else if (a > b)
        {
            dfs0(x, y, x + a / 2, w);
            dfs0(x + a / 2 + 1, y, z, w);
        }
        else
        {
            dfs0(x, y, z, y + b / 2);
            dfs0(x, y + b / 2 + 1, z, w);
        }
    };

    dfs = [&](int x, int y, int s) {
        if (s <= 7)
        {
            ans.push_back({x, y, s});
        }
        else
        {
            int t = s / 2;
            dfs(x, y, t);
            dfs(x + t, y + t, s - t);
            // dbug({ x + t, y, x + s - 1, y + t - 1 });
            // dbug({ x, y + t, x + t - 1, y + s - 1 });
            dfs0(x + t, y, x + s - 1, y + t - 1);
            dfs0(x, y + t, x + t - 1, y + s - 1);
            ans.push_back({x, y, s});
        }
    };

    dfs(1, 1, n);
    std::cout << ans.size() << '\n';
    for (auto it : ans)
    {
        std::cout << it << "\n";
    }

    return 0;
}