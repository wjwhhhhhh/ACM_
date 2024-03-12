#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
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
const int N = 1300, M = 1e9 + 7;
int dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    string tem;
    cin >> tem;
    for (auto i : tem)
    {
        if (i == 'y' || i == 'k' || i == 'a' || i == 'w' || i == 'i')
            dp[0]++;
    }
    auto qmi = [&](int x, int q = M - 2) {
        LL ans = 1, a = x;
        while (q)
        {
            if (q & 1)
                ans = ans * a % M;
            a = a * a % M;
            q >>= 1;
        }
        return ans;
    };
    for (int i = 1; i <= k; i++)
    {
        dp[i] = (dp[i - 1] - (dp[i - 1] * qmi(n) % M) * (21 * qmi(26) % M) % M +
                 ((n - dp[i - 1] + M) * qmi(n) % M) * (5 * qmi(26) % M) + M) %
                M;
    }
    cout << dp[k] << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}