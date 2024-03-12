#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int a[N];
struct node
{
    int l, r;
    int mi;
    int mx;
} t[4 * N];
void build(int q, int l, int r)
{
    t[q].l = l, t[q].r = r;
    if (l == r)
    {
        t[q].mx = t[q].mi = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(q << 1, l, mid), build(q << 1 | 1, mid + 1, r);
    t[q].mx = max(t[q << 1].mx, t[q << 1 | 1].mx);
    t[q].mi = max(t[q << 1].mi, t[q << 1 | 1].mi);
    // cout<<t[1].dat<<endl;
}
int ask(int q, int l, int r)
{
    if (l <= t[q].l && r >= t[q].r)
        return t[q].mx;
    int mid = t[q].l + t[q].r >> 1;
    int val = -0x3f3f3f3f;
    if (l <= mid)
        val = max(val, ask(q << 1, l, r));
    if (r > mid)
        val = max(val, ask(q << 1 | 1, mid + 1, r));
    return val;
}
int ask2(int q, int l, int r)
{
    if (l <= t[q].l && r >= t[q].r)
        return t[q].mi;
    int mid = t[q].l + t[q].r >> 1;
    int val = 0x3f3f3f3f;
    if (l <= mid)
        val = min(val, ask2(q << 1, l, r));
    if (r > mid)
        val = min(val, ask2(q << 1 | 1, mid + 1, r));
    return val;
}
int n;
bool check(int x)
{
    if (x == 1)
        return 1;
    for (int i = 1; i + x - 1 <= n; i++)
    {
        int l = i, r = i + x - 1;
        int a1 = ask(1, l, r), a2 = ask2(1, l, r);
        if (abs(a1 - a2) <= 1)
            return true;
    }
    return false;
}
int main()
{

    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    int l = -1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}