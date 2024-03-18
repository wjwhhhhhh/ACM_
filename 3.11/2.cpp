#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    i64 an = 0;
    for (int i = a; i > 0; i--)
    {
        i64 t = 1ll << (i - 1);
        if (b >= t)
        {
            an += 1 << (i - 1);
            b = t * 2 - b;
        }
    }
    string ans;
    while (an)
    {
        int t = an % 2;
        ans += char('0' + t);
        an /= 2;
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() != a)
        cout << "0";
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")