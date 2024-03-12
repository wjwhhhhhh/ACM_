#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 8;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool fl = true;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 25 != 0)
            fl = false;
        if (a[i] < 100 || a[i] > 675)
            fl = false;
        if (a[i] < last)
            fl = false;
        last = a[i];
    }
    if (fl)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}