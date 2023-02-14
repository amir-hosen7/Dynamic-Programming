public class Solution {
    static int[] dp = new int[10010];
    private int solve(int idx, int n, int[] nums) {
        if (idx == (n - 1)) return 0;
        if (dp[idx] != -1) return dp[idx];
        int res = (int)1e5;
        for (int i = 1; (i + idx) < n && i <= nums[idx]; i++) {
            res = Math.Min(res, 1 + solve(idx + i, n, nums));
        }
        return dp[idx] = res;
    }
    public int Jump(int[] nums) {
        int n = nums.Length;
        for (int i = 0; i < 10010; i++) {
            dp[i] = -1;
        }
        return solve(0, n, nums);
    }
}

