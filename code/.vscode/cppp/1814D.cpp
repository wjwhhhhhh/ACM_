#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
// #define int __int128
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
const int N = 3100;
int f[N], d[N];
vector<int> st;
bool check(int x, int y, int tem)
{
    int a = x / tem * tem, b = (x / tem + 1) * tem;
    return a == x || b <= y;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        st.clear();
        int n = read(), k = read();
        fir(i, 1, n) f[i] = read();
        fir(i, 1, n) d[i] = read();
        fir(i, 1, n) st.push_back(f[i] * d[i]);
        sort(st.begin(), st.end());
        int ans = n;
        fir(i, 1, n)
        {
            bool fl = true;
            int cnt = 0;
            int l = max(1ll, f[i] * d[i] - k), r = f[i] * d[i] + k;
            fir(i, 1, n)
            {
                int tem = f[i] * d[i];
                if (f[i] > r || !check(l, r, f[i]))
                    fl = false;
                if (tem > r || tem < l)
                    cnt++;
            }
            if (fl)
                ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}