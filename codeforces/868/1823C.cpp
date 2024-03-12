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
const int N = 1010;
int a[N];
map<int, int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        st.clear();
        int n;
        cin >> n;
        fir(i, 1, n) cin >> a[i];
        fir(i, 1, n)
        {
            int t = a[i];
            for (int j = 2; j <= t / j; j++)
            {
                if (t % j == 0)
                {
                    while (t % j == 0)
                    {
                        st[j]++;
                        t /= j;
                    }
                }
            }
            if (t != 1)
                st[t]++;
        }
        int sum = 0, res = 0;
        for (auto i : st)
        {
            sum += i.second / 2;
            res += i.second % 2;
        }
        sum += res / 3;
        cout << sum << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}