class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atMostK(nums,k) - atMostK( nums,k-1);
    }


    int atMostK(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int left = 0, res = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (freq[nums[right]] == 0) {
            k--; 
        }
        freq[nums[right]]++;

        // Shrink window if distinct > k
        while (k < 0) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                k++;
            }
            left++;
        }

        res += (right - left + 1);  // count of valid subarrays ending at right
    }
    return res;

    }       
};