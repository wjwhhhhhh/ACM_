#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    } // 是符号
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    } // 是数字
    return x * s;
}
void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
const int N = 110, M = 998244353;
int dp1[N][N], dp2[N][N];
int kua(int x, int p = M - 2)
{
    LL res = 1;
    while (p)
    {
        if (p & 1)
            res = res * x % M;
        x = x * x % M;
        p >>= 1;
    }
    return res;
}
void find(int dp[N][N], int p, int a, int n)
{
    dp[a][0] = 1;
    fir(i, a, n - 1)
    {
        for (int j = 0; j < N - 1; j++)
        {

            for (int l = 1; l <= p && i + l <= n; l++)
            {
                dp[i + l][j + 1] = (dp[i + l][j + 1] + dp[i][j] * kua(p)) % M;
            }
            int l = max(i + p - n, 0ll);
            if (l)
            {
                // cout << i << j << endl;
                dp[n][j + 1] = (dp[n][j + 1] + dp[i][j] * l * kua(p)) % M;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    find(dp1, p, a, n), find(dp2, q, b, n);
    long long sum = dp2[n][N - 2], ans = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        sum = (dp2[n][i] + sum) % M;
        ans = (ans + dp1[n][i] * sum) % M;
    }
    cout << ans << endl;
    //  freopen("CON", "r", stdin);
    //  system("pause");
    return 0;
}