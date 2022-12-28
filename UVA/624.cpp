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
void yesNo(bool ck){cout << (ck ? "YES\n" : "NO\n");}
//------------------------------------------------------------------------------//

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

vector<ll> finalPath;
ll dp[N][25], path[N][25];

void find_path(ll idx, ll sum, vector<ll> &v) {
    if (path[sum][idx] == -1) return;
    if (path[sum][idx] == 1) {
        finalPath.pb(v[idx]);
        find_path(idx + 1, sum + v[idx], v);
    }
    else find_path(idx + 1, sum, v);
}

ll solve(ll idx, ll sum, ll n, ll tot, vector<ll> &v) {
    if (idx >= n) return 0;
    ll &ret = dp[sum][idx];
    if (ret != -1) return ret;
    ll ans1 = 0;
    if ((sum + v[idx]) <= tot) {
        ans1 = v[idx] + solve(idx + 1, sum + v[idx], n, tot, v);
    }
    ll ans2 = solve(idx + 1, sum, n, tot, v);
    ret = ans2, path[sum][idx] = 0;
    if (ans1 > ans2) {
        ret = ans1, path[sum][idx] = 1;
    }
    return ret;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll tot, n;
        while (cin >> tot >> n) {
            vector<ll> v(n);
            for (ll i = 0; i < n; i++) {
                cin >> v[i];
            }
            for (ll i = 0; i <= tot; i++) {             
                for (ll j = 0; j <= n; j++) {
                    dp[i][j] = path[i][j] = -1;
                }
            }
            ll res = solve(0, 0, n, tot, v);
            find_path(0, 0, v);
            for (auto i : finalPath) {
                cout << i << " ";
            }
            cout << "sum:" << res << "\n";
            finalPath.clear();
        }
    }
    return 0;
}





