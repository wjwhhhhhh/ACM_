#include <bits/stdc++.h>
#define int long long
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25);
using namespace std;
using i64 = long long;
struct Hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    vector<int>o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y)
    {
        return a[x] < a[y];
    });
    int ans = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int>st;
        if (2ll * n / a[o[i]] < a[o[i]])break;
        int s = a[o[i]];
        while (i + len < n && a[o[i]] == a[o[i + len]])
        {
            i64 tem = s * a[o[i + len]] - b[o[i + len]];
            if (tem > 0 && tem <= n)
            {
                ans += st[tem];
            }
            st[b[o[i + len]]]++;
            len++;
        }
        for (int j = i + len; j < n; j++)
        {
            i64 tem = s * a[o[j]] - b[o[j]];
            if (tem > 0 && tem <= n)ans += st[tem];
        }
        i += len - 1, len = 0;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}