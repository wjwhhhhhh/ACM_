/**
 *    author:  tourist
 *    created: 27.05.2023 08:01:17
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> t(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return t[i] < t[j];
    });
    vector<long long> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], d[order[i]]);
    }
    long long low = 0, high = h;
    while (low < high) {
        long long mid = (low + high) >> 1;
        __int128 dmg = 0;
        long long mx = 0;
        long long done = 0;
        int i = 0;
        while (done < mid) {
            long long till = mid;
            if (i < n) {
                till = min(till, t[order[i]]);
            }
            if (till == done) {
                mx = max(mx, t[order[i]] * d[order[i]]);
                i += 1;
                continue;
            }
            long long L = done + 1;
            long long R = till;
            // t * suf[i] <= mx?
            long long u = (suf[i] == 0 ? R + 1 : mx / suf[i]);
            u = min(u, R);
            u = max(u, L - 1);
            if (u >= L) {
                dmg += (__int128) (u - L + 1) * mx;
                L = u + 1;
            }
            if (L <= R) {
                auto sum = (__int128) (L + R) * (R - L + 1) / 2;
                sum = min(sum, (__int128) h);
                dmg += sum * suf[i];
            }
            dmg = min(dmg, (__int128) h);
            done = till;
        }
        debug(mid, (long long) dmg);
        if (dmg >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << '\n';
    return 0;
}
