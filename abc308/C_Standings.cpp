#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<i64> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) {
        return (l[x] * (l[y] + r[y]) == l[y] * (l[x] * r[x]) && x < y) ||
               (l[x] * (l[y] + r[y])) > (l[y] * (l[x] + r[x]));
    });
    for (int i = 0; i < n; i++)
        cout << o[i] + 1 << " ";
    return 0;
}