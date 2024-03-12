#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100;
bool st[N][N][N];
int n;
bool dfs(int x, int y, int z)
{
    if (st[x][y][z])
        return false;
    st[x][y][z] = true;
    if (x > 1 && !dfs(x - 1, y, z))
        return true;
    if (y > 1 && !dfs(x, y - 1, z))
        return true;
    if (z > 1 && !dfs(x, y, z - 1))
        return true;
    if (x < n && !dfs(x + 1, y, z))
        return true;
    if (y < n && !dfs(x, y + 1, z))
        return true;
    if (z < n && !dfs(x, y, z + 1))
        return true;
    return false;
}
bool solve(int r, int g, int b)
{
    memset(st, 0, sizeof st);
    //    cin>>n>>r>>g>>b;
    if (dfs(r, g, b))
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if (solve(4,4 , ))
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return 0;
}