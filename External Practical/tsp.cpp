class Solution {
public:
    int solve(int mask, int curr, int n, vector<vector<int>>& cost, vector<vector<int>>& memo) {
        if (mask == (1 << n) - 1) {
            return cost[curr][0];
        }

        if (memo[mask][curr] != -1) {
            return memo[mask][curr];
        }

        int min_cost = 1e9;

        for (int next_city = 0; next_city < n; next_city++) {
            if (!(mask & (1 << next_city))) {
                int new_cost = cost[curr][next_city] + solve(mask | (1 << next_city), next_city, n, cost, memo);
                min_cost = min(min_cost, new_cost);
            }
        }

        return memo[mask][curr] = min_cost;
    }

    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        vector<vector<int>> memo(1 << n, vector<int>(n, -1));
        return solve(1, 0, n, cost, memo);
    }
};
