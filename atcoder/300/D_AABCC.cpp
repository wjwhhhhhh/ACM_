#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define endl '\n'
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
const int N = 1e6 + 10;
bool st[N];
int prim[N], idx = 0;
void qmi(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            prim[idx++] = i;
        for (int j = 0; prim[j] <= n / i; j++)
        {
            st[prim[j] * i] = true;
            if (i % prim[j] == 0)
                break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    qmi(N - 1);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; prim[i] * prim[i] < n; i++)
    {
        for (int j = i + 1; prim[i] * prim[i] <= n / prim[j]; j++)
        {

            for (int z = j + 1; prim[i] * prim[i] * prim[j] <= n / (prim[z] * prim[j]) / prim[z]; z++)
                sum++;
        }
    }
    cout << sum << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}