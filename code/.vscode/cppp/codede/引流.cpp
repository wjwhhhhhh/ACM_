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
    string tem;
    getline(cin, tem);
    tem = "guan zhu " + tem + " miao, guan zhu " + tem + " xie xie miao!";
    cout << tem;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}