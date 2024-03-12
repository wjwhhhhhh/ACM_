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
const int N = 1e5 + 10, M = 1e9 + 7;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    string tem;
    auto qmi = [&](int x, int q = M - 2) {
        if (q == 0)
            return 1ll;
        int ans = 1;
        while (q)
        {
            if (q & 1)
                ans = ans * x % M;
            x = x * x % M;
            q >>= 1;
        }
        return ans;
    };
    int t = 5 * (qmi(26)) % M;
    int p0 = (n - 1) * qmi(n) % M;
    p0 = qmi(p0, k);
    int p1 = (1 - p0 + M) % M;
    cin >> tem;
    tem = " " + tem;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tem[i] == 'y' || tem[i] == 'k' || tem[i] == 'a' || tem[i] == 'w' || tem[i] == 'i')
            sum = (sum + p0 + p1 * t) % M;
        else
            sum = (sum + p1 * t) % M;
    }
    cout << sum << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}