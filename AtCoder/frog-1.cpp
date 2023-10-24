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
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++) cin >> v[i];
    ll dp[n + 5];
    dp[1] = 0;
    dp[2] = abs(v[1] - v[2]);
    for (ll i = 3; i <= n; i++) {
      dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
    }
    cout << dp[n] << "\n";
  }
  return 0;
}




