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
map<int, int> st;
int main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        st.clear();
        string tem;
        cin >> tem;
        for (auto i : tem)
            st[i - '0']++;
        if (st.size() == 1)
            puts("-1");
        else if (st.size() == 3 || st.size() == 4)
            puts("4");
        else if (st.begin()->second == 2)
            puts("4");
        else
            puts("6");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}