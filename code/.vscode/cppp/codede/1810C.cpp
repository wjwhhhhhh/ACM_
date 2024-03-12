#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 1e5 + 10;
int a[N];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read(), c = read(), d = read();
        fir(i, 1, n) a[i] = read();
        sort(a + 1, a + 1 + n);
        int res = c * n + d;
        int tem = 0;
        fir(i, 1, n)
        {
            if (a[i] == a[i - 1])
            {
                tem++;
                continue;
            }
            int sum = (tem + n - i) * c + (a[i] - i + tem) * d;
            res = min(sum, res);
        }
        cout << res << "\n";
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}