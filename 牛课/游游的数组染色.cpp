#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string an;
    cin >> an;
    map<int, int> b, r;
    for (int i = 0; i < n; i++)
    {
        if (an[i] == 'B')
            b[a[i]]++;
        else
            r[a[i]]++;
    }
    i64 ans = 0;
    for (auto [x, y] : b)
    {
        ans += 1ll*y * r[x];
    }
    cout << ans << endl;
    return 0;
}