#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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
int find(string tem, char ch)
{
    int sum = 0;
    int i = 0, j = tem.size() - 1;
    while (i <= j)
    {
        if (tem[i] == tem[j])
            i++, j--;
        else if (tem[i] == ch)
            i++, sum++;
        else if (tem[j] == ch)
            j--, sum++;
        else
            return 0x3f3f3f3f;
    }
    return sum;
}

signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read();
        int ans = 0x3f3f3f3f;
        string tem;
        cin >> tem;
        fir(i, 0, 25) ans = min(ans, find(tem, i + 'a'));
        if (ans == 0x3f3f3f3f)
            cout << "-1" << '\n';
        else
            cout << ans << "\n";
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}