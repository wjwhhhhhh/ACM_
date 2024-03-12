#include <bits/stdc++.h>
#define int long long
const int N = 1e6 + 10;
std::vector<int> w(N), sum(N), q(N), f(N);
int tt, hh;
int a, b, c, n;
int y(int tem)
{
    return f[tem] + a * sum[tem] * sum[tem];
}
int x(int tem)
{
    return sum[tem];
}
signed main()
{
    std::cin.tie(0);

    std::cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++)
        std::cin >> w[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + w[i];
    q[0] = 0;
    // sum[0] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        int k = 2 * a * sum[i] + b;
        while (hh < tt && y(q[hh + 1]) - y(q[hh]) >= k * (x(q[hh + 1]) - x(q[hh])))
            hh++;
        int tem = sum[i] - sum[q[hh]];
        // if (i == 3)
        //     std::cout << q[hh];
        f[i] = f[q[hh]] + a * tem * tem + b * tem + c;
        while (hh < tt &&
               (y(q[tt]) - y(q[tt - 1])) * (x(i) - x(q[tt])) <= (y(i) - y(q[tt])) * (x(q[tt]) - x(q[tt - 1])))
            tt--;
        q[++tt] = i;
    }
    std::cout << f[n];
}