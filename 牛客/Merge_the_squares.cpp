#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    function<int(int, int)> find = [&](int l, int r) {
        if (l > r)
            swap(l, r);
        if (l <= 7)
            return r * l;
        return 1 + find(r - l, l);
    };
    auto check = [&](int x, int y) {
        int si = 1;
        si += x / y;
        si += find(x - x / y * y, y);
        x -= y;
        si += x / y;
        si += find(x - x / y * y, y);
        if (si <= 50)
            return true;
        return false;
    };
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<array<int, 3>> ans;
    function<void(int, int, int)> dfs;
    function<void(int, int, int, int)> get = [&](int l, int r, int x, int y) {
        if (l > r)
            swap(l, r);
        if (l <= 7)
            return;
        dfs(x, y, l);
        return;
    };
    dfs = [&](int l, int r, int len) {
        if (len <= 7)
        {
            ans.push_back({l, r, len});
            return;
        }
        int n;
        for (n = len - 1; n >= 1; n--)
        {
            if (check(len, len - n))
                break;
        }
        dfs(l, r, n);
        int x = len, y = len - n;
        for (int i = 0; i < x / y; i++)
            dfs(l + n, r + i * y, y);
        get(x - x / y * y, y, l + n, y * (x / y));
        x -= y;
        for (int i = 0; i < x / y; i++)
        {
            dfs(l + i * y, r + n, y);
        }
        get(x - x / y * y, y, l + n, y * (x / y));
    };
    dfs(1, 1, n);
    cout << ans.size() << endl;
    for (auto [x, y, z] : ans)
    {
        cout << x << " " << y << " " << z << '\n';
    }
    return 0;
}