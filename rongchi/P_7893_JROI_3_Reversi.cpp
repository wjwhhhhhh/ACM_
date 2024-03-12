#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Tree_array
{
    vector<int> tr;
    int maxx;
    Tree_array(int n)
    {
        init(n);
    }
    void init(int n)
    {
        maxx = n;
        tr.assign(n + 1, 0);
    }
    void insert(int x, int c)
    {
        for (int i = x; i <= maxx; i += lowbit(i))
            op(i, c);
    }
    int ask(int x)
    {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void op(int x, int c)
    {
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}