#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    vector<int> ans(n);
    vector<int> ing(n);
    while (n > 1 && a[n - 1] == 0)
    {
        ans[n - 1] = 0;
        n--;
    }
    function<void(int, int, int, int)> addl = [&](int l, int fr, int op, int val) {
        for (int i = 0; i < l; i++)
        {
            if (ans[i] == op)
                ing[fr - i] += val;
        }
        return;
    };
    auto addr = [&](int r, int fr, int op, int val) {
        for (int i = r + 1; i < n; i++)
        {
            if (ans[i] == op)
                ing[i - fr] += val;
        }
        return;
    };
    function<bool(int, int)> dfs = [&](int l, int r) {
        for (int i = 1; i < n; i++)
        {
            if (ing[i] > a[i])
                return false;
        }
        if (l > r)
        {
            for (int i = 1; i < n; i++)
            {
                if (ing[i] != a[i])
                    return false;
            }
            return true;
        }
        if (l == r)
        {

            ans[l] = 1;
            addl(l, l, 0, 1);
            if (dfs(l + 1, r - 1))
                return true;
            addl(l, l, 0, -1);
            ans[l] = 0;
            addr(l, l, 1, 1);
            if (dfs(l + 1, r - 1))
                return true;
            addr(l, l, 1, -1);
            return false;
        }
        else
        {
            int len = n - 1 - l;
            if (ing[len] + 2 < a[len])
                return false;
            if (ing[len] == a[len])
            {
                ans[l] = 1, ans[r] = 0;
                addl(l, l, 0, 1);
                addr(r, r, 1, 1);
                if (dfs(l + 1, r - 1))
                    return true;
                addl(l, l, 0, -1);
                addr(r, r, 1, -1);
                return false;
            }
            else if (ing[len] + 2 == a[len])
            {
                ans[l] = 0, ans[r] = 1;
                addl(l, r, 0, 1);
                addr(r, l, 1, 1);
                ing[r - l]++;
                if (dfs(l + 1, r - 1))
                    return true;
                addl(l, r, 0, -1);
                addr(r, l, 1, -1);
                ing[r - l]--;
                return false;
            }
            else
            {

                ans[l] = 0, ans[r] = 0;
                addr(r, l, 1, 1);
                addr(r, r, 1, 1);
                if (dfs(l + 1, r - 1))
                    return true;
                addr(r, l, 1, -1);
                addr(r, r, 1, -1);
                ans[l] = 1, ans[r] = 1;
                addl(l, l, 0, 1);
                addl(l, r, 0, 1);
                if (dfs(l + 1, r - 1))
                    return true;
                addl(l, l, 0, -1);
                addl(l, r, 0, -1);
                return false;
            }
        }
    };
    if (n == 1)
    {
        for (auto c : ans)
            cout << c;
        return 0;
    }
    else if (a[n - 1] != 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        ans[0] = 0, ans[n - 1] = 1;
        ing[n - 1] = 1;
        if (dfs(1, n - 2))
        {
            for (auto c : ans)
                cout << c;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}