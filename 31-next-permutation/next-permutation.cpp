class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find pivot
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // No pivot -> already the largest permutation
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find smallest element greater than nums[i]
        // Since suffix is decreasing, first from right works
        int j = n - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }

        // Step 3: Swap
        swap(nums[i], nums[j]);

        // Step 4: Make suffix smallest
        reverse(nums.begin() + i + 1, nums.end());
    }
};