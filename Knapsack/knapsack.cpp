#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18;
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
const ll N=2e6+50;
const ll mod=1e9+7;

ll cap,w,n;
vector<ll>D,G;
ll dp[1010][50];

ll solve(ll idx,ll curr,ll gold){
	if(idx==n){
		return gold;
	}
	if(dp[idx][curr]!=-1){return dp[idx][curr];}
	ll a=0,wt=curr+(D[idx]*w)+(D[idx]*w*2);
	if(wt<=cap){
		a=solve(idx+1,wt,gold+G[idx]);
	}
	ll b=solve(idx+1,curr,gold);
	return dp[idx][curr]=max(a,b);
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	
	while(cin>>cap>>w){
		memset(dp,-1,sizeof(dp));
		cin>>n;
		D.resize(n);
		G.resize(n);
		for(ll i=0; i<n; i++){
			cin>>D[i]>>G[i];
		}
		ll res=solve(0,0,0);
		cout<<res<<"\n";
		
	}
	return 0;
}



