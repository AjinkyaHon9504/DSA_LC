class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int range = 0;

        for(int i = 0; i < n; i++){
            range += nums[i];
        }

        if (abs(target) > range || (target + range) % 2 != 0)
            return 0;

        int sum = (target + range) / 2;

        int dp[n+1][sum+1];

        // Base cases
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int j = 1; j <= sum; j++)
            dp[0][j] = 0;

        // Fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } 
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};