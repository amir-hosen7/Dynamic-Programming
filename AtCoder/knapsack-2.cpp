#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e16

const ll P = 29, N = 1010, mod = 1e9 + 7;

ll w[N], v[N], dp[110][100010], n;

ll solve(ll idx, ll val) {
    if (idx > n or val <= 0) return (val == 0) ? 0 : inf;
    ll &ret = dp[idx][val];
    if (ret != -1) return ret;
    ll ans1 = w[idx] + solve(idx + 1, val - v[idx]);
    ll ans2 = solve(idx + 1, val);
    return ret = min(ans1, ans2);
}

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll bagW;
    cin >> n >> bagW;
    ll totVal = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        totVal += v[i];
    }
    memset(dp, -1, sizeof(dp));
    for (ll i = totVal; i >= 0; i--) {
        if (solve(1, i) <= bagW) {
            cout << i << "\n"; break;
        }
    }
  }
  return 0;
}





