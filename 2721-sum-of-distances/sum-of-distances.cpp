class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<long long> ans(n, 0);

        unordered_map<int, long long> count;
        unordered_map<int, long long> sum;

        // LEFT PASS
        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (count.count(val)) {
                ans[i] += count[val] * i - sum[val];
            }

            count[val]++;
            sum[val] += i;
        }

        // Reset maps
        count.clear();
        sum.clear();

        // RIGHT PASS
        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];

            if (count.count(val)) {
                ans[i] += sum[val] - count[val] * i;
            }

            count[val]++;
            sum[val] += i;
        }

        return ans;
    }
};