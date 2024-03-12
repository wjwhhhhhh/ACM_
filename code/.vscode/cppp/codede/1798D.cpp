#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 3e5 + 10;
int a[N], b[N];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read();
        fir(i, 1, n) a[i] = read();
        bool fl = true;
        sort(a + 1, a + 1 + n);
        int l = 1, tem = a[n] - a[1], r = n, sum = 0;
        fir(i, 1, n)
        {
            if (sum >= 0)
                b[i] = a[l++];
            else
                b[i] = a[r--];
            sum += b[i];
        }
        fir(i, 2, n) if (abs(b[i] + b[i - 1]) >= tem) fl = false;
        if (n == 1)
            fl = false;
        if (fl)
        {
            puts("Yes");
            fir(i, 1, n) cout << b[i] << " ";
            puts("");
        }
        else
            puts("No");
        // fir(i, 1, n) cout << b[i] << " ";
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}