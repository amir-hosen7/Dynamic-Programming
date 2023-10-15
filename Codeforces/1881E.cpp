#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;


vector<ll> v(N), dp(N);

ll solve(ll idx, ll n) {
  if (idx == n) return 0;
  ll &ret = dp[idx];
  if (ret != -1) return ret;
  ll curr = idx + v[idx], ans;
  if (curr >= n) {
    ll ans1 = 1 + solve(idx + 1, n);
    ll ans2 = n - idx;
    ans = min(ans1, ans2);
  }
  else {
    ll ans1 = solve(curr + 1, n);
    ll ans2 = 1 + solve(idx + 1, n);
    ans = min(ans1, ans2);
  }
  return ret = ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  //https://codeforces.com/contest/1881/problem/E
  
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll n;
    cin >> n;
    v.resize(n);
    for (ll i = 0; i < n; i++) { cin >> v[i]; dp[i] = -1; }
    ll res = solve(0, n);
    cout << res << "\n";
  }
  return 0;
}



