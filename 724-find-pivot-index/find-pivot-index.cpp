class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        long long total = 0;

        // Calculate total sum
        for (int num : nums) {
            total += num;
        }

        long long leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long rightSum = total - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            // Add current element to left
            // before moving to next index
            leftSum += nums[i];
        }

        return -1;
    }
};