class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        if(n==1) return nums[0];
        dp[0]=0;
        dp[1]=nums[0];
        int result1=0;
        int result2=0;
        
        //nums[0] and nums[n]

        for(int i=1;i<=n-1;i++){
            int steal = nums[i-1] + (i-2>=0 ? dp[i-2] : 0);
            int skip = dp[i-1];
            dp[i]=max(steal,skip);
            
        }
        result1 = dp[n-1];

        dp.clear();
        dp[0]=0;
        dp[1]=0;

        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + (i-2>=0 ? dp[i-2] : 0);
            int skip = dp[i-1];
            dp[i]=max(steal,skip);
            
        }
        result2 = dp[n];

        return max(result1,result2);
    }
};