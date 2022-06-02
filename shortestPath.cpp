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

ll cost[100][100],dp[100];

ll shortestPath(ll u, ll n){
	if(u==n){
		return 0;
	}
	if(dp[u]!=-1){
		return dp[u];
	}
	ll ans=inf;
	for(ll v=1; v<=n; v++){
		if(cost[u][v]!=-1){
			ans=min(ans,shortestPath(v,n)+cost[u][v]);
		}
	}
	return dp[u]=ans;
}

//Shortest path for DAG

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll node,edge;
		cin>>node>>edge;
		ll u,v,w;
		memset(dp,-1,sizeof(dp));
		memset(cost,-1,sizeof(cost));	
		for(ll i=0; i<edge; i++){
			cin>>u>>v>>w;
			cost[u][v]=w;
		}
		ll ans=shortestPath(1,node);
		cout<<ans<<"\n";
	}
	return 0;
}



