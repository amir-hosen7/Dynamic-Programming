#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//


const ll p=29;
const ll N=3e5+50;
const ll mod=1e9+7;

bool vis[N];
ll depth[N], dp[N];
vector<ll>adj[N], G[N];

void dfs(ll root){
	vis[root]=1;
	for(ll i=0; i<adj[root].size(); i++){
		if(vis[adj[root][i]]==0){
			G[root].pb(adj[root][i]);
			dfs(adj[root][i]);
			depth[root]+=depth[adj[root][i]];
		}
	}
}

ll solve(ll root){
	if(G[root].size()==0){
		return 0;
	}
	if(dp[root]!=-1){
		return dp[root];
	}
	ll ans;
	if(G[root].size()>1){
		ll ans1=depth[G[root][0]]-1 + solve(G[root][1]);
		ll ans2=depth[G[root][1]]-1 + solve(G[root][0]);
		ans=max(ans1, ans2);
	}
	else{
		ans=depth[G[root][0]]-1;
	}
	return dp[root]=ans;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	cin>>t;
	for(ll T=1; T<=t; T++){
		ll n;
		cin>>n;
		ll u,v;
		for(ll i=0; i<=n; i++){
			depth[i]=1, vis[i]=0, dp[i]=-1;
			adj[i].clear(), G[i].clear();
		}
		for(ll i=0; i<(n-1); i++){
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		ll ans=solve(1);
		cout<<ans<<"\n";
	} 
	return 0;
}








