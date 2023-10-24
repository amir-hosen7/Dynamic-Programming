#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const ll P = 29, N = 1e5 + 50, mod = 1e9 + 7;

ll dp[110][N];

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll n, bagW;
    cin >> n >> bagW;
    ll w[n + 5], v[n + 5];
    for (ll i = 1; i <= n; i++) {
      cin >> w[i] >> v[i];
    }
    for (ll i = 1; i <= n; i++) {
      for (ll j = 0; j <= bagW; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j < w[i]) continue;
        dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
      }
    }
    cout << dp[n][bagW] << "\n";
  }
  return 0;
}




