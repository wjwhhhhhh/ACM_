#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 3e4;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        i64 a;
        cin >> a;
        if (a < 7)
        {
            cout << "NO\n";
            continue;
        }
        i64 l = 2, r = 1e9;
        while (l < r)
        {
            i64 mid = l + r + 1 >> 1;
            if (1ll + mid + mid * mid <= a)
                l = mid;
            else
                r = mid - 1;
        }
        if (1 + l + l * l == a)
        {
            cout << "YES\n";
            continue;
        }
        l = 2, r = 1e6;
        while (l < r)
        {
            i64 mid = l + r + 1 >> 1;
            if (1 + mid + mid * mid + mid * mid * mid <= a)
                l = mid;
            else
                r = mid - 1;
        }
        if (1 + l + l * l + l * l * l == a)
        {
            cout << "YES\n";
            continue;
        }
        auto check = [&](i64 x) {
            __int128 sum = 1 + x + x * x + x * x * x + x * x * x * x, l = x * x * x * x;
            while (sum <= a)
            {
                if (sum == a)
                    return true;
                l *= x;
                sum += l;
            }
            return false;
        };
        bool fl = false;
        for (i64 i = 2; i * i * i * i < a; i++)
        {
            if (check(i))
            {
                cout << "YES\n";
                fl = true;
                continue;
            }
        }
        if (!fl)
            cout << "NO\n";
    }
    return 0;
}