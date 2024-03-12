#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 2e5 + 10;
int n, k;
int l[N], r[N];
vector<PII> st;
int sum1[N], sum2[N];
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
        cin >> n >> k;
        fir(i, 1, n) cin >> l[i];
        fir(i, 1, n) cin >> r[i];
        long long sum = 0, ans;
        fir(i, 1, n) sum += (r[i] - l[i] + 1);
        if (sum < k)
        {
            cout << "-1" << endl;
            continue;
        }
        int a = l[1], b = r[1];
        for (int i = 2; i <= n; i++)
        {
            if (l[i] - 1 == b)
                b = r[i];
            else
            {
                st.push_back({a, b});
                a = l[i], b = r[i];
            }
        }
        st.push_back({a, b});
        for (int i = 1; i <= st.size(); i++)
        {
            cout << st[i - 1].second;
            if (st[i - 1].first == st[i - 1].second)
                sum1[i] = sum1[i - 1] + 1, sum2[i] = sum2[i - 1];
            else
                sum1[i] = sum1[i - 1], sum2[i] = sum2[i - 1] + st[i - 1].second - st[i - 1].first + 1;
        }
        ans = 2e18;
        for (int i = 1; i <= st.size(); i++)
        {
            if (sum1[i] + sum2[i] < k)
                continue;
            int len = max(k - sum2[i - 1] - sum1[i - 1], 0ll);
            len = st[i - 1].first + len - 1;
            int si = min(sum1[i - 1], st[i - 1].second - len);
            len += si;
            ans = min(ans, 2ll * (i - si) + len);
        }
        cout << ans << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}