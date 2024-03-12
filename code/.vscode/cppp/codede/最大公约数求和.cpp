#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5 + 10;
struct nodes
{
    int l, r, w;
    int lsum.rsum;
} p[4 * N];
int n, k, a, b, q;
void build(int u, int l, int r)
{
    p[u].l = l, p[u].r = r;
    if (l == r)
    {
        p[u].w = p[u].lsum = p[u].rsum = 0;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    p[u].w = p[u].lsum = p[u].rsum = 0;
}
void update(int u, int x, int v)
{
    if (p[u].l == x && p[u].l == p[u].r)
    {
        p[u].w += v;
        p[u].lsum = min(a, )
    }
}
int main()
{
    cin >> n >> k >> a >> b >> q;
    build(1, 1, n);
    while (q--)
    {
    }
}