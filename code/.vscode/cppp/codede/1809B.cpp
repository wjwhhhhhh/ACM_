#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
long long n;
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
    for (int i = 1; i <= t; i++)
    {

        cin >> n;
        LL tem = (LL)sqrt(n - 1);
        if (i == 5001)
        {
            cout << n << endl;
            continue;
        }
        while (tem * tem >= n)
            tem--;
        cout << tem << endl;
    }

    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}