#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
const int N = 110;
int A[N][N], B[N][N];
int n;
bool xi()
{
    fir(i, 1, n) fir(j, 1, n) if (A[i][j] == 1 && B[i][j] == 0) return false;
    return true;
}
void roll()
{
    int tem[N][N];
    fir(i, 1, n) fir(j, 1, n) tem[i][j] = A[n + 1 - j][i];
    memcpy(A, tem, sizeof tem);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);

    cin >> n;
    bool fl = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A[i][j];
    for (int i = 1; i <= n; i++)
        fir(j, 1, n) cin >> B[i][j];
    for (int i = 0; i < 4 && !fl; i++)
    {
        fl = xi();
        // if (fl)
        //     cout << i << "";
        roll();
    }
    if (fl)
        puts("Yes");
    else
        puts("No");
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}