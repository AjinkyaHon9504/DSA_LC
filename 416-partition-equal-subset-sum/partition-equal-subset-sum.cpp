class Solution {
public:


    bool subsetsum(vector<int>&nums,int target){
        int n=nums.size();

        bool dp[n+1][target+1];
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        for(int j=1;j<=target;j++){
            dp[0][j] = false;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];

        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        int target = sum/2;
        if(sum%2!=0){
            return false;
        }
        return subsetsum(nums,target);
        

        }
        
        
    
};