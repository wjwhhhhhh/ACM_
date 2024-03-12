#include <bits/stdc++.h>
using namespace std;
#define int long long
//  #define int __int128
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
const int N = 1e6 + 10, M = 998244353;
LL lg[N];
LL q[N];
int tt = 0, hh = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    lg[1] = 1;
    for (int i = 2; i < N; i++)
        lg[i] = (10 * lg[i - 1]) % M;
    int qq;
    cin >> qq;
    LL ans = 1;
    while (qq--)
    {
        int flag;
        cin >> flag;
        q[0] = 1;
        if (flag == 1)
        {
            int a;
            cin >> a;
            q[++tt] = a;
            ans = (ans * 10 + a) % M;
        }
        else if (flag == 2)
        {

            int len = tt - hh + 1;
            ans = (ans + M - q[hh++] * lg[len]) % M;
        }
        else
            cout << (ans + M) % M << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}