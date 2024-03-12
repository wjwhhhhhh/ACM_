#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int a[20], b[20], c[20];
int idx;
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
void ch(int tem, int re[])
{
    idx = 1;
    while (tem)
    {
        re[idx++] = tem % 10;
        tem /= 10;
    }
}
int k, kai, weici;
bool dfs(int xian, int wei)
{
    if (a[wei + 1] > xian || b[wei + 1] < xian)
        return false;
    if (wei == 0)
        return true;
    for (int j = i; j <= i + k; j++)
    {
        if (j == 0 && weici == wei)
            continue;
        if (dfs(xian * 10 + j, wei - 1))
            return true;
    }
    return false;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int l = read(), r = read();
        int mi = 10;
        ch(l, a), ch(r, b);
        for (int i = idx - 1; i > 0; i--)
        {
            a[i] += a[i + 1] * 10ll;
            b[i] += b[i + 1] * 10ll;
        }
        k = 0;
        while (1)
        {
            for (weici = 1; weici < idx; weici++)
                for (kai = 0; kai + k < 10; kai++)
                    if (dfs(0, wei))
                    {
                        cout << k;
                        return;
                    };
        }
        k++;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}