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

ll house,W[12][12],dp[12][1<<12];

bool isOn(ll x, ll pos){
	return (bool)(x&(1<<pos));
}

ll turnOn(ll x, ll pos){
	return x|(1<<pos);
}

ll travel(ll idx, ll mask){
	if(mask==(1<<house)-1){
		return W[idx][0];
	}
	if(dp[idx][mask]!=-1){
		return dp[idx][mask];
	}
	ll ans=inf;
	for(ll i=0; i<house; i++){
		if(W[idx][i]==-1){continue;}
		if(isOn(mask,i)==false){
			ll res=travel(i,turnOn(mask,i))+W[idx][i];
			ans=min(ans,res);
		}
	}
	return dp[idx][mask]=ans;
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll road;
		cin>>house>>road;
		ll u,v,dis;
		memset(W,-1,sizeof(W));
		memset(dp,-1,sizeof(dp));
		for(ll i=0; i<road; i++){
			cin>>u>>v>>dis;
			W[u][v]=dis;
		}
		ll min_dis=travel(0,1);
		cout<<min_dis<<"\n";
	}
	return 0;
}



