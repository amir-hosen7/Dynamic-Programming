#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const ll P = 29, N = 1e6 + 50, mod = 1e9 + 7;

ll memo[N][5];

ll solve(ll n, ll status) {
  if (n <= 2) {
    if (status == 1) return 1;
    return 0;
  }
  if (n == 3) {
    if (status == 1) return 2;
    if (status == 2) return 0;
    return 1;
  }
  ll &ret = memo[n][status];
  if (ret != -1) return ret;
  if (status == 1) {
    return ret = (solve(n - 1, 1) + solve(n - 3, 1) + (2 * solve(n - 2, 2))) % mod;
  }
  else if (status == 2) {
    return ret = (solve(n - 1, 3) + solve(n - 3, 2)) % mod;
  }
  else {
    return ret = (solve(n - 3, 1) + solve(n - 3, 3)) % mod;
  }
}

ll dp[N];

ll two(ll n) {
  if (n == 1) return 0;
  if (n <= 3) return 1;
  if (dp[n] != -1) return dp[n];
  return dp[n] = (two(n - 2) + two(n - 3)) % mod;
}


int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  //https://www.codechef.com/INOIPRAC/problems/INOI2002

  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll k, n;
    cin >> k >> n;
    if (k == 1) {
      ll res = 0;
      if (n % 3 == 0) res = 1;
      cout << res << "\n";
    }
    else if (k == 2) {
      for (ll i = 0; i <= n; i++) dp[i] = -1;
      ll res = two(n);
      cout << res << "\n";
    }
    else {
        for (ll i = 0; i <= n; i++) {
          for (ll j = 0; j <= 3; j++) {
            memo[i][j] = -1;
          }
        }
        ll res = solve(n, 1);
        cout << res << "\n";
    }
  }
  return 0;
}




