#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
// #define int long long
// #define int __int128
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
const int N = 1e5 + 10;
priority_queue<int, vector<int>, greater<int>> st[10];
int w[N];
int f[N];
int qian(int x)
{
    int tem;
    while (x)
    {
        tem = x % 10;
        x /= 10;
    }
    return tem;
}
int huo(int x)
{
    return x % 10;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int a = qian(w[i]), b = huo(w[i]);

        if (st[a].size() == 0)
            f[i] = i - 1;
        else
            f[i] = i - 1 + st[a].top();
        st[b].push(f[i] - i);
    }
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        res = min(res, n - i + f[i]);
    cout << res << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}