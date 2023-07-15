class Solution {
public:
    int dp[1010][1010];
    int solve(int i, int j, string &s) {
        if (i >= j) {
            if (i == j) return 1;
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int ans;
        if (s[i] == s[j]) {
            ans = 2 + solve(i + 1, j - 1, s);
        }
        else {
            int ans1 = solve(i + 1, j, s);
            int ans2 = solve(i, j - 1, s);
            ans = max(ans1, ans2);
        }
        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size() - 1, s);
    }
};
