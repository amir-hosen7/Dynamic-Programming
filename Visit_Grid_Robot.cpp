#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9+7;
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int32_t main(){
    fast();
    int row, col, p;
    cin>>row>>col>>p;
    int dp[row+1][col+1];
    memset(dp, 0, sizeof(dp));
    int x, y;
    for(int i=1; i<=p; i++){
        cin>>x>>y;
        dp[x][y] = -1;
    }
    if(dp[1][1] == -1){
        cout<<"0\n";
        return 0;
    }
    for(int i=1; i<=col; i++){
        if(dp[1][i] != -1) dp[1][i] = 1LL;
        else break;
    }
    for(int i=1; i<=row; i++){
        if(dp[i][1] != -1) dp[i][1] = 1LL;
        else break;
    }
    for(int i=2; i<=row; i++){
        for(int j=2; j<=col; j++){
            if(dp[i][j] == -1) continue;
            if(dp[i-1][j]>0) dp[i][j] = (dp[i][j]+dp[i-1][j]+mod)%mod;
            if(dp[i][j-1]>0) dp[i][j] = (dp[i][j]+dp[i][j-1]+mod)%mod;
        }
    }
    int a, b; cin>>a>>b; //1 based index
    if(dp[a][b]>0) cout<<dp[a][b]<<"\n";
    else cout<<"0\n";
    return 0;
}


