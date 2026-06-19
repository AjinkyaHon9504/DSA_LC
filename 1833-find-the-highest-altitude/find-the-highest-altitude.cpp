class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>dp(n+1);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
            dp[i]=dp[i-1]+gain[i-1];
        }
        sort(dp.begin(),dp.end());
        return dp[n];
    }
};