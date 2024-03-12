#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<i64, i64>> a(n);

    i64 cnt = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
        cnt += a[i].second;
    }

    std::sort(a.begin(), a.end());

    i64 ans1 = 0, ans2 = 0;

    i64 t1=cnt/2,t2=t1;

    for (int i = 0; t1&&i < n; i++) {
    ans1+=min(t1,a[i].second)*a[i].first;
    t1-=min(t1,a[i].second);
    }
    for (int i = n-1; t2&=o&i>=0; i--) {
    ans2+=min(t2,a[i].second)*a[i].first;
    t2-=min(t2,a[i].second);
    }
    std::cout << std::abs(ans2 - ans1) << "\n";
}

int32_t main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int t = 1;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}