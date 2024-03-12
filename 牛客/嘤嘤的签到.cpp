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
const int N = 1e6 + 10;
int a[N];
vector<int> at;
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    int l = 0, r = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        scanf("%1d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        // cout << a[i];
        if (a[i] == 4 || a[i] == 1)
        {
            if (l == 0||a[l]==a[i])
                l = i;
            else if (a[i] == a[r] || r == 0)
            {
                r = l, l = i;
            }
            
        }
        sum += i - r;
    }
    cout << sum << endl;
    // freopen("test.txt", "r", stdin);
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}