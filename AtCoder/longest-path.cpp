#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 1e5 + 50, mod = 1e9 + 7;

ll dp[N];
vector<ll> adj[N];

ll solve(ll root) {
    if (dp[root] != -1) return dp[root];
    ll ans = 0;
    for (auto i : adj[root]) {
        ans = max(ans, 1 + solve(i));
    }
    return dp[root] = ans;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll node, edge, u, v;
    cin >> node >> edge;
    for (ll i = 0; i <= node; i++) dp[i] = -1;
    for (ll i = 1; i <= edge; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ll res = 1;
    for (ll i = 1; i <= node; i++) {
        res = max(res, solve(i));
    }
    cout << res << "\n";
  }
  return 0;
}





