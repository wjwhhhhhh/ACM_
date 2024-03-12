#include <bits/stdc++.h>

template <typename P, typename Q> std::istream &operator>>(std::istream &is, std::pair<P, Q> &v)
{
    std::cin >> v.first >> v.second;
    return is;
}
template <typename P, typename Q> std::ostream &operator<<(std::ostream &os, std::pair<P, Q> &v)
{
    std::cout << v.first << ' ' << v.second;
    return os;
}
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
template <typename P, typename Q> void chmax(P &a, Q b)
{
    a = (b > a ? b : a);
}
template <typename P, typename Q> void chmin(P &a, Q b)
{
    a = (b < a ? b : a);
}

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

struct StringHash
{
    constexpr static int P1 = 998244351, P2 = 998244353;
    int B1 = 131, B2 = 13331;
    int n;
    std::vector<int> h1, h2, p1, p2;
    StringHash()
    {
    }
    StringHash(const std::string &s)
    {
        init(s);
    }
    void init(const std::string &s)
    {
        n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        // B1 = rnd() % 200 + 100;
        // B2 = rnd() % 20000 + 10000;

        for (int i = 0; i < n; i++)
        {
            p1[i + 1] = 1LL * p1[i] * B1 % P1;
            p2[i + 1] = 1LL * p2[i] * B2 % P2;
            h1[i + 1] = (1LL * h1[i] * B1 + s[i]) % P1;
            h2[i + 1] = (1LL * h2[i] * B2 + s[i]) % P2;
        }
    }
    int get1(int l, int r)
    { // 0开头 左闭右开
        int res = (h1[r] - 1LL * h1[l] * p1[r - l] % P1) % P1;
        if (res < 0)
            res += P1;
        return res;
    }
    int get2(int l, int r)
    {
        int res = (h2[r] - 1LL * h2[l] * p2[r - l] % P2) % P2;
        if (res < 0)
            res += P2;
        return res;
    }
    bool same(int x, int y, int l, int r)
    {
        return get1(x, y) == get1(l, r) && get2(x, y) == get2(l, r);
    }
};

void solve()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    const int n = s1.size();

    int l1, l2;
    std::cin >> l1 >> l2;
    if (s1 == s2)
    {
        std::cout << "yes\n";
        return;
    }

    StringHash t(s2);
    int g1 = t.get1(0, s2.size());
    int g2 = t.get2(0, s2.size());

    StringHash t1(s1 + s1);
    std::ranges::reverse(s1);
    StringHash t2(s1 + s1);

    std::vector<int> down(n), up(n);
    int p = 0;
    do
    {
        p += l1;
        p %= n;
        down[p] = true;
        p -= l2;
        p %= n;
        if (p < 0)
            p += n;
        up[p] = true;
    } while (p != 0);

    auto same = [&](int t1, int t2) { return g1 == t1 && g2 == t2; };

    for (int i = 0; i < n; i++)
    {
        if (up[i])
        {
            if (same(t1.get1(i, i + n), t1.get2(i, i + n)))
            {
                std::cout << "yes\n";
                return;
            }
        }
        if (down[i])
        {
            int j = n - i;
            if (same(t2.get1(j, j + n), t2.get2(j, j + n)))
            {
                std::cout << "yes\n";
                return;
            }
        }
    }

    std::cout << "no\n";
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