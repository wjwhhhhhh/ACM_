#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    map<int, vector<int> >mp;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    priority_queue<int> st;
    i64 ans = 0;
    for (auto [x, y] : mp)
    {
        sort(y.rbegin(),y.rend());
        for(int i=0;i<x&&i<y.size();i++)ans+=y[i];
    }

    cout << ans << '\n';
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