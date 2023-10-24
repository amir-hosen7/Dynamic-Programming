#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll n;
    cin >> n;
    ll v[n + 5][5], dp[n + 5][5];
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= 3; j++) {
        dp[i][j] = 0;
        cin >> v[i][j];
      }
    }
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= 3; j++) {
        for (ll k = 1; k <= 3; k++) {
          if (j == k) continue;
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + v[i][j]);
        }
      }
    }
    ll res = 0;
    for (ll i = 1; i <= 3; i++) {
      res = max(res, dp[n][i]);
    }
    cout << res << "\n";
  }
  return 0;
}




