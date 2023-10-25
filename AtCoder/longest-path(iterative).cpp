#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 1e5 + 50, mod = 1e9 + 7;

bool vis[N];
vector<ll> A, adj[N], dp(N);

//taken the child first so we can use them further
void dfs(ll root) {
    if (vis[root]) return;
    vis[root] = 1;
    for (auto i : adj[root]) dfs(i);
    A.push_back(root);
}

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll node, edge, u, v;
    cin >> node >> edge;
    for (ll i = 1; i <= edge; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1; i <= node; i++) dfs(i);
    ll res = 1;
    for (auto i : A) {
        for (auto j : adj[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res << "\n";
  }
  return 0;
}






