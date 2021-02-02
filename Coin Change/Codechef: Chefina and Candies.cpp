#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef tree < ll, null_type, less < ll >, 
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define miOne cout<<"-1\n";
#define zero cout<<"0\n";
#define rep(i,a,b) for(ll i=a; i<b; i++) 
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
const int N=1e6;

void solve(ll t){
	ll n; cin>>n;
	vector<ll>v(n);
	ll sum=0;
	for(ll i=0; i<n; i++){
		cin>>v[i]; 
		sum+=v[i];
	}
	if(sum%2==1){
		cout<<"Not Impressed\n";
		return;
	}
	ll k=sum/2;
	vector<bool>dp(k+5,0);
	dp[0]=1;
	for(ll j=0; j<n; j++){
		for(ll i=0; i<=k; i++){
			if(dp[i]==1 and (i+v[j])<=k){
				dp[i+v[j]]=1;
			}
		}
	}
	if(dp[k]==1){
		cout<<"Impressed\n";
	}
	else{
		cout<<"Not Impressed\n";
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	//pre_calc();

	ll t=1; cin>>t;
	rep(T,1,t+1){
		solve(T);
	}
	return 0;
}

