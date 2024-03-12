#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
vector<int> st;
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        st.clear();
        int n;
        cin >> n;
        if (n % 2 == 0)
            puts("-1");
        else
        {
            for (int i = 0; i < 40 && n != 1; i++)
            {
                if ((n - 1) % 4 != 0)
                {
                    st.push_back(2);
                    n = (n - 1) / 2;
                }
                else
                {
                    st.push_back(1);
                    n = (n + 1) / 2;
                }
            }
            if (n != 1)
            {
                puts("-1");
            }
            else
            {
                cout << st.size() << endl;
                for (int i = st.size() - 1; i >= 0; i--)
                    cout << st[i] << " ";
                puts("");
            }
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}