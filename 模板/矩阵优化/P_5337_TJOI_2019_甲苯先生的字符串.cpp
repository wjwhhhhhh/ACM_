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
const int N = 26, M = 1e9 + 7;
int ans[N][N], f[N][N];
void mul(int A[N][N], int B[N][N], int C[N][N])
{
    int tem[N][N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                tem[i][j] = (tem[i][j] + B[i][k] * C[k][j] % M) % M;
            }
    memcpy(A, tem, sizeof tem);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    string tem;
    cin >> tem;
    for (int i = 0; i < N; i++)
        ans[0][i] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            f[i][j] = 1;
    for (int i = 1; i < tem.size(); i++)
    {
        int a = tem[i - 1] - 'a', b = tem[i] - 'a';
        f[a][b] = 0;
    }
    n--;
    while (n)
    {
        if (n & 1)
            mul(ans, ans, f);
        mul(f, f, f);
        n >>= 1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum = (sum + ans[0][i]) % M;
    cout << sum << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}