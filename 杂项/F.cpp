#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, a, b;
    cin >> n >> a >> b;
    cout << "YES" << endl;
    vector<array<int, 4>> ans;
    function<void(int, int, int, int, int)> dfs = [&](int len, int x, int y, int wx, int wy) {
        if (x == 1 && (y == 1))
        {
            for (int i = len; i >= 2; i--)
            {
                ans.push_back({i + wx, i + wy, -1 * i + 1, -1 * i + 1});
            }
            return;
        }
        else if (x == 1 && (y == len))
        {
            for (int i = len; i >= 2; i--)
            {
                ans.push_back({i + wx, (len - i + 1) + wy, -1 * i + 1, 1 * i - 1});
            }
            return;
        }
        else if (x == len && y == len)
        {
            for (int i = len; i >= 2; i--)
            {
                ans.push_back({(len - i + 1) + wx, (len - i + 1) + wy, i - 1, i - 1});
            }
            return;
        }
        else if (x == len && y == 1)
        {
            for (int i = len; i >= 2; i--)
            {
                ans.push_back({(len - i + 1) + wx, i + wy, i - 1, -1 * i + 1});
            }
            return;
        }
        else if (x == 1)
        {
            for (int i = len; i > y; i--)
            {
                ans.push_back({i + wx, i + wy, -1 * i + 1, -1 * i + 1});
            }
            dfs(y, x, y, wx, wy);
        }
        else if (y == 1)
        {
            for (int i = len; i > x; i--)
            {
                ans.push_back({i + wx, i + wy, -1 * i + 1, -1 * i + 1});
            }
            dfs(x, x, y, wx, wy);
        }
        else if (x == len)
        {

            int si = 0;
            for (int i = 1; i < y; i++)
            {
                si++;
                ans.push_back({i + wx, i + wy, len - i, len - i});
            }

            dfs(len - si, x - si, y - si, wx + si, wy + si);
        }
        else if (y == len)
        {
            int si = 0;
            for (int i = 1; i < x; i++)
            {
                si++;
                ans.push_back({i + wx, i + wy, len - i, len - i});
            }

            dfs(len - si, x - si, y - si, wx + si, wy + si);
        }
        else
        {
            cerr << len << x << y << endl;
            for (int i = len; i > max(x, y); i--)
            {
                ans.push_back({i + wx, i + wy, -1 * i + 1, -1 * i + 1});
            }
            // cerr << len << x << y << endl;
            dfs(max(x, y), x, y, wx, wy);
        }
    };
    dfs(n, a, b, 0, 0);
    cout << ans.size() << endl;
    for (auto [x, y, a, b] : ans)
    {
        cout << x << " " << y << " " << a << " " << b << endl;
    }
    return 0;
}