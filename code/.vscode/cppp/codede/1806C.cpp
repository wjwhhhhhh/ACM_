#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 4e5 + 10;
LL a[N];
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
int main()
{
    // freopen("test.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
            cin >> a[i];
        LL res = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            res += abs(a[i]);
        }
        if (n == 1)
        {
            LL ch = abs(a[1] - a[2]);
            res = min(res, ch);
        }
        if (n == 2)
        {
            LL ch = abs(a[1] - 2) + abs(a[2] - 2) + abs(a[3] - 2) + abs(a[4] - 2);

            res = min(res, ch);
        }
        if (n & 1)
        {
            cout << res << endl;
            continue;
        }
        LL sum = 0, ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= 2 * n; i++)
            sum += abs(-1 - a[i]);
        for (int i = 1; i <= 2 * n; i++)
        {
            LL x = abs(-1 - a[i]), y = abs(n - a[i]);
            ans = min(ans, sum + y - x);
        }
        cout << min(ans, res) << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}