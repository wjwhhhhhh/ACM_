#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
int g[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a][b] = g[b][a] = min(c, g[a][b]);
    }
    string an(n, '0');
    vector<string> ans;
    vector<int> cnt;
    an[0] = '1';
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sy;
    for (int j = 1; j < n; j++)
    {
        sy.push({g[0][j], j});
    }
    int sum = 0;
    while (sy.size())
    {
        auto [x, y] = sy.top();
        sy.pop();
        if (an[y] == '1')
            continue;
        ans.push_back(an);
        sum += x;
        cnt.push_back(x);
        vector<pair<int, int>> cy;
        while (sy.size())
        {
            cy.push_back(sy.top());
            sy.pop();
        }
        vector<int> need;
        for (auto [a, b] : cy)
        {
            if (a == x)
            {
                an[b] = '1';
                need.push_back(b);
            }
            else
                sy.push({a - x, b});
        }
        for (auto i : need)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && an[j] == '0')
                    sy.push({g[i][j], j});
            }
        }
        if (an[n - 1] == '1')
            break;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (an[n - 1] == '0' && an[i] == '0')
        {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << sum << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << cnt[i] << '\n';
    }
    return 0;
}