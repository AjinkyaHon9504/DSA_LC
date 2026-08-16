class Solution {
public:

    int solve(vector<int>& nums,int i,int target,vector<vector<int>>&dp){
        
        if(i==nums.size()){
            return target == 0;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int notTake = solve(nums,i+1,target,dp);
        int take=0;
        if(nums[i]<=target){
            take+=solve(nums,i+1,target-nums[i],dp);
        }
        return dp[i][target]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        //2p = target + total
        if(abs(target)>total){
            return 0;
        }
        if((target + total)%2!=0){
            return 0;
        }
        int finaltarget = (target+total)/2;
        vector<vector<int>>dp(n,vector<int>(finaltarget+1,-1));
        return solve(nums,0,finaltarget,dp);
    }
};