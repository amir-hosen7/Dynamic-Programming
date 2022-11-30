#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//

//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

ll dp[210][1150][15];
vector<ll> prime;
bitset<N+50> isPrime;

void sieve() {
    ll srt = sqrt(N) + 1;
    for (ll i = 2; i <= srt; i++) {
        if (isPrime[i] == 0) {
            for (ll j = i * i; j <= N; j += i) {
                isPrime[j] = 1;
            }
        }
    }
    for (ll i = 2; i <= N; i++) {
        if (isPrime[i] == 0) prime.pb(i);
    }
}

ll solve(ll idx, ll n, ll k) {
    if (n <= 0 or k <= 0 or idx >= 200) {
        if (n == 0 and k == 0) return 1;
        else return 0;
    }
    ll &ret = dp[idx][n][k];
    if (ret != -1) return ret;
    ll ans1 = solve(idx + 1, n - prime[idx], k - 1);
    ll ans2 = solve(idx + 1, n, k);
    return ret = ans1 + ans2;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    sieve();

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll n, k;
        while (cin >> n >> k) {
            if ((n + k) == 0) break;
            for (ll i = 0; i <= 200; i++) {
                for (ll j = 0; j <= 1124; j++) {
                    for (ll k = 0; k <= 14; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }
            ll res = solve(0, n, k);
            cout << res << "\n";
        }
    }
    return 0;
}





