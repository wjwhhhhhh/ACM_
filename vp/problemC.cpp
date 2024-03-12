#include <bits/stdc++.h>
using namespace std;
// #define int long long
//   #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e6 + 10;
int w[N];
unordered_map<int, int> st;
vector<int> a[2 * N];
int n, k, l = 1;
bool v[2 * N];
int sum = 0;
int str[N], rt[N];
void in(int a)
{
    if (st.find(a) != st.end())
        return;
    st[a] = l++;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        w[i] = t;
        in(t), in(t + k);
        a[st[t]].push_back(t);
        if (k != 0)
            a[st[t + k]].push_back(t);
    }
    for (int j = 1; j <= n; j++)
    {
        if (!v[st[w[j]]])
        {
            int n = a[st[w[j]]].size();
            if (sum < n)
            {
                str[0] = 0, rt[0] = 0;
                for (int i = 1; i <= n; i++)
                {
                    str[i] = str[i - 1] + (a[st[w[j]]][i - 1] == w[j]);
                }
                for (int i = 1; i <= n; i++)
                {
                    rt[i] = max(str[n] + 2 * str[i - 1] - i + 1, rt[i - 1]);
                }
                int res = str[n];
                for (int i = 1; i <= n; i++)
                {
                    res = max(res, i + rt[i] - 2 * str[i]);
                }
                sum=max(res,sum);
            }
            v[st[w[j]]] = true;
        }
    }
    cout << sum << '\n';
    return 0;
}