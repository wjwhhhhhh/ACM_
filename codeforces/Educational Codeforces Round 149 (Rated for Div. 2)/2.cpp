#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ans = 1;
    int l = 0, r = 0;
    for (auto i : a)
    {
        if (i == '<')
        {
            l++, r = 0;
            ans = max(ans, l + 1);
        }
        else
        {
            r++, l = 0;
            ans = max(ans, r + 1);
        }
    }
    cout<<ans<<'\n';
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