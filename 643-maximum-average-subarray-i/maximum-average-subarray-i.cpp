class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double windowsum=0;
        for(int i =0;i<k;i++){
            windowsum += nums[i];
        }

        double maxsum = windowsum;

        for(int i=k;i<n;i++){
            windowsum +=nums[i];
            windowsum -=nums[i-k];
            maxsum = max(windowsum,maxsum);
        }

        return maxsum/k;
    }
};