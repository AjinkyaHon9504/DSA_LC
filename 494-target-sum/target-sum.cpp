class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        if(abs(target)>totalsum || (target + totalsum)%2 !=0){
            return 0;
        }

        int Psum = (target+totalsum)/2;

        vector<vector<int>> dp(n+1,vector<int>(Psum+1,0));
        dp[0][0]=1;

        

        for(int i=1;i<=n;i++){
            for(int j=0;j<=Psum;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }

        }
        return dp[n][Psum];
    }
};