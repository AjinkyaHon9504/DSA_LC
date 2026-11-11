
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Option 1: Buy everything separately
        long long separate = 1LL * need1 * cost1
                           + 1LL * need2 * cost2;

        int mn = min(need1, need2);
        int mx = max(need1, need2);

        // Option 2: Buy common items for the smaller requirement
        long long mixed = 1LL * mn * costBoth
                        + 1LL * (need1 - mn) * cost1
                        + 1LL * (need2 - mn) * cost2;

        // Option 3: Buy only common items
        long long allBoth = 1LL * mx * costBoth;

        return min({separate, mixed, allBoth});
    }
};
