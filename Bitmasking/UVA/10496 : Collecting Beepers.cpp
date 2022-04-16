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

ll n,W[12][12],dp[12][1<<12];

bool isOn(ll x, ll pos){
	return (bool)(x&(1<<pos));
}

ll turnOn(ll x, ll pos){
	return (x|(1<<pos));
}

ll travel(ll idx, ll mask){
	if(mask==((1<<n)-1)){return W[idx][0];}
	if(dp[idx][mask]!=-1){return dp[idx][mask];}
	ll ans=inf;
	for(ll i=0; i<n; i++){
		if(isOn(mask,i)==false){
			ll res=travel(i,turnOn(mask,i))+W[idx][i];
			ans=min(res,ans);
		}
	}
	return dp[idx][mask]=ans;
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll L,R; cin>>L>>R;
		ll x,y; cin>>x>>y;
		cin>>n;
		vector<pair<ll,ll>>point;
		point.pb({x,y});
		for(ll i=0; i<n; i++){
			cin>>x>>y;
			point.pb({x,y});
		}
		n=point.size();
		for(ll i=0; i<n; i++){
			for(ll j=0; j<n; j++){
				W[i][j]=abs(point[i].F-point[j].F)+abs(point[i].S-point[j].S);
			}
		}
		memset(dp,-1,sizeof(dp));
		ll ans=travel(0,1);
		cout<<"The shortest path has length "<<ans<<"\n";
	}
	return 0;
}



