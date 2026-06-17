class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        
        // Extract (min, second_min) for each device
        // If device has only 1 unit, second_min = 0 (becomes empty if used as source)
        vector<array<int, 2>> dev(m);
        for (int i = 0; i < m; i++) {
            sort(units[i].begin(), units[i].end());
            dev[i] = {units[i][0], units[i].size() > 1 ? units[i][1] : 0};
        }
        
        // Base sum of all device ratings
        long long base = 0;
        for (auto& d : dev) base += d[0];
        
        // Sort devices by their minimum (ascending)
        sort(dev.begin(), dev.end());
        
        // pg[i] = gain if device i is a source (removes its min, rating becomes second_min)
        // Note: pg[i] can be negative (device becomes empty or second < first impossible since sorted)
        // Since units sorted: second_min >= min, so pg[i] >= 0 always... except single-unit case (second=0)
        long long total = 0;
        vector<long long> pg(m);
        for (int i = 0; i < m; i++) {
            pg[i] = (long long)dev[i][1] - dev[i][0]; // can be negative for single-unit devices
            total += pg[i];
        }
        
        // Option A: device[0] is the dump (receives all garbage)
        // device[0]'s rating unchanged (its min <= all others)
        // All other devices can freely be sources — but only if pg[i] >= 0 (worthwhile)
        // Gain = sum of max(0, pg[i]) for i in [1, m-1]
        long long gainA = 0;
        for (int i = 1; i < m; i++) gainA += max(0LL, pg[i]);
        long long ans = base + gainA;
        
        // Option B: device[0] is also a source (pg[0] may or may not be positive)
        // Its min goes to secondary dump d (d >= 1)
        // device[d] new rating = dev[0][0]
        // Net gain = pg[0] + sum_{i!=0, i!=d} max(0, pg[i]) - (dev[d][0] - dev[0][0])
        // = pg[0] + gainA - max(0, pg[d]) - (dev[d][0] - dev[0][0])
        // = pg[0] + gainA - max(0, pg[d]) - dev[d][0] + dev[0][0]
        // max(0, pg[d]) + dev[d][0] = max(dev[d][0], dev[d][1])
        //   if dev[d][1] >= 0 (multi-unit): = dev[d][1]
        //   if dev[d][1] == 0 (single-unit): = dev[d][0]
        // So minimize max(dev[d][0], dev[d][1]) over d in [1, m-1]
        if (m > 1) {
            int minCost = INT_MAX;
            for (int d = 1; d < m; d++)
                minCost = min(minCost, max(dev[d][0], dev[d][1]));
            long long optB = (long long)pg[0] + gainA - minCost + dev[0][0];
            ans = max(ans, base + optB);
        }
        
        return ans;
    }
};