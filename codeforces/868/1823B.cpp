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
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (k == 1)
        {
            cout << "0" << endl;
        }
        else
        {
            set<int> h;
            int sum = 0;
            for (int i = 1; i <= k; i++)
            {
                h.clear();
                for (int j = i; j <= n; j += k)
                    h.insert(a[j]);
                for (int j = i, l = 0; j <= n; j += k, l++)
                {
                    if (h.find(j) == h.end())
                        sum++;
                }
            }
            if (sum == 0)
                cout << "0" << endl;
            else if (sum == 2)
                cout << "1" << endl;
            else
                cout << "-1" << endl;
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}