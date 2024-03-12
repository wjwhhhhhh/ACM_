#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> st[4];
    int n;
    cin >> n;
    vector<i64> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        st[0].push({x[i] + y[i], i});
        st[1].push({x[i] - y[i], i});
        st[2].push({-x[i] + y[i], i});
        st[3].push({-x[i] - y[i], i});
    }
    vector<int> stt(n);
    i64 l = 0, r = 0;
    auto get = [&](int s, i64 &ans, i64 &tem, i64 sum) {
        auto [x, y] = st[s].top();
        while (stt[y])
        {
            st[s].pop();
            x = st[s].top().first, y = st[s].top().second;
        }
        if (tem == sum - x)
            ans = min(ans, y);
        else if (tem < sum - x)
        {
            ans = y;
            tem = sum - x;
        }
    };
    int si = n;
    i64 an = 0;
    while (si--)
    {
        i64 tem = -1e18, ans = n;
        get(0, ans, tem, l + r);
        get(1, ans, tem, l - r);
        get(2, ans, tem, -l + r);
        get(3, ans, tem, -l - r);
        stt[ans] = true;
        an += tem;
        // cout<<tem<<endl;
        l = x[ans], r = y[ans];
    }
    cout << an << endl;
    return 0;
}