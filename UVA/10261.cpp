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
unordered_map<ll, bool> mark;
ll dp[210][10010], path[210][10010];

ll solve(ll idx, ll n, ll curr, ll tot) {
    if (idx >= n) return curr;
    ll &ret = dp[idx][curr];
    if (ret != -1) return ret;
    ll ans1 = 0;
    if ((curr + v[idx]) <= tot) ans1 = solve(idx + 1, n, curr + v[idx], tot);
    ll ans2 = solve(idx + 1, n, curr, tot);
    ret = ans2;
    path[idx][curr] = 0;
    if (ans1 > ans2) {
        ret = ans1;
        path[idx][curr] = 1;
    }
    return ret;
}

void get_path(ll idx, ll n, ll curr) {
    if (idx >= n or path[idx][curr] == -1) return;
    if (path[idx][curr] == 1) {
        mark[idx] = 1;
        get_path(idx + 1, n, curr + v[idx]);
    }
    else get_path(idx + 1, n, curr);
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        ll ferrySize;
        cin >> ferrySize;
        ferrySize *= 100;
        v.clear();
        mark.clear();
        ll a;
        while (1) {
            cin >> a;
            if (!a) break;
            v.pb(a);
        }
        ll n = v.size();
        vector<ll> cum(n + 5);
        cum[0] = 0;
        ll idx;
        for (ll i = 1; i <= n; i++) {
            cum[i] = cum[i - 1] + v[i - 1];
            if (cum[i] <= ferrySize*2) {
                idx = i;
            }
        }
        while (idx) {
            memset(dp, -1, sizeof(dp));
            memset(path, -1, sizeof(path));
            ll curr = solve(0, idx, 0, ferrySize);
            if ((cum[idx] - curr) <= ferrySize) {
                get_path(0, idx, 0);
                break;
            }
            idx--;
        }
        cout << idx << "\n";
        for (ll i = 0; i < idx; i++) {
            if (mark[i]) cout << "port\n";
            else cout << "starboard\n";
        }
        if (T != t) cout << "\n";
    }
    return 0;
}





