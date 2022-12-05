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

ll n, path[10][1 << 10];
vector<ll> final_path;
vector<pair<ll, ll>> v;
double dp[10][1 << 10], dis[10][10];

double solve(ll idx, ll mask) {
    if (mask == (1 << n) - 1) return 0;
    double &ret = dp[idx][mask];
    if (ret != -1) return ret;
    double ans = inf;
    for (ll i = 0; i < n; i++) {
        bool ok = mask & (1 << i);
        if (ok == false) {
             double curr = solve(i, mask | (1 << i)) + dis[idx][i];
             if (curr < ans) {
                ans = curr;
                path[idx][mask] = i;
             } 
        }
    }
    return ret = ans;
}

void print_path(ll idx, ll mask) {
    if (mask == (1 << n) - 1) return;
    if (path[idx][mask] != -1) {
        ll i = path[idx][mask];
        final_path.pb(i);
        print_path(i, mask | (1 << i));
    }
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll cas = 1;
        while (cin >> n) {
            if (n == 0) break;
            v.clear();
            v.resize(n);
            final_path.clear();
            for (ll i = 0; i < n; i++) {
                cin >> v[i].F >> v[i].S;
            }
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    double a = v[i].F - v[j].F;
                    double b = v[i].S - v[j].S;
                    dis[i][j] = sqrt((a*a) + (b*b)) + 16;
                }
            }
            for (ll i = 0; i < 10; i++) {
                for (ll j = 0; j < (1 << 10); j++) {
                    dp[i][j] = path[i][j] = -1;
                }
            }
            ll idx;
            double res = inf;
            for (ll i = 0; i < n; i++) {
                double curr = solve(i, 1 << i);
                if (curr < res) {
                    idx = i, res = curr;
                }
            }
            final_path.pb(idx);
            print_path(idx, 1 << idx);
            cout << "**********************************************************\n";
            cout << "Network #"<< cas++ << "\n";
            ll siz = final_path.size();
            for (ll i = 0; i < (siz - 1); i++) {
                ll id = final_path[i], id2 = final_path[i + 1];
                cout << "Cable requirement to connect (" << v[id].F << "," << v[id].S <<") to (" << v[id2].F << "," << v[id2].S << ") is " << fixed << setprecision(2) << dis[id][id2] << " feet.\n";
            }
            cout << "Number of feet of cable required is " << fixed << setprecision(2) << res << ".\n";
        }
    }
    return 0;
}





