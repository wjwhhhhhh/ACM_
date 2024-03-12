#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
// #define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i < b; i++)
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
vector<PII> st;
vector<int> x, y;
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        st.clear(), x.clear(), y.clear();
        int n = read(), a = read(), b = read();
        fir(i, 1, n + 1)
        {
            int tem = read();
            // cout << tem;
            st.push_back({tem, i});
        }
        // cout << st.size();
        sort(st.begin(), st.end());

        reverse(st.begin(), st.end());
        int l = a, r = b;

        for (auto ch : st)
        {
            if (l < r)
                x.push_back(ch.second), l += a;
            else
                y.push_back(ch.second), r += b;
        }

        cout << x.size() << " ";
        fir(i, 0, x.size()) cout << x[i] << " ";
        puts("");
        cout << y.size() << " ";
        fir(i, 0, y.size()) cout << y[i] << " ";
        puts("");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}