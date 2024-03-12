#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int si = 0;
    int len = 0;
    vector<pair<int, int>> x, y;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')si++, len++;
        else si--, len++;
        if (si == 0)
        {
            if (a[i] == ')')x.push_back({i - len + 1, i});
            else y.push_back({i - len + 1, i});
            len = 0;
        }
    }
    if(si!=0)
    {
        cout<<"-1"<<'\n';
        return ;
    }
    if(x.size()==0||y.size()==0)
    {
       cout<<"1"<<'\n';
       for(int i=1;i<=n;i++)cout<<"1 ";
       cout<<'\n';
       return ;
    }
    vector<int>ans(n);
    for (auto i : x)
    {
        for (int j = i.first; j <= i.second; j++)ans[j] = 1;
    }
    for (auto i : y)
    {
        for (int j = i.first; j <= i.second; j++)ans[j] = 2;
    }
    cout << 2 << '\n';
    for (auto i : ans)cout << i << ' ';
    cout << '\n';
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