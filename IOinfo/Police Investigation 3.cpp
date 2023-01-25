#include<iostream>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;
typedef long long ll;

ll dp[200000][2];

ll solve(ll idx, ll n, vector<ll>& v, ll status) {
    if (idx >= n) return 0;
    ll &ret = dp[idx][status];
    if (ret != -1) return ret;
    ll ans;
    if (status) {
        ans = v[idx] + solve(idx + 1, n, v, 0);
    }
    else {
        ll ans1 = v[idx] + solve(idx + 1, n, v, 0);
        ll ans2 = solve(idx + 1, n, v, 1);
        ans = min(ans1, ans2);
    }
    return ret = ans;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (ll i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = -1;
    }
    ll res = solve(0, n, v, 0);
    cout << res << "\n";
    return 0;
}
