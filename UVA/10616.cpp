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

ll dp[210][25][15];

ll solve(ll idx, ll n, vector<ll> &v, ll d, ll m, ll curr, ll cnt) {
    if (idx >= n or cnt == m) {
        if (curr % d == 0 and cnt == m) return 1;
        else return 0;
    }
    ll &ret = dp[idx][curr][cnt];
    if (ret != -1) return ret;
    ll ans1 = solve(idx + 1, n, v, d, m, (curr + v[idx]) % d, cnt + 1);
    ll ans2 = solve(idx + 1, n, v, d, m, curr, cnt);
    return ret = ans1 + ans2;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll n, q, cas = 1;
        while (cin >> n >> q) {
            if ((n + q) == 0) {
                break;
            }
            vector<ll> v(n);
            for (ll i = 0; i < n; i++) {
                cin >> v[i];
            }
            cout << "SET " << cas++ << ":\n";
            for (ll tt = 1; tt <= q; tt++) {
                ll d, m;
                cin >> d >> m;
                vector<ll> A(n);
                for (ll i = 0; i < n; i++) {
                    A[i] = abs(v[i]) / d;
                    A[i] = (v[i] + ((A[i] + 1) * d)) % mod;
                }
                memset(dp, -1, sizeof(dp));
                ll res = solve(0, n, A, d, m, 0, 0);
                cout << "QUERY "<< tt << ": " << res << "\n";
            }
        }
    }
    return 0;
}





