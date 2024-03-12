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
const int N = 2e5 + 10;
multiset<int> xiang[N];
set<int> ka[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, n;
    cin >> n;
    cin >> q;
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            int a, b;
            cin >> a >> b;
            xiang[b].insert(a);
            ka[a].insert(b);
        }
        else if (flag == 2)
        {
            int a;
            cin >> a;
            for (auto i : xiang[a])
                cout << i << " ";
            cout << '\n';
        }
        else
        {
            int a;
            cin >> a;
            for (auto i : ka[a])
                cout << i << " ";
            cout << '\n';
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}