#include <bits/stdc++.h>
// #define int long long
// #define int __int128
using namespace std;
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
typedef unsigned int ui;
ui randNum(ui &seed, ui last, const ui m)
{
    seed = seed * 17 + last;
    return seed % m + 1;
}
multiset<PII> sr;
PII jiazhi[N];
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    int last = 7;
    while (t--)
    {
        sr.clear();
        met(jiazhi, 0);
        int m, n;
        ui seed;
        cin >> m >> n >> seed;
        for (int i = 1; i <= m; i++)
            sr.insert({jiazhi[i].first, jiazhi[i].second});
        for (int i = 1; i <= n; i++)
        {
            int num = randNum(seed, last, m);
            int time = randNum(seed, last, m);
            PII tem = {jiazhi[num].first + 1, jiazhi[num].second - time};
            auto l = sr.lower_bound(tem);
            last = sr.end() - l;
            cout << last << '\n';
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}