class Solution {
public:
    int dp[110][110];
    vector<pair<int, int>> adj[110];
    long long solve(int src, int dst, int cnt, int k) {
        if (src == dst or (cnt - 1) >= k) {
            if ((cnt - 1) > k or src != dst) return INT_MAX;
            return 0;
        } 
        int &ret = dp[src][cnt];
        if (ret != -1) return ret;
        long long siz = adj[src].size(), ans = INT_MAX;
        for (int i = 0; i < siz; i++) {
            int v = adj[src][i].first, c = adj[src][i].second;
            ans = min(ans, c + solve(v, dst, cnt + 1, k));
        }
        return ret = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int siz = flights.size();
        for (int i = 0; i < siz; i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        for (int i = 0; i <= n + 5; i++) {
            for (int j = 0; j <= k + 5; j++) {
                dp[i][j] = -1;
            }
        }
        int res = solve(src, dst, 0, k);
        if (res >= INT_MAX) res = -1;
        return res;
    }
};
