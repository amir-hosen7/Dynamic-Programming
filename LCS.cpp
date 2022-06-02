#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
//typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pbds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>pbds; 

//------------------------------------------------------------------------------//


const ll P=29;
const ll N=2e6+50;
const ll mod=1e9+7;

ll dp[100][100];

ll lcs(ll i, ll j, string &s, string &w){
	if(i==s.size() or j==w.size()){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll ans=0;
	if(s[i]==w[j]){
		ans=1+lcs(i+1,j+1,s,w);
	}
	else{
		ans=max(lcs(i+1,j,s,w), lcs(i,j+1,s,w));
	}
	return dp[i][j]=ans;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		string s,w;
		cin>>s>>w;
		memset(dp,-1,sizeof(dp));
		ll ans=lcs(0,0,s,w);
		cout<<ans<<"\n";
	}
	return 0;
}



