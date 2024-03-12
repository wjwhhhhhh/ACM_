#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Minimum_representation(string &sec)
{
    int n = sec.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n)
    {
        if (sec[(i + k) % n] == sec[(j + k) % n])
        {
            k++;
        }
        else
        {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j)
                i++;
            k = 0;
        }
    }

    i = min(i, j);
    sec = sec.substr(i) + sec.substr(0, i);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        Minimum_representation(a[i]);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (a[x] == a[y])
            cout << "Yes" << '\n';
        else
            cout << "No" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}