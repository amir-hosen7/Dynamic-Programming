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

class Solution{
public:
	vector<int>calc(vector<int>&v){
        int sz=v.size();
        stack<pair<int,int>>st;
        st.push({-1,0});
        vector<int>expand(sz);
        for(int i=0; i<sz; i++){
            while(st.size()>0){
                pair<int,int>curr=st.top();
                if(v[i]>=curr.first){
                    st.push({v[i],i+1});
                    break;
                }
                else{
                    st.pop();
                    int idx=curr.second-1;
                    expand[idx]=i-idx;
                }
            }
        }
        //cout<<st.size()<<"\n";
        while(st.size()>1){
            pair<int,int>curr=st.top();
            st.pop();
            int idx=curr.second-1;
            //cout<<idx<<" aman\n";
            expand[idx]=sz-idx;
        }
        return expand;
    }

    int solve(vector<int>&A){
        int len=A.size();
        vector<int>left,right;
        left=calc(A);
        reverse(A.begin(),A.end());
        right=calc(A);
        reverse(right.begin(),right.end());
        reverse(A.begin(),A.end());
        int ans=0;
        for(int i=0; i<len; i++){
            ans=max(ans,A[i]*(left[i]+right[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>&matrix){
        int res=0,row=matrix.size();
        int col=matrix[0].size();
        vector<int>dp(col,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int a=matrix[i][j]-'0';
                if(a==1){
                    dp[j]++;
                }
                else{
                    dp[j]=0;
                }
            }
            res=max(res,solve(dp));
        }
        return res;
    }
};


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll row,col;
		cin>>row>>col;
		vector<vector<char>>mat;
		mat.resize(row);
		for(ll i=0; i<row; i++){
			mat[i].resize(col);
			for(ll j=0; j<col; j++){
				cin>>mat[i][j];
			}
		}
		Solution obj;
		ll res=obj.maximalRectangle(mat);
		cout<<res<<"\n";
	}
	return 0;
}

