#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 1e5, M = 1e6;
typedef pair<int, int> PII;
int f[N];
map<int, int> st;
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
        st.clear();
        int n = read();
        LL res = 0, sum = 0;
        for (int i = 1; i <= n; i++)
            f[i] = read();
        for (int i = 1; i <= n; i++)
        {
            int x = f[i];
            for (int j = 2; j <= x / j; j++)
            {
                if (x % j == 0)
                {
                    while (x % j == 0)
                        x /= j;
                    sum += i - st[j];
                    st[j] = i;
                }
            }
            if (x > 1)
            {
                sum += i - st[x];
                st[x] = i;
            }
            res = res + sum;
        }
        cout << res << "\n";
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}