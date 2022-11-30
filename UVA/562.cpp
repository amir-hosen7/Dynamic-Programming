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

vector<ll> v;
ll dp[110][50010], n, sum;

ll solve(ll idx, ll curr) {
    if (idx == n) return abs(curr - (sum - curr));
    ll &ret = dp[idx][curr];
    if (ret != -1) return ret;
    return ret = min(solve(idx + 1, curr + v[idx]), solve(idx + 1, curr));
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        sum = 0;
        for (ll i = 0; i <= 100; i++) {
            for (ll j = 0; j <= 50010; j++) {
                dp[i][j] = -1;
            }
        }
        cin >> n;
        v.clear(); v.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        ll res = solve(0, 0);
        cout << res << "\n";
    }
    return 0;
}





