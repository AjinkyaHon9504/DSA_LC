class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end());

        // Step 2: Start with the first interval
        result.push_back(intervals[0]);

        // Step 3: Merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Compare with the last interval in result
            if (intervals[i][0] <= result.back()[1]) {
                // Overlap → merge
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // No overlap → push new interval
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};