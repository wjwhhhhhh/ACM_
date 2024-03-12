#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#include <bits/stdc++.h>
using namespace std;
struct Tire//字母
{
    static const int W = 26;
    int cnt;
    vector<array<int, W>> nex;
    vector<int> size;
    Tire() {};
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
    void add(string t)
    {
        int p = 0;
        for (int i = 0; i < t.size(); i++)
        {
            int c = t[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
        }
        size[p]++;
    }
};
int f[5100][5100];
bool st[5100][5100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    Tire a(5100), b(5100);
    for (int i = 1; i <= n; i++)
    {
        string tem;
        cin >> tem;
        a.add(tem);
    }
    for (int i = 1; i <= m; i++)
    {
        string tem;
        cin >> tem;
        b.add(tem);
    }
    queue<pair<int, int> > q;
    f[0][0] = 0;
    q.push({0, 0});
    while (q.size())
    {
        auto [x, y] = q.front();
        if (st[x][y])continue;
        st[x][y] = true;
        q.pop();
        int tem=f[x][y];
        if (a.size[x] && b.size[y])
        {
            cout << tem << endl;
            return 0;
        }
        for (int i = 0; i < 26; i++)
        {
            int t1 = a.nex[x][i], t2 = b.nex[y][i];
            if (t1 && t2 && !st[t1][t2])
            {
                f[t1][t2] = tem + 1;
                q.push({t1, t2});
            }
        }
        if (a.size[x])
        {
            x = 0;
            for (int i = 0; i < 26; i++)
            {
                int t1 = a.nex[x][i], t2 = b.nex[y][i];
                if (t1 && t2 && !st[t1][t2])
                {
                    f[t1][t2] = tem + 1;
                    q.push({t1, t2});
                }
            }
        }
        if(b.size[y])
        {
            y = 0;
            for (int i = 0; i < 26; i++)
            {
                int t1 = a.nex[x][i], t2 = b.nex[y][i];
                if (t1 && t2 && !st[t1][t2])
                {
                    f[t1][t2] = tem + 1;
                    q.push({t1, t2});
                }
            }
        }
    }
    cout << "-1" << endl;
    //cout<<a.nex[1][1];
    return 0;
}