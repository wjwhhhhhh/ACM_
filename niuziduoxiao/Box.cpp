#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> has(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> has[i];
    vector<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        if (has[i] == 1)
        {
            while (i <= n && has[i] == 1)
                i++;
            st.push_back({l, i - 1});
        }
    }
    array<i64, 4> last = {0, -0x3f3f3f3f, -0x3f3f3f3f, -0x3f3f3f3f};
    for (int i = 0; i < st.size(); i++)
    {
        array<i64, 4> ans = {};
        i64 res = 0, sum = 0;
        for (int j = st[i].first; j <= st[i].second; j++)
            res += a[j];
        ans[0] = max({last[0], last[1], last[2], last[3]}) + res;
        if (st[i].first != 1)
        {
            sum = 0, res = 0x3f3f3f3f;
            for (int j = st[i].first - 1; j <= st[i].second; j++)
                sum += a[j];
            for (int j = st[i].first; j <= st[i].second; j++)
                res = min(res, a[j]);
            i64 an = 0;
            if (i == 0 || st[i - 1].second < st[i].first - 2)
                an = max(last[2], last[3]);
            an = max({an, last[0], last[1]});
            ans[1] = an + sum - res;
        }
        else
            ans[1] = -0x3f3f3f3f;
        if (st[i].second != n)
        {
            sum = 0, res = 0x3f3f3f3f;
            for (int j = st[i].first; j <= st[i].second + 1; j++)
                sum += a[j];
            for (int j = st[i].first; j <= st[i].second; j++)
                res = min(res, a[j]);
            i64 an = 0;
            ans[2] = max({last[0], last[1], last[2], last[3]}) + sum - res;
        }
        else
            ans[2] = -0x3f3f3f3f;
        if (st[i].first != 1 && st[i].second != n && st[i].second - st[i].first >= 1)
        {
            i64 d1 = 0x3f3f3f3f, d2 = 0x3f3f3f3f;
            sum = 0;
            for (int j = st[i].first - 1; j <= st[i].second + 1; j++)
                sum += a[j];
            for (int j = st[i].first; j <= st[i].second; j++)
            {
                if (d1 > a[j])
                    d2 = d1, d1 = a[j];
                else if (d2 > a[j])
                    d2 = a[j];
            }
            i64 an = 0;
            if (i == 0 || st[i - 1].second < st[i].first - 2)
                an = max(last[2], last[3]);
            an = max({an, last[0], last[1]});
            ans[3] = an + sum - d1 - d2;
        }
        else
            ans[3] = -0x3f3f3f3f;
        swap(last, ans);
    }
    cout << max({last[0], last[1], last[2], last[3]}) << endl;
    return 0;
}