#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
const int LOG = 19;

int a[N], r[N], rmq[LOG][N];

void solve() {
  int n; cin >> n;
  long long res = 0;
  vector<int> s;
  a[0] = a[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    rmq[0][i] = a[i];
    res += 1ll * i * (i - 1) / 2;
  }
  cout<<res<<endl;
  s.push_back(n + 1);
  for (int i = n; i > 0; i--) {
    while (a[s.back()] > a[i])
      s.pop_back();
    r[i] = s.back();
    s.push_back(i);
  }
  for (int k = 1; k < LOG; k++)
    for (int i = (1 << k); i <= n; i++)
      rmq[k][i] = max(rmq[k - 1][i], rmq[k - 1][i - (1 << (k - 1))]);
  s.clear();
  s.push_back(0);
  for (int i = 1; i <= n; i++) {
    while (a[s.back()] > a[i])
      s.pop_back();
    int j = s.back();
    for (int k = LOG - 1; k >= 0; k--)
      if (j >= (1 << k) && rmq[k][j] < a[i])
        j -= 1 << k;
    res -= 1ll * (r[i] - i) * (s.back() - j);
    cout<<j<<endl;
    s.push_back(i);
  }
  //cout << res << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}