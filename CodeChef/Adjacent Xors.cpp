#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P=29;
const ll N=2e5+50;
const ll mod=1e9+7;

ll dp[N][2];

ll solve(ll idx, ll n, ll x, ll status, vector<ll>& v){
	if(idx>=n) return 0;
	if(dp[idx][status]!=-1) return dp[idx][status];
	ll ans;
	if(status){
		ll ans1=((v[idx-1]+x)^v[idx])+solve(idx+1, n, x, 0, v);
		ll ans2=((v[idx-1]+x)^(v[idx]+x))+solve(idx+1, n, x, 1, v);
		ans=max(ans1, ans2);
	}
	else{
		ll ans1=(v[idx-1]^v[idx])+solve(idx+1, n, x, 0, v);
		ll ans2=(v[idx-1]^(v[idx]+x))+solve(idx+1, n, x, 1, v);
		ans=max(ans1, ans2);
	}
	return dp[idx][status]=ans;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	cin>>t;
	for(ll T=1; T<=t; T++){
		ll n, x;
		cin>>n>>x;
		vector<ll>v(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		for(ll i=0; i<=n; i++){
			dp[i][0]=dp[i][1]=-1;
		}
		cout<<max(solve(1, n, x, 0, v), solve(1, n, x, 1, v))<<"\n";
	}
	return 0;
}




