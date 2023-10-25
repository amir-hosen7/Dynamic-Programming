#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e16

const ll P = 29, N = 1e5 + 50, mod = 1e9 + 7;

ll dp[110][N];

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll n, bagW;
    cin >> n >> bagW;
    ll totVal = 0, w[n + 5], v[n + 5];
    for (ll i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        totVal += v[i];
    }
    ll res = 0;
    for (ll i = 1; i <= totVal; i++) dp[0][i] = inf;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= totVal; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j < v[i]) continue;
            dp[i][j] = min(dp[i][j], w[i] + dp[i - 1][j - v[i]]);
            if (dp[i][j] <= bagW) {
                res = max(res, j);
            }
        }
    }
    cout << res << "\n";
  }
  return 0;
}




