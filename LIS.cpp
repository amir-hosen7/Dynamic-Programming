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

ll dp[100],next_idx[100];

ll lis(ll idx, vector<ll>&A, ll n){
	if(dp[idx]!=-1){
		return dp[idx];
	}
	ll ans=0;
	for(ll j=idx+1; j<n; j++){
		if(A[j]>A[idx]){
			ll subAns=lis(j,A,n);
			if(subAns>ans){
				ans=subAns;
				next_idx[idx]=j;
			}
		}
	}
	return dp[idx]=ans+1;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n;
		cin>>n;
		vector<ll>A(n);
		for(ll i=0; i<n; i++){
			cin>>A[i];
		}
		memset(dp,-1,sizeof(dp));
		memset(next_idx,-1,sizeof(next_idx));
		ll ans=0,start_idx;
		for(ll i=0; i<n; i++){
			ll subAns=lis(i,A,n);
			if(subAns>ans){
				ans=subAns;
				start_idx=i;
			}
		}
		cout<<ans<<"\n";
		vector<ll>path;
		while(start_idx!=-1){
			path.pb(A[start_idx]);
			start_idx=next_idx[start_idx];
		}
		cout<<"Path: ";
		for(auto i:path){
			cout<<i<<" ";
		}cout<<"\n";
	}
	return 0;
}



