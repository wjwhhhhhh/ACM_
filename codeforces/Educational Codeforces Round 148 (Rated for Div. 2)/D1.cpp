#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N], b[N];
int n, q;
bool check(int x, int k)
{
    for (int i = 1; k && i < n; i++, k--)b[i] += k;
    if (k & 1)b[n]+=k--;


        k /= 2;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > x)
        {
            k -= b[i] - x;
        }
        else return false;
    }
    return k <= 0;
}
void solves()
{
    int k;
    cin >> k;
    memcpy(b, a, sizeof a);
    int l = 0, r = 0x3f3f3f3f;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid, k))l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + 1 + n);
    while (q--)
    {
        solves();
    }
    return 0;
}