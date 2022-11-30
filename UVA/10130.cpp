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

//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

ll dp[1010][35];
vector<pair<ll, ll>> A;

ll solve(ll idx, ll n, ll curr) {
    if (idx >= n) {
        return 0;
    }
    ll &ret = dp[idx][curr];
    if (ret != -1) return ret;
    ll ans1 = 0;
    if (curr >= A[idx].S) ans1 = A[idx].F + solve(idx + 1, n, curr - A[idx].S);
    ll ans2 = solve(idx + 1, n, curr);
    return ret = max(ans1, ans2);
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        ll n;
        cin >> n;
        A.clear(); A.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> A[i].F >> A[i].S;
        }
        ll g;
        cin >> g;
        ll res = 0;
        while (g--) {
            ll cap;
            cin >> cap;
            memset(dp, -1, sizeof(dp));
            res += solve(0, n, cap);
        }
        cout << res << "\n";
    }
    return 0;
}





