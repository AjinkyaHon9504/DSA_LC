class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left;int right;int maxLen = 0;
        int zeroCount = 0;

          while (right < nums.size()) {
            // Count zero if found
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++; // shrink window
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
         return maxLen;
    }
};