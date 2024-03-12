#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
using i128 = __int128;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
std::ostream &operator<<(std::ostream &os, __int128 T)
{
    if (T < 0)
        os << "-";
    if (T >= 10)
        os << T / 10;
    if (T <= -10)
        os << (-(T / 10));
    return os << ((int)(T % 10) > 0 ? (int)(T % 10) : -(int)(T % 10));
}
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    vector<int> b(3);
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> b[i];
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    i128 ans = 2e20;
    for (int i = 1; i < 1 << 3; i++)
    {

        vector<i128> ta(n);
        for (int i = 0; i < n; i++)
            ta[i] = a[i];
        i128 tr = 1;
        for (int j = 0; j < 3; j++)
        {
            if (i >> j & 1)
            {

                tr = lcm(tr, (i128)b[j]);
            }
        }
        vector<i128> all;
        all.push_back(tr);
        for (int j = 0; j < 3; j++)
        {
            if (!(i >> j & 1))
            {
                all.push_back(b[j]);
            }
        }
        set<int> has;
        auto find = [&](i128 u) {
            if (u == 1)
                return (i128)0;
            i128 si = 2e20, it = -1;
            for (int i = 0; i < n; i++)
            {
                if (has.find(i) != has.end())
                    continue;
                if (chmin(si, (u - (ta[i] % u)) % u))
                {
                    it = i;
                };
            }
            has.insert(it);
            if (it != -1)
                ta[it] += si;
            return si;
        };
        for (int i = 0; i < 20; i++)
        {
            shuffle(all.begin(), all.end(), rnd);
            for (int i = 0; i < n; i++)
                ta[i] = a[i];
            has.clear();
            i128 res = 0;
            for (auto c : all)
            {
                res += find(c);
            }
            // cout << res << endl;
            if (has.find(-1) == has.end())
            {
                chmin(ans, res);
            }
        }
    }
    cout << ans << endl;
    return 0;
}