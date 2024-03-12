#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const long long N = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int a[N], l[N];
int f[N], qian[N];
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
int n;
bool check(int k)
{
    // if (k == 3)
    //   fir(i, 1, n) cout << f[i] << " ";
    bool fl = false;
    l[n + 2] = -INF;
    l[n + 1] = -INF;
    for (int i = n + 1; i > 0; i--)
    {
        l[i] = max(l[i + 1], f[i]);
    }
    fir(i, k, n - (k - 1) * k / 2)
    {
        int tem = qian[i] - qian[i - k];
        if (tem < l[i + 1])
        {
            f[i - k + 1] = tem;
            fl = true;
        }
        else
            f[i - k + 1] = -INF;
    }
    int cnt = max(0ll, n - (k - 1) * k / 2 - k + 2);
    fir(i, cnt, n + 1) f[i] = -INF;
    return fl;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    fir(tt, 1, t)
    {
        n = read();
        memset(f, 0x3f, 8 * (n + 7));
        fir(i, 1, n) a[i] = read();
        fir(i, 1, n) qian[i] = qian[i - 1] + a[i];
        int k = 0;
        while (check(k + 1))
        {
            k++;
        }
        cout << k << endl;
    }
    return 0;
}