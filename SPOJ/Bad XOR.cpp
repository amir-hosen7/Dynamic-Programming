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
const ll mod = 100000007;

ll dp[1010][3010];
unordered_map<ll, bool> mark;

ll solve(ll idx, ll XOR, ll n, vector<ll>& v) {
    if (idx >= n) {
        if (mark[XOR] == 0) return 1;
        return 0;
    }
    ll &ret = dp[idx][XOR];
    if (ret != -1) return ret;
    ll ans1 = solve(idx + 1, XOR, n, v);
    ll ans2 = solve(idx + 1, XOR ^ v[idx], n, v);
    return ret = (ans1 + ans2) % mod;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        memset(dp, -1, sizeof(dp));
        mark.clear();
        ll n, m;
        cin >> n >> m;
        vector<ll> A(n), B(m);
        for (ll i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (ll i = 0; i < m; i++) {
            cin >> B[i];
            mark[B[i]] = 1;
        }
        ll res = solve(0, 0, n, A);
        cout << "Case " << T << ": " << res << "\n";
    }
    return 0;
}





