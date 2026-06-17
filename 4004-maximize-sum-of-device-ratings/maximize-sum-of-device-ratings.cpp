class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();

        vector<array<long long, 2>> dev;

        for (auto &row : units) {
            sort(row.begin(), row.end());

            long long mn = row[0];
            long long smn = (row.size() > 1 ? row[1] : 0);

            dev.push_back({mn, smn});
        }

        long long base = 0;

        for (auto &d : dev) {
            base += d[0];
        }

        sort(dev.begin(), dev.end()); // sort by minimum

        vector<long long> profit(m);
        long long gainA = 0;

        for (int i = 0; i < m; i++) {
            profit[i] = dev[i][1] - dev[i][0];
        }

        for (int i = 1; i < m; i++) {
            gainA += max(0LL, profit[i]);
        }

        long long ans = base + gainA;

        if (m > 1) {
            long long minCost = LLONG_MAX;

            for (int d = 1; d < m; d++) {
                minCost = min(minCost,
                              max(dev[d][0], dev[d][1]));
            }

            long long gainB =
                profit[0] +
                gainA -
                minCost +
                dev[0][0];

            ans = max(ans, base + gainB);
        }

        return ans;
    }
};