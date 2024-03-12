#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Tire // 字母
{
    static const int W = 2;
    int cnt;
    vector<array<int, W>> nex;
    vector<int> size;
    Tire(){};
    Tire(int n)
    {
        init(n);
    }
    void init(int n)
    {
        cnt = 0;
        nex.resize(n + 5); // 根据需要修改
        size.resize(n + 5);
    }
    int add(int t)
    {
        int p = 0;
        for (int i = 34; i >= 0; i--)
        {
            int c = t >> i & 1;
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
            size[p]++;
        }
        return p;
    }
    void erase(int t)
    {
        int p = 0;
        for (int i = 34; i >= 0; i--)
        {
            int c = t >> i & 1;
            p = nex[p][c];
            size[p]--;
        }
    }
    int find(int t, int h) // 找出现次数
    {                      // 查找字符串
        int p = 0, si = 0;
        for (int i = 34; i >= 0; i--)
        {
            int c = t >> i & 1;
            int er = h >> i & 1;
            if (er == 1)
            {
                if (nex[p][!c] && size[nex[p][!c]])
                {
                    p = nex[p][!c];
                }
                else
                    break;
            }
            else
            {
                if (nex[p][!c] && size[nex[p][!c]])
                {
                    si += size[nex[p][!c]];
                }
                if (nex[p][c] && size[nex[p][c]])
                {
                    p = nex[p][!c];
                }
                else
                    break;
            }
            if (i == 0)
                si += size[p];
        }
        return si;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int q, hp;
    cin >> q >> hp;
    Tire tr(q * 35);
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 0)
        {
            int x;
            cin >> x;
            tr.add(x);
        }
        else if (flag == 1)
        {
            int x;
            cin >> x;
            tr.erase(x);
        }
        else
        {
            int h, x;
            cin >> x >> h;
            int si = tr.find(x, h);
            cout << si << endl;
            if (si == 0)
                hp--;
        }
    }
    cout << hp << endl;
    return 0;
}