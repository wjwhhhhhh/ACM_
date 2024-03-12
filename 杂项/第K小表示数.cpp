#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    i64 k, a, b;
    cin >> k >> a >> b;
    if (a > b)
        swap(a, b);
    if (__gcd(a, b) == 1)
    {
        priority_queue<int, vector<int>, greater<int>> st;
        st.push(a), st.push(b);
        k--;
        while (k--)
        {
            int h = st.top();
            st.pop();
            st.push(h + a), st.push(h + b);
        }
        cout << st.top() << endl;
    }
    else
        cout << k * a << endl;
    return 0;
}