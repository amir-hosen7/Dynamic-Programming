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

ll dp[25][210];

ll toInt(string s) {stringstream ss; ss<<s; ll n; ss>>n; return n;}

ll solve(ll idx, ll n, vector<ll> &v, ll curr, ll tot) {
    if (idx >= n) return abs(curr - (tot - curr));
    ll &ret = dp[idx][curr];
    if (ret != -1) return ret;
    return ret = min(solve(idx + 1, n, v, curr + v[idx], tot), solve(idx + 1, n, v, curr, tot));
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    cin >> t;
    cin.ignore();
    for (ll T = 1; T <= t; T++) {
        string str;
        getline(cin, str);
        stringstream ss;
        ss << str;
        ll val, sum = 0;
        vector<ll> v;
        while (ss >> val) {
            v.pb(val);
            sum += val;
        }
        if (sum & 1) {
            cout << "NO\n"; continue;
        }
        memset(dp, -1, sizeof(dp));
        ll ok = solve(0, v.size(), v, 0, sum);
        if (!ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}





