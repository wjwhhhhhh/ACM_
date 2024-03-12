#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
#define int long long
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    vector<array<int, 20>> f(n);
    for (int i = 0; i < n; i++)
        f[i][0] = i;
    auto op = [&](int x, int y) {
        if (a[x] < a[y])
            return x;
        else if (a[x] == a[y])
            return max(x, y);
        else
            return y;
    };
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            f[i][j] = op(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    auto ask = [&](int l, int r) {
        int len = r - l + 1;
        len = __lg(len);
        return op(f[l][len], f[r - (1 << len) + 1][len]);
    };
    int ing = 0;
    int last = 0, lastl = -1;
    while (ing != n)
    {
        auto re = ask(ing, n - 1);
        int l = 0, r = (lastl == -1 ? 0x3f3f3f3f : lastl);
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (last * mid + k >= a[re] * mid)
                l = mid;
            else
                r = mid - 1;
        }
        s[ing] += l, s[re + 1] -= l;
        k = (k + l * last) % a[re];
        ing = re + 1;
        last = a[re];
        lastl = l;
    }
    for (int i = 1; i < n; i++)
        s[i] += s[i - 1];
    for (int i = 0; i < n; i++)
        cout << s[i] << ' ';
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}