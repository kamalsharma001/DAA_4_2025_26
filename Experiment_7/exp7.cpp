class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmpPrices = prices;
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                
                if (prices[u] != INT_MAX) {
                    if (prices[u] + w < tmpPrices[v]) {
                        tmpPrices[v] = prices[u] + w;
                    }
                }
            }
            prices = tmpPrices;
        }

        return (prices[dst] == INT_MAX) ? -1 : prices[dst];
    }
};

/*
 * Time Complexity: O(k * E)
 * - We run the outer loop k + 1 times.
 * - Inside, we iterate through all E (number of flights) edges.
 * * Space Complexity: O(n)
 * - We store two vectors (prices and tmpPrices) of size n (number of cities).
 */
