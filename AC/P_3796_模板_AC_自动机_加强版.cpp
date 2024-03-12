#include <bits/stdc++.h>
using namespace std;
struct AC
{
    queue<int> q;
    vector<array<int, 26>> tr;
    int tot;
    vector<int> fail, val, idx; // 出现的次数，出现的是第几个字符串
    AC()
    {
    }
    AC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        tot = 0;
        tr.resize(n), val.resize(n, 0), fail.resize(n, 0), idx.resize(n, 0);
    }
    void insert(string s, int id)
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!tr[u][s[i] - 'a'])
                tr[u][s[i] - 'a'] = ++tot; // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];         // 搜索下一个节点
        }
        idx[u] = id;
    }
    void build()
    {
        for (int i = 0; i < 26; i++)
            if (tr[0][i])
                q.push(tr[0][i]);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                if (tr[u][i])
                {
                    fail[tr[u][i]] = tr[fail[u]][i]; // fail数组：同一字符可以匹配的其他位置
                    q.push(tr[u][i]);
                }
                else
                    tr[u][i] = tr[fail[u]][i];
            }
        }
    }

    int query(string t)
    { // 返回最大的出现次数
        int u = 0, res = 0;
        for (int i = 0; i < t.size(); i++)
        {
            u = tr[u][t[i] - 'a'];
            for (int j = u; j; j = fail[j])
                val[j]++;
        }
        for (int i = 0; i <= tot; i++)
            if (idx[i])
                res = max(res, val[i]); //, cnt[idx[i]] = val[i];
        return res;
    }
};
const int N = 70 * 160;
string cnt[160];
void solve(int t)
{
    AC tt(N);
    for (int i = 1; i <= t; i++)
    {
        cin >> cnt[i];
        tt.insert(cnt[i], i);
    }
    tt.build();
    string ans;
    cin >> ans;
    auto tw = tt.query(ans);
    cout << tw << endl;
    for (int i = 0; i <= tt.tot; i++)
    {
        if (tt.idx[i] && tt.val[i] == tw)
            cout << cnt[tt.idx[i]] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    while (cin >> t, t)
    {
        solve(t);
    }
    return 0;
}