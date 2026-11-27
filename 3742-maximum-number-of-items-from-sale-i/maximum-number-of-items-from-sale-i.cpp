
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> weight(n);

        // Calculate total contribution of each item
        for (int i = 0; i < n; i++) {
            int freeItems = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeItems++;
                }
            }

            weight[i] = 1 + freeItems;
        }

        // Group items by price
        vector<vector<int>> groups(1501);

        for (int i = 0; i < n; i++) {
            groups[items[i][1]].push_back(weight[i]);
        }

        const int NEG = -1000000000;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        // Process each possible minimum price
        for (int p = 1500; p >= 1; p--) {
            if (groups[p].empty()) continue;

            vector<int> has(budget + 1, NEG);

            // At least one item of price p must be selected
            for (int w : groups[p]) {
                for (int c = budget; c >= p; c--) {

                    if (dp[c - p] != NEG) {
                        has[c] = max(has[c], dp[c - p] + w);
                    }

                    if (has[c - p] != NEG) {
                        has[c] = max(has[c], has[c - p] + w);
                    }
                }
            }

            // Spend remaining budget on cheapest selected item
            for (int c = 0; c <= budget; c++) {
                if (has[c] == NEG) continue;

                int extra = (budget - c) / p;
                ans = max(ans, has[c] + extra);
            }

            // Add current price group to normal DP
            for (int w : groups[p]) {
                for (int c = budget; c >= p; c--) {
                    if (dp[c - p] != NEG) {
                        dp[c] = max(dp[c], dp[c - p] + w);
                    }
                }
            }
        }

        return ans;
    }
};
