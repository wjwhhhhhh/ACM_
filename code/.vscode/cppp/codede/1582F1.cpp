#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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
int dp[513];
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    met(dp, 0x3f);
    dp[0] = 0;
    fir(i, 1, n)
    {
        int tem = read();
        fir(j, 0, 512)
        {
            if (tem > dp[j])
                dp[j ^ tem] = min(dp[j ^ tem], tem);
        }
    }
    int res = 0;
    fir(i, 0, 512) if (dp[i] != 0x3f3f3f3f) res++;
    cout << res << endl;
    fir(i, 0, 512) if (dp[i] != 0x3f3f3f3f) cout << i << " ";
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}