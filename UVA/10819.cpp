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

ll totMoney;
ll dp[110][10500];
vector<pair<ll, ll>> v;

ll solve(ll idx, ll n, ll curr) {
    //cout << curr << " " << totMoney << "\n";
    if (idx >= n) return 0;
    ll &ret = dp[idx][curr];
    if (ret != -1) return ret;
    ll ans1 = 0;
    //cout << v[idx].F + curr << " ck\n";
    if ((v[idx].F + curr) <= totMoney) 
        ans1 = v[idx].S + solve(idx + 1, n, curr + v[idx].F);
    else if ((curr + v[idx].F) > 2000 and (v[idx].F + curr) <= (totMoney + 200)) 
        ans1 = v[idx].S + solve(idx + 1, n, curr + v[idx].F);
    ll ans2 = solve(idx + 1, n, curr);
    return ret = max(ans1, ans2);
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll n;
        while (cin >> totMoney >> n) {
            v.clear();
            v.resize(n);
            for (ll i = 0; i < n; i++) {
                cin >> v[i].F >> v[i].S;
            }
            sort(all(v));
            memset(dp, -1, sizeof(dp));
            ll res = solve(0, n, 0);
            cout << res << "\n";
        }
    }
    return 0;
}





