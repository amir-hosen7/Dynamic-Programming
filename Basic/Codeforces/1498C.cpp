#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
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
const ll N=2e5+50;
const ll mod=1e9+7;

ll piller,power;
ll dp[1005][1005][2];

ll calc(ll state, ll health, ll position){
	if(health<=0){
		return 0;
	}
	if(position>=piller or position<0){
		return 1;
	}
	if(dp[health][position][state]!=-1){
		return dp[health][position][state];
	}
	ll ans=0;
	if(state==0){
		ans+=calc(state,health,position+1);
		ans%=mod;
		ans+=calc(state^1,health-1,position-1);
		ans%=mod;
	}
	else{
		ans+=calc(state,health,position-1);
		ans%=mod;
		ans+=calc(state^1,health-1,position+1);
		ans%=mod;
	}
	return dp[health][position][state]=ans;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		cin>>piller>>power;
		for(ll i=0; i<=power; i++){
			for(ll j=0; j<=piller; j++){
				dp[i][j][0]=-1;
				dp[i][j][1]=-1;
			}
		}
		ll res=calc(0,power,0);
		cout<<res<<"\n";
	}
	return 0;
}

