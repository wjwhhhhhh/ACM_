#include <bits/stdc++.h>
const int bug = false;
#define dug(x)                                                                                                         \
    if (bug)                                                                                                           \
    cerr << "死了吧小丑" << x << endl
#define fir(i, a, b) for (int i = a; i < b; i++)
#define far(a, b) for (auto a : b)
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
vector<int> Duval(string &a)
{
    vector<int> ans;
    for (int i = 0; i < a.size();)
    {
        int j = i, k = i + 1; // 初始化
        while (k < a.size() && a[j] <= a[k])
        {
            if (a[j] < a[k])
                j = i; // 合并为一整个
            else
                j++; // 保持循环不变式
            k++;
        }
        while (i <= j) // 从v的开头重新开始
        {
            ans.push_back(i + k - j - 1);
            i += k - j;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    auto p = Duval(a);
    int t = 0;
    for (auto c : p)
        t ^= (c + 1);
    cout << t << '\n';
    return 0;
}