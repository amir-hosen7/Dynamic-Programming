#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define Mid(b, e) b + (e - b) / 2
#define inf 1e18
double PI = 2 * acos(0.0);

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

vector<ll> final_path;
vector<pair<ll, ll>> v; 
ll tt, w, dp[35][1010], path[35][1010];

ll solve(ll idx, ll n, ll t) {
    if (idx >= n) return 0;
    ll &ret = dp[idx][t];
    if (ret != -1) return ret;
    ll res1 = 0, res2 = 0, cost = 3 * v[idx].F * w;
    if (cost <= t) {
        res1 = v[idx].S + solve(idx + 1, n, t - cost);
    }
    res2 = solve(idx + 1, n, t);
    ret = res2, path[idx][t] = 0;
    if (res1 > res2) {
        ret = res1, path[idx][t] = 1;
    }
    return ret;
}

void print_path(ll idx, ll t) {
    if (path[idx][t] == -1) return;
    if (path[idx][t] == 1) {
        final_path.pb(idx);
        print_path(idx + 1, t - (3 * v[idx].F * w));
    }
    else print_path(idx + 1, t);
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        bool ck = 0;
        while (cin >> tt >> w) {
            v.clear(); 
            final_path.clear();
            for (ll i = 0; i <= 32; i++) {
                for (ll j = 0; j <= 1002; j++) {
                    dp[i][j] = path[i][j] = -1;
                }
            }
            ll n;
            cin >> n;
            ll d, vv;
            for (ll i = 0; i < n; i++) {
                cin >> d >> vv;
                v.pb({d, vv});
            }
            if (ck) cout << "\n";
            ll res = solve(0, n, tt);
            cout << res << "\n";
            print_path(0, tt);
            ll siz = final_path.size();
            cout << siz << "\n";
            for (ll i = 0; i < siz; i++) {
                cout << v[final_path[i]].F << " " << v[final_path[i]].S << "\n";
            }
            ck = 1;
        }
    }
    return 0;
}





