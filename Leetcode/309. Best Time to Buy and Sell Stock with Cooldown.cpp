class Solution {
public:
    int dp[5010][2];
    int solve(int idx, int n, vector<int>& v, int status){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][status]!=-1){
            return dp[idx][status];
        }
        int profit;
        if(status){
            profit=max(v[idx]+solve(idx+2, n, v, 0), solve(idx+1, n, v, 1));
        }
        else{
            int profit1=solve(idx+1, n, v, 1)-v[idx];
            int profit2=solve(idx+1, n, v, 0);
            profit=max(profit1, profit2);
        }
        return dp[idx][status]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,n,prices,0);
    }
};

