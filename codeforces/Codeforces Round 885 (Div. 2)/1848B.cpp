#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    // cout << a << endl;
    // cout << b << endl;
    auto check = [&](int a, int b) {
        int si = 1;
        while (a != b)
        {
            int c = abs(a - b);
            // cout << c << endl;
            a = b, b = c;
            si++;
        }
        cout << si % 3 << endl;
    };
    for (int i = 2; i < 40; i += 2)
        check(i, 6);
    return 0;
}