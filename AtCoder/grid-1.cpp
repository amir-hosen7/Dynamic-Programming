#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 1010, mod = 1e9 + 7;

ll dp[N][N];

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll row, col;
    cin >> row >> col;
    char grid[row + 1][col + 1];
    for (ll i = 1; i <= row; i++) {
        for (ll j = 1; j <= col; j++) {
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 1;
    for (ll i = 1; i <= row; i++) {
        for (ll j = 1; j <= col; j++) {
            if (grid[i][j] == '#') continue;
            dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << dp[row][col] << "\n";
  }
  return 0;
}





