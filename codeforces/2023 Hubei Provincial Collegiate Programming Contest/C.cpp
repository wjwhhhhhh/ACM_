#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 998244353;

i64 f(int x, int y) {
    return 1ll * (x ^ y) * (x & y) * (x | y);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> deg(n + 1);
    std::map<int, int> cnt;

    while (m--) {
        int u, v;
        std::cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        cnt[deg[i]]++;
    }
    int ans = 0;


    for (auto [x, t1] : cnt) {
        for (auto [y, t2] : cnt) {
            if (x == y) {
                continue;
            }
            ans += (i64)t1 * t2 * f(x, y) % P;
        }
    }

    std::cout << ans / 2 << "\n";

    return 0;
}