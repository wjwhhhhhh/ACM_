#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 n, k;
    cin >> n >> k;
    vector<two> all(n);
    for (int i = 0; i < n; i++)
        cin >> all[i][0] >> all[i][1];
    int l = 0, r = 1e9;
    auto check = [&](int len) {
        i64 yong = 0;
        vector<i64> s(n);
        vector<i64> ss(n);
        for (int i = 0; i < n; i++)
            s[i] = all[i][0];
        sort(s.begin(), s.end());
        // for (int i = 0; i < n; i++)
        //     cout << s[i] << endl;
        ss[0] = s[0];
        for (int i = 1; i < n; i++)
            ss[i] = s[i] + ss[i - 1];
        i64 tem = 1e18;
        /*
        306319121
358683490
369972904
386219602
409648209
450668761
489733278
861289363
915030547
930832199
*/
        for (int i = 0; i < n; i++)
        {
            i64 te = s.end() - upper_bound(s.begin(), s.end(), s[i] + len);
            if (te != 0)
            {
                te = ss[n - 1] - ss[n - 1 - te] - (s[i] + len) * te;
            }
            if (i != 0)
                te += s[i] * i - ss[i - 1];
            if (chmin(tem, te))
            {
                // cout << tem << " " << i << endl;
            }
            int l = 0, r = i;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (s[mid] >= s[i] - len)
                    r = mid;
                else
                    l = mid + 1;
            }
            te = 0;
            if (l != 0)
                te += (s[i] - len) * l - ss[l - 1];
            // cout << te << endl;
            if (i != n - 1)
                te += ss[n - 1] - ss[i] - (n - 1 - i) * s[i];
            if (chmin(tem, te))
            {
                // cout << tem << " " << i << endl;
            }
        }
        yong += tem;
        // cout << tem << endl;
        for (int i = 0; i < n; i++)
            s[i] = all[i][1];
        sort(s.begin(), s.end());
        // for (int i = 0; i < n; i++)
        //     cout << s[i] << endl;
        ss[0] = s[0];
        for (int i = 1; i < n; i++)
            ss[i] = s[i] + ss[i - 1];
        tem = 1e18;
        for (int i = 0; i < n; i++)
        {
            i64 te = s.end() - upper_bound(s.begin(), s.end(), s[i] + len);
            if (te != 0)
            {
                te = ss[n - 1] - ss[n - 1 - te] - (s[i] + len) * te;
            }
            if (i != 0)
                te += s[i] * i - ss[i - 1];
            // cout << te << endl;
            chmin(tem, te);
            int l = 0, r = i;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (s[mid] >= s[i] - len)
                    r = mid;
                else
                    l = mid + 1;
            }
            te = 0;
            if (l != 0)
                te += (s[i] - len) * l - ss[l - 1];
            if (i != n - 1)
                te += ss[n - 1] - ss[i] - (n - 1 - i) * s[i];
            if (chmin(tem, te))
            {
                // cout << i << " " << tem << endl;
            }
        }
        yong += tem;
        // cout << tem << endl;
        return yong <= k;
    };
    // if (check(2))
    // {
    //     cout << "ok" << endl;
    // }
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}