#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<array<int, 4>> ans;
    function<void(int, int, int, int)> dfs = [&](int n, int a, int b, int wei) {
        if (n == 1)
            return;
        else if (a == 1 && b == 1)
        {
            for (int i = 2; i <= n; i++)
                ans.push_back({wei + i, wei + i, -(i - 1), -(i - 1)});
        }
        else if (a == 1 && b == n)
        {
            for (int i = 2; i <= n; i++)
                ans.push_back({wei + i, wei + n - i + 1, -(i - 1), (i - 1)});
        }
        else if (a == n && b == 1)
        {
            for (int i = 2; i <= n; i++)
                ans.push_back({wei + n - i + 1, wei + i, (i - 1), -(i - 1)});
        }
        else if (a == n && b == n)
        {
            for (int i = 2; i <= n; i++)
                ans.push_back({wei + n - i + 1, wei + n - i + 1, (i - 1), (i - 1)});
        }
        else if (b == 1)
        {
            for (int i = a + 1; i <= n; i++)
            {
                ans.push_back({wei + i, wei + i - a + 1, -(i - a), -(i - a)});
            }
            for (int i = 1; i < a; i++)
            {
                ans.push_back({wei + i, wei + n - i + 1, n - i, -(n - i)});
            }
        }
        else if (b == n)
        {
            for (int i = a + 1; i <= n; i++)
            {
                ans.push_back({wei + i, wei + n - (i - a), -(i - a), (i - a)});
            }
            for (int i = 1; i < a; i++)
            {
                ans.push_back({wei + i, wei + i, n - i, (n - i)});
            }
        }
        else if (a == 1)
        {
            for (int i = b + 1; i <= n; i++)
            {
                ans.push_back({wei + i - b + 1, wei + i, -(i - b), -(i - b)});
            }
            for (int i = 1; i < b; i++)
            {
                ans.push_back({wei + n - i + 1, wei + i, -(n - i), (n - i)});
            }
        }
        else if (a == n)
        {
            for (int i = b + 1; i <= n; i++)
            {
                ans.push_back({wei + n - (i - b), wei + i, (i - b), -(i - b)});
            }
            for (int i = 1; i < b; i++)
            {
                ans.push_back({wei + i, wei + i, n - i, (n - i)});
            }
        }
        else
        {
            ans.push_back({wei + 1, wei + 1, n - 1, n - 1});
            ans.push_back({wei + n, wei + n, -(n - 2), -(n - 2)});
            dfs(n - 2, a - 1, b - 1, wei + 1);
        }
    };
    dfs(n, a, b, 0);
    cout << "Yes" << endl;
    assert(ans.size() <= (n * n - 1) / 3);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
    return 0;
}