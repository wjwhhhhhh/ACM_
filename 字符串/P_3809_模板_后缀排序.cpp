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
// 默认从0开始
// 倍增  O(nlog(n))
struct SA
{
#define F(x) ((x) / 3 + (x % 3 == 1 ? 0 : 0))
#define G(x) ((X) < tb)
    vector<int> sa; // 表示将所有后缀排序后第 i 小的后缀的编号，也是所说的后缀数组，后文也称编号数组 sa；
    vector<int> rk; // rk[i] 表示后缀 i 的排名，是重要的辅助数组，后文也称排名数组 rk。
    // 这两个数组满足性质：sa[rk[i]]=rk[sa[i]]=i。
    void init(int n)
    {
        rk.resize(3 * n), sa.resize(3 * n);
    }
    void dc3(int r, int s, int n, int m = 127)
    {
        int rn = r + n, sn = s + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
        // 递归处理r和sa的开头，ta为模3为0，tb为模3为1
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    string a;
    cin >> a;
    SA S(a);
    for (int i = 1; i <= a.size(); i++)
        cout << S.sa[i] << " ";
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}