class Solution {
public:

    bool subsetsum(vector<int> &nums,int sum){
        int n = nums.size();

        vector<vector<bool>> dp(n+1,
                                vector<bool>(sum+1,false));

        // Base case
        for(int i=0;i<=n;i++)
            dp[i][0]=true;

        // Fill DP table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){

                if(nums[i-1] <= j){
                    dp[i][j] =
                        dp[i-1][j-nums[i-1]]
                        || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x: nums)
            sum += x;

        if(sum % 2 != 0)
            return false;

        return subsetsum(nums, sum/2);
    }
};