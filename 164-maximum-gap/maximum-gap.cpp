class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx) return 0;

        int bucketSize = (mx - mn + n - 2) / (n - 1);

        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        // Put every number into its bucket
        for (int x : nums) {
            int idx = (x - mn) / bucketSize;

            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
        }

        int ans = 0;
        int prevMax = mn;

        // Check gaps between consecutive non-empty buckets
        for (int i = 0; i < bucketCount; i++) {

            if (bucketMin[i] == INT_MAX)
                continue;

            ans = max(ans, bucketMin[i] - prevMax);

            prevMax = bucketMax[i];
        }

        return ans;
    }
};