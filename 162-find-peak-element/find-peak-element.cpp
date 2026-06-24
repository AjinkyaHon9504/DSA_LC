class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        map<int,int> mp;

        if (nums[0] > nums[1]) {
            mp[nums[0]] = 0;
        }

        if (nums[n-1] > nums[n-2]) {
            mp[nums[n-1]] = n-1;
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                mp[nums[i]] = i;
            }
        }

        return mp.rbegin()->second;
    }
};