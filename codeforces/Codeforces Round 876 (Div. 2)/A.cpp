#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    if (k == 1)
    {
        cout << n << endl;
        return ;
    }
    int si = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)si++;
        //cout<<((i + (k - 1)) / k)<<endl;
        if (((i + (k - 1)) / k) > si)
        {
            a[i] = 1; si++;
            ans++;
        }
    }
    reverse(a.begin() + 1, a.end());
    si = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)si++;
        if (((i + (k - 1)) / k) > si)
        {
            a[i] = 1; si++;
            ans++;
        }
    }
    cout << ans << endl;

}
int main()
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