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
const int N = 2e3 + 10;
int w[N][N];
int l[N][N], r[N][N], d[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> w[i][j];
    }
    for (int j = 1; j <= n; j++)
    {
        int temp = 0;
        for (int i = n; i > 0; i--)
        {
            if (w[i][j] == 1)
                temp++;
            else
                temp = 0;
            d[i][j] = temp;
        }
    }
    for (int j = n; j > 0; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            int a = i - 1, b = j + 1;
            int temp;
            if (a <= 0 || b > n)
                temp = 0;
            else
                temp = r[a][b];
            if (w[i][j] == 1)
                temp++;
            else
                temp = 0;
            r[i][j] = temp;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int a = i - 1, b = j - 1;
            int temp;
            if (a <= 0 || b <= 0)
                temp = 0;
            else
                temp = l[a][b];
            if (w[i][j] == 1)
                temp++;
            else
                temp = 0;
            l[i][j] = temp;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (w[i][j] == 1)
            {
                ans += min({l[i][j], r[i][j], d[i][j]}) - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}