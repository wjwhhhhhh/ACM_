#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (*min_element(a.begin(), a.end()) >= 0)
        {
            cout << n - 1 << endl;
            for (int i = 1; i < n; i++)
            {
                cout << i + 1 << " " << i << '\n';
            }
            continue;
        }
        if (*max_element(a.begin(), a.end()) <= 0)
        {
            cout << n - 1 << endl;
            for (int i = n - 2; i >= 0; i--)
            {
                cout << i + 1 << " " << i + 2 << '\n';
            }
            continue;
        }
        int zh, fu;
        for (auto x : a)
        {
            if (x >= 0)
                zh++;
            else
                fu++;
        }
        vector<array<int, 2>> ans;
        if (min(zh, fu) >= 8)
        {
            int mi = *min_element(a.begin(), a.end());
            int ma = *max_element(a.begin(), a.end());
            if (ma >= -mi)
            {
                int id = find(a.begin(), a.end(), ma) - a.begin();
                for (int i = 0; i < n; i++)
                {
                    if (a[i] < 0)
                        ans.push_back({i + 1, id + 1});
                }
                for (int i = 1; i < n; i++)
                {
                    ans.push_back({i + 1, i});
                }
            }
            else
            {
                int id = find(a.begin(), a.end(), mi) - a.begin();
                for (int i = 0; i < n; i++)
                {
                    if (a[i] > 0)
                        ans.push_back({i + 1, id + 1});
                }
                for (int i = n - 2; i >= 0; i--)
                {
                    ans.push_back({i + 1, i + 2});
                }
            }
        }
        else
        {
            if (zh > fu)
            {
                int ma = *max_element(a.begin(), a.end());
                int id = find(a.begin(), a.end(), ma) - a.begin();
                while (ma < 20)
                {
                    ma <<= 1;
                    ans.push_back({id + 1, id + 1});
                }
                for (int i = 0; i < n; i++)
                {
                    if (a[i] < 0)
                        ans.push_back({i + 1, id + 1});
                }
                for (int i = 1; i < n; i++)
                {
                    ans.push_back({i + 1, i});
                }
            }
            else
            {
                int mi = *max_element(a.begin(), a.end());
                int id = find(a.begin(), a.end(), mi) - a.begin();
                while (mi > -20)
                {
                    mi *= 2;
                    ans.push_back({id + 1, id + 1});
                }
                for (int i = 0; i < n; i++)
                {
                    if (a[i] > 0)
                        ans.push_back({i + 1, id + 1});
                }
                for (int i = n - 2; i >= 0; i--)
                {
                    ans.push_back({i + 1, i + 2});
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans)
            cout << x << " " << y << '\n';
    }
    return 0;
}