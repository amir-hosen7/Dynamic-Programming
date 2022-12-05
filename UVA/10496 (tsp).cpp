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

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;


ll dp[12][1 << 12], n, w[22][22];

ll solve(ll idx, ll mask) {
    if (mask == (1 << n) - 1) return w[idx][0];
    ll &ret = dp[idx][mask];
    if (ret != -1) return ret;
    ll ans = inf;
    for (ll i = 0; i < n; i++) {
        bool ok = mask & (1 << i);
        if (!ok) {
            ans = min(ans, solve(i, mask | (1 << i)) + w[idx][i]);
        }
    }
    return ret = ans;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        ll row, col;
        cin >> row >> col;
        ll x, y;
        cin >> x >> y;
        cin >> n;
        n++;
        vector<pair<ll, ll>> v(n);
        v[0] = {x, y};
        for (ll i = 1; i < n; i++) {
            cin >> v[i].F >> v[i].S;
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                w[i][j] = abs(v[i].F - v[j].F) + abs(v[i].S - v[j].S);
            }
        }
        for(ll i = 0; i <= 10; i++) {
            for (ll j = 0; j < (1 << 10); j++) {
                dp[i][j] = -1;
            }
        }
        ll res = solve(0, 1);
        cout << "The shortest path has length " << res << "\n";
    }
    return 0;
}





