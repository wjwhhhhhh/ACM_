#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
struct Tire // 字母
{
    static const int W = 26;
    int cnt;
    vector<array<int, W>> tr;
    vector<int> size;
    Tire(){};
    Tire(int n)
    {
        init(n);
    }
    void init(int n)
    {
        cnt = 0;
        tr.resize(n + 5); // 根据需要修改
        size.resize(n + 5);
    }
    void add(string t, int len)
    {
        int p = 0;
        for (int i = 0; i < t.size(); i++)
        {
            int c = t[i] - 'a';
            if (!tr[p][c])
                tr[p][c] = ++cnt; // 如果没有，就添加结点
            p = tr[p][c];
            if (i <= len)
                size[p]++;
        }
    }
    int find(string s) // 找出现次数
    {                  // 查找字符串
        int p = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            for (int j = 0; j < 26; j++)
            {
                if (tr[p][j] && j != c)
                    res += size[tr[p][j]];
            }
            if (!tr[p][c])
                return res;
            p = tr[p][c];
        }
        for (int j = 0; j < 26; j++)
        {
            if (tr[p][j])
                res += size[tr[p][j]];
        }
        return res;
    }
};
const int N = 1e6 + 10;
string th = "lenovo";
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    Tire tree(N);
    int q;
    cin >> q;
    while (q--)
    {
        int fl;
        cin >> fl;
        string a;
        cin >> a;
        if (fl == 1)
        {
            int len = -1;
            for (int i = (int)a.size() - 6; i >= 0; i--)
            {
                if (a.substr(i, 6) == th)
                {
                    len = i;
                    break;
                }
            }
            tree.add(a, len);
        }
        else
        {
            cout << tree.find(a) << endl;
        }
    }
    return 0;
}