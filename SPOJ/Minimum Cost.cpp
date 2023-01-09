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

ll dp[1010][1010];

ll solve(ll i, ll j, string &s, string &w){
    if(i == s.size()){
        if(j != w.size()){
            return (w.size()-j) * 30;
        }
        return 0;
    }
    if(j == w.size()){
        if(i != s.size()){
            return (s.size() - i) * 15;
        }
        return 0;
    }
    ll &ret = dp[i][j];
    if (ret != -1) return ret;
    ll ans;
    if (s[i] == w[j]) {
        ans = solve(i + 1, j + 1, s, w);
    }
    else {
        ll ans1 = 15 + solve(i + 1, j, s, w);
        ll ans2 = 30 + solve(i, j + 1, s, w);
        ll ans3 = 45 + solve(i + 1, j + 1, s, w);
        ans = min(ans1, min(ans2, ans3));
    }
    return ret = ans;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        string a, b;
        while (cin >> a) {
            if (a == "#") break;
            cin >> b;
            ll al = a.size(), bl = b.size();
            for (ll i = 0; i <= al; i++) {
                for (ll j = 0; j <= bl; j++) {
                    dp[i][j] = -1;
                }
            }
            ll res = solve(0, 0, a, b);
            cout << res << "\n";
        }
    }
    return 0;
}





