#include <algorithm>
#include <cstring>
#include <iostream>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
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
int main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        string tem, ans = "";
        cin >> tem;
        int s = 0;
        for (auto ch : tem)
        {
            if (ch == '0')
                ans += (char)(('a' - 1) + s), s = 0;
            else
                s += (ch - ('1' - 1));
        }
        if (s)
            ans += (char)(('a' - 1) + s);
        cout << ans << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}