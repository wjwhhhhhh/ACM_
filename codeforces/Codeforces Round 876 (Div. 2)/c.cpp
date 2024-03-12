#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    if (v[n] == 1)
    {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    vector<int> ans;
    int si = 1;
    for (int i = n; i; i--)
    {
        if (v[i] % 2 == si % 2)
        {
            ans.push_back(i);
            si++;
        }
    }
    while(ans.size()!=n)ans.push_back(0);
    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<" ";
        cout<<endl;
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