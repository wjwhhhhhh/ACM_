#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
const int N = 2e5 + 10;
int b[N], a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
            cout << "1" << endl;
        else if (n & 1)
            cout << "-1" << endl;
        else
        {
            int l = 1, r = n;
            for (int i = 1; i <= n; i++)
            {
                if (i & 1)
                    b[i] = l++;
                else
                    b[i] = r--;
            }
            a[1] = n;
            for (int i = 2; i <= n; i++)
            {
                a[i] = (b[i] - b[i - 1] + n) % n;
                // if (i == 3)
                //     cout << b[i - 1] % n;
            }
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}