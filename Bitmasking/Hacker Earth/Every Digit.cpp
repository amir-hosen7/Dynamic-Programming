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

//---------------------------------------------------------------------------//
//Timus: 314795JS

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//

const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

ll n;
vector<string>A(1010);
ll dp[1010][1025];

ll calc(string str){
	ll mask=0;
	for(auto ch:str){
		ll id=ch-'0';
		mask|=(1<<id);
	}
	return mask;
}

ll solve(ll idx, ll mask){
	//cout<<idx<<" "<<mask<<"\n";
	if(idx>=n){
		return (mask==1023)?1:0;
	}
	//if(mask==1023){return 1;}
	if(dp[idx][mask]!=-1){
		return dp[idx][mask];
	}
	ll ans=0,curr_mask=calc(A[idx]);
	ans=(ans+solve(idx+1,mask|curr_mask))%mod;
	ans=(ans+solve(idx+1,mask))%mod;
	return dp[idx][mask]=ans;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		memset(dp,-1,sizeof(dp));
		cin>>n;
		for(ll i=0; i<n; i++){
			cin>>A[i];
		}
		ll res=solve(0,0);	
		cout<<res<<"\n";	
	}
	return 0;
}

