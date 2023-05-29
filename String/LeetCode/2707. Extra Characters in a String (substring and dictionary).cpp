class Solution {
public:
    int dp[55];
    unordered_map<string, bool> mark;
    int solve(int idx, int n, string& s) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int res = 1 + solve(idx + 1, n, s);     //skip this char
        for (int i = 1; (idx + i) <= n; i++) {
            string t = s.substr(idx, i);
            if (mark[t]) res = min(res, solve(idx + i, n, s));
        }
        return dp[idx] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for (auto i : dictionary) mark[i] = 1;
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size(), s);
    }
};

