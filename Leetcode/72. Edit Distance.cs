public class Solution {
    static int[,] dp = new int[510, 510];
    int solve(int i, int j, int n, int m, string a, string b) {
        if (i >= n) {
            return b.Length - j;
        }
        if (j >= m) {
            return a.Length - i;
        }
        if (dp[i, j] != -1) {
            return dp[i, j];
        }
        int res;
        if (a[i] == b[j]) {
            res = solve(i + 1, j + 1, n, m, a, b);
        }
        else {
            int ans1 = 1 + solve(i + 1, j, n, m, a, b);
            int ans2 = 1 + solve(i, j + 1, n, m, a, b);
            int ans3 = 1 + solve(i + 1, j + 1, n, m, a, b);
            res = Math.Min(ans1, Math.Min(ans2, ans3));
        }
        return dp[i, j] = res;
    }

    public int MinDistance(string word1, string word2) {
        int n = word1.Length, m = word2.Length;
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 500; j++) {
                dp[i, j] = -1;
            }
        }
        return solve(0, 0, n, m, word1, word2);
    }
}

