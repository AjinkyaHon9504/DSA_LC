class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            dp[0]+=i*nums[i];
        }
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+ sum - nums[n-i]*n;
        }
        sort(dp.begin(),dp.end());
        return dp[n];
        
    }
};