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

ll n,sum,res;
ll dp[110][200000];
vector<ll>v;

ll solve(ll idx,ll curr){
	if(idx==n){
		return abs((sum-curr)-curr);
	}
	if(dp[idx][curr]!=-1){return dp[idx][curr];}
	return dp[idx][curr]=min(solve(idx+1,curr+v[idx]), solve(idx+1,curr));
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		memset(dp,-1,sizeof(dp));
		cin>>n;
		v.resize(n); sum=0;
		for(ll i=0; i<n; i++){
			cin>>v[i];
			sum+=v[i];
		}
		cout<<solve(0,0)<<"\n";
	}
	return 0;
}



