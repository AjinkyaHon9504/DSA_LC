
class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int ans = INT_MAX;

        // Case 1: Change two smallest
        ans = min(ans, nums[n-1] - nums[2]);

        // Case 2: Change smallest and largest
        ans = min(ans, nums[n-2] - nums[1]);

        // Case 3: Change two largest
        ans = min(ans, nums[n-3] - nums[0]);

        return ans;
    }
};
