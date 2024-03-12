#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve(int n, int m, int k)
{
    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        int ing = 1 << i, val = i;
        for (int j = n - 1; j > 0; j--)
        {
            val %= j;
            ing |= 1 << val;
        }
        if (__builtin_popcount(ing) == k)
            ans++;
    }
    cout << ans << " ";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                cout << i << " " << j << " " << k;
                solve(i, j, k);
                cout << endl;
            }
        }
    }
    return 0;
}