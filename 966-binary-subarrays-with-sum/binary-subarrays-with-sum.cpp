class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return atMost(nums, goal) - atMost(nums, goal - 1);
    }
       
        int atMost(vector<int>& nums, int goal) {
        int left=0;int right=0;int maxnum = 0;
        int sum=0;
        int count=0;

        if(goal<0)return 0;
            while (right < nums.size()) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1); 
            right++;
        }
        return count;
    }
};