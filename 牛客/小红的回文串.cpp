#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    int n = a.size();
    int ans = 1;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (a[i] != '?' && a[j] != '?' && a[i] != a[j])
        {
            cout << 0 << endl;
            return 0;
        }
        if (a[i] == '?')
        {
            if (a[j] == '?')
                ans *= 26;
        }
    }
    cout << ans << endl;
    return 0;
}