#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
string a[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
void solve()
{
    i64 x, y, z;
    map<string, int> get;
    for (int i = 0; i < 5; i++)
        get[a[i]] = i;
    cin >> x >> y >> z;
    string has;
    cin >> has;
    y += x * 12;
    z += y * 30;
    int ing = get[has];
    ing = (ing - z % 5 + 5) % 5;
    cin >> x >> y >> z;
    y += x * 12;
    z += 30 * y;
    ing = (ing + z % 5) % 5;
    cout << a[ing] << '\n';
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