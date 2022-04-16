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

ll n,D,M;
ll dp[210][50][50];
vector<ll>v;

ll solve(ll idx,ll curr,ll cnt){
	if(idx==n){
		if(cnt==M){
			cnt=0; return (curr%D==0)?1:0;
		}
		return 0;
	}
	if(cnt==M){
		cnt=0; return (curr%D==0)?1:0;
	}
	if(dp[idx][curr][cnt]!=-1){return dp[idx][curr][cnt];}
	return dp[idx][curr][cnt]=solve(idx+1,(curr+v[idx])%D,cnt+1)+solve(idx+1,curr%D,cnt);
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll q,cas=1;
	while(cin>>n>>q){
		if((n+q)==0){break;}
		v.resize(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		cout<<"SET "<<cas++<<":\n";
		for(ll i=1; i<=q; i++){
			cin>>D>>M;
			memset(dp,-1,sizeof(dp));
			cout<<"QUERY "<<i<<": "<<solve(0,0,0)<<"\n";
		}
	}
	return 0;
}



