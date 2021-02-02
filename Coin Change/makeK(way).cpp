
//Make k how many way

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
const int N=1e6;

void solve(ll t){
	ll n; cin>>n;
	vector<ll>v(n);
	for(ll i=0; i<n; i++){
		cin>>v[i];
	}
	ll k; cin>>k;
	vector<ll>dp(k+5,0);
	dp[0]=1;
	for(ll j=0; j<n; j++){
		for(ll i=0; i<=k; i++){
			if(i>=v[j]){				
				dp[i] += dp[i-v[j]];
			}
		}
	}
	cout<<dp[k]<<"\n";
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	//pre_calc();

	ll t=1;
	for(ll T=1; T<=t; T++){
		solve(T);
	}
	return 0;
}

