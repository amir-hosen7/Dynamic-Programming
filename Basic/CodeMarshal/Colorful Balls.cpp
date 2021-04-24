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

ll dp[100010][5];

//1=Red,2=Green,3=Blue

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		memset(dp,0,sizeof(dp));
		string str;
		cin>>str;
		vector<ll>A;
		ll len=str.size();
		for(ll i=0; i<len; i++){
			if(str[i]=='W'){
				if(i==0){
					for(ll j=1; j<=3; j++){
						dp[i+1][j]=1;
					}
				}
				else{
					if(str[i-1]=='W'){
						for(ll j=1; j<=3; j++){
							if(j==1){
								dp[i+1][j]=(dp[i][2]+dp[i][3])%mod;
							}
							else if(j==2){
								dp[i+1][j]=(dp[i][1]+dp[i][3])%mod;
							}
							else{
								dp[i+1][j]=(dp[i][1]+dp[i][2])%mod;
							}
						}
					}
					else{
						if(str[i-1]=='R'){
							dp[i+1][2]=1;
							dp[i+1][3]=1;
						}
						else if(str[i-1]=='G'){
							dp[i+1][1]=1;
							dp[i+1][3]=1;
						}
						else{
							dp[i+1][1]=1;
							dp[i+1][2]=1;
						}
					}
				}
			}
			else{
				ll tot=0;
				for(ll j=1; j<=3; j++){
					if(str[i]=='R' and j!=1){
						tot+=dp[i][j];
					}
					else if(str[i]=='G' and j!=2){
						tot+=dp[i][j];
					}
					else if(str[i]=='B' and j!=3){
						tot+=dp[i][j];
					}
				}
				A.pb(tot%mod);
			}
		}
		ll i=len;
		if(str[i-1]=='W'){
			ll tot=0;
			for(ll j=1; j<=3; j++){
				tot+=dp[i][j];
			}
			A.pb(tot%mod);
		}
		ll res=1;
		len=A.size();
		for(i=0; i<len; i++){
			if(A[i]>0){
				res=(res*A[i])%mod;
			}
		}
		cout<<"Case "<<T<<": "<<res<<"\n";
	}
	return 0;
}

