#include <bits/stdc++.h>
#define int long long
using namespace std;
void cao(vector<int> &tem)
{
    int mi = 0, ma = 25;
    for (int i = 0; i < 26; i++)
    {
        if (tem[i] < tem[mi])mi = i;
        if (tem[i] > tem[ma])ma = i;
    }
    tem[mi]++, tem[ma]--;
}
int get(vector<int>&tem)
{
    int ans = -1;
    for (int i = 0; i < 26; i++)
    {
        ans = max(ans, tem[i]);
    }
    return ans;
}
void solves()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(26), b(26);
    string t1, t2;
    cin >> t1 >> t2;
    for (auto i : t1)
    {
        a[i - 'a']++;
    }
    for (auto i : t2)
    {
        b[i - 'a']++;
    }
    int si = 0;
    if (p == 0)
    {
        int x = get(a), y = get(b);
        //cout<<x<<" "<<y;
        if (x > y)cout << "Alice" << endl;
        else if (x == y)cout << "Draw" << endl;
        else cout << "Bob" << endl;
        return ;
    }
    if (p == 1)
    {
        cao(a), cao(b);
        int x = get(a), y = get(b);
        //cout<<x<<" "<<y;
        if (x > y)cout << "Alice" << endl;
        else if (x == y)cout << "Draw" << endl;
        else cout << "Bob" << endl;
        return ;
    }
    while (p > 1 && si <= 500)
    {
        si++, p--;
        cao(a);
        cao(b);
    }
    int x = get(a), y = get(b);
    cao(a), cao(b);
    x = min(x, get(a)), y = min(y, get(b));
    if (x > y)cout << "Alice" << endl;
    else if (x == y)cout << "Draw" << endl;
    else cout << "Bob" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}