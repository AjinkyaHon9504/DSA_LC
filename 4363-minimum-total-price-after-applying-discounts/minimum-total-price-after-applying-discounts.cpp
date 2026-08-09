class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double ans = 0;

        int i = 0;

        // Apply discounts greedily
        while (i < prices.size()) {

            if (i < discounts.size()) {
                ans += prices[i] * (100.0 - discounts[i]) / 100.0;
            }
            else {
                ans += prices[i];
            }

            i++;
        }

        return ans;
    }
};