#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int n;
    cin >> n;
    cin >> a;
    vector<int> left;
    int sum = 0;
    vector<pair<int, int>> qu;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
            left.push_back(i);
        else if (a[i] == ')')
        {
            if (left.size() == 0)
                continue;
            qu.push_back({left.back(), i});
            left.pop_back();
        }
    }
    sort(qu.begin(), qu.end());
    vector<pair<int, int>> ans;
    vector<int> st(a.size());
    if (qu.size() == 0)
    {
        cout << a << endl;
        return 0;
    }
    auto [l, r] = qu[0];
    for (auto [x, y] : qu)
    {
        if (x > r)
        {
            ans.push_back({l, r});
            l = x, r = y;
        }
        else
            r = max(r, y);
    }
    ans.push_back({l, r});
    for (auto [x, y] : ans)
    {
        for (int j = x; j <= y; j++)
            st[j] = true;
    }
    for (int i = 0; i < a.size(); i++)
        if (!st[i])
            cout << a[i];
    return 0;
}