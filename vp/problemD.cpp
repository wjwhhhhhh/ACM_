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
const int N = 2e6 + 10;
int tr2[N];
int n;
bool v[N];
map<int, int> mp, li;
int lowbit(int x)
{
    return x & -x;
}
void update(int x)
{

    for (int t = x; t <= n; t += lowbit(t))
        tr2[t] += 1;
}
int ask(int x)
{
    if (x <= 0)
        return 0;
    int sum = 0;
    for (int t = x; t; t -= lowbit(t))
        sum += tr2[t];
    return sum;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(tr2, 0, 4 * (n + 10));
        memset(v, 0, n + 10);
        mp.clear(), li.clear();
        int maxn = 0, sum = 0;
        vector<int> er, gr;
        er.clear(), gr.clear();
        gr.push_back(0);
        int who = 0;
        for (int i = 1; i <= n; i++)
        {
            int tem;
            cin >> tem;
            er.push_back(tem), gr.push_back(tem);
        }
        sort(er.begin(), er.end());
        er.erase(unique(er.begin(), er.end()), er.end());
        int l = 0;
        for (auto i : er)
            li[i] = ++l;
        for (int i = 1; i <= n; i++)
        {
            int tem;
            tem = gr[i];
            int si = li[tem];
            if (i == 1)
                sum = 0;
            else if (maxn < tem)
            {
                if (mp[maxn] > 1)
                    sum += mp[maxn] + who + 1;
                else
                    sum += 2;
            }
            else
            {
                int te = ask(l - si);
                sum += te;
            }
            if (!v[l + 1 - si])
            {
                update(l + 1 - si);
                v[l + 1 - si] = true;
            }
            if (mp[maxn] >= 2 && tem < maxn)
                who++;
            else if (tem > maxn)
                maxn = tem, who = 0;
            mp[tem]++;
            cout << sum;
            if (i != n)
                cout << " ";
        }
        cout << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}