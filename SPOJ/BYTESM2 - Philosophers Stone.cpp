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

ll row, col, dp[110][110], grid[110][110];

ll solve(ll x, ll y) {
    if (x >= row) return 0;
    if (y >= col or y < 0) return INT_MIN;
    ll &ret = dp[x][y];
    if (ret != -1) return ret;
    return ret = max(grid[x][y] + solve(x + 1, y), max(grid[x][y] + solve(x + 1, y + 1), grid[x][y] + solve(x + 1, y - 1)));
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        cin >> row >> col;
        for (ll i = 0; i < row; i++) {
            for (ll j = 0; j < col; j++) {
                dp[i][j] = -1;
                cin >> grid[i][j];
            }
        }
        ll res = 0;
        for (ll i = 0; i < col; i++) {
            res = max(res, solve(0, i));
        }
        cout << res << "\n";
    }
    return 0;
}





