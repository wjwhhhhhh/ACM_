#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
#define int long long
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
const i64 M = (i64)1e18 + 10, P = 1e9 + 7;
int get(i64 di, i64 x)
{
    if (di <= 1)
        return 0;
    i128 res = 1;
    int si = 0;
    while (res <= x)
    {
        res *= di;
        si++;
    }
    return si - 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    vector<i64> fac, ww;
    for (int i = 0; 1ll << i < M; i++)
    {
        fac.push_back(1ll << i);
        ww.push_back(i);
    }
    fac.push_back(M);
    vector<i128> all, allw;
    for (int i = 0; i < fac.size() - 1; i++)
    {
        i64 ing = fac[i];
        while (ing < fac[i + 1])
        {
            all.push_back(ing);
            allw.push_back(get(ww[i], ing));
            i64 l = ing, r = fac[i + 1] - 1;
            while (l < r)
            {
                i64 mid = l + r + 1 >> 1;
                if (get(ww[i], ing) == get(ww[i], mid))
                    l = mid;
                else
                    r = mid - 1;
            }
            ing = l + 1;
        }
    }
    all.push_back(M);
    vector<i128> sum(all.size());
    for (int i = 1; i < all.size(); i++)
    {
        sum[i] = (sum[i - 1] + (all[i] - all[i - 1]) * allw[i - 1] % P) % P;
    }
    auto solve = [&](i64 s) {
        int l = 0, r = all.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (all[mid] <= s)
                l = mid;
            else
                r = mid - 1;
        }
        // cout << (i64)all[l] << endl;
        return (sum[l] + (s - all[l] + 1) * allw[l] % P) % P;
    };
    int t;
    cin >> t;
    while (t--)
    {
        i64 a, b;
        cin >> a >> b;
        cout << (i64)(solve(b) - solve(a - 1) + P) % P << endl;
    }
    return 0;
}