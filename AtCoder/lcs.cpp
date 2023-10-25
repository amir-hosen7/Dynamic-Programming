#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 3010, mod = 1e9 + 7;

ll dp[N][N];

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    //cout << dp[n][m] << "\n";
    ll i = n, j = m;
    string res;
    while (i >= 1 and j >= 1) {
        if (dp[i][j] != dp[i][j - 1] and dp[i][j] != dp[i - 1][j]) {
            res += t[j - 1];
            i--; j--;
        }
        else if (dp[i][j] == dp[i][j - 1]) j--;
        else i--;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
  }
  return 0;
}





