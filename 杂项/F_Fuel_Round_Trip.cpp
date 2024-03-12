#include <bits/stdc++.h>

using i64 = long long;

template <typename... Args> void println(Args... args)
{
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

int main()
{
    int n, H;
    scanf("%d%d", &n, &H);

    std::vector<int> X(n), v(n), w(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &X[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &w[i], &v[i]);
    }

    std::vector<std::array<int, 3>> dp(n + 1);

    for (int i = 0; i < n; i++)
    {
    }

    for (int i = 0; i < n; i++)
    {
    }

    return 0;
}