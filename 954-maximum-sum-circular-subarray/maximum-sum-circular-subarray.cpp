class Solution {
public:
    int kadanemin(vector<int>& nums,int n){
        int sum = nums[0];
        int minsum = nums[0];
        for(int i=1;i<n;i++){
            sum = min(sum+nums[i],nums[i]);
            minsum = min(minsum,sum);
        }
        return minsum;
    }
    int kadanemax(vector<int>& nums,int n){
        int sum = nums[0];
        int maxsum = nums[0];
        for(int i=1;i<n;i++){
            sum = max(sum+nums[i],nums[i]);
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums),end(nums),0);
        int minsum = kadanemin(nums,n);
        int maxsum = kadanemax(nums,n);
        int circsum = sum - minsum;
        if(maxsum>0){
            return max(maxsum,circsum);
        }
        return maxsum;
    }
};