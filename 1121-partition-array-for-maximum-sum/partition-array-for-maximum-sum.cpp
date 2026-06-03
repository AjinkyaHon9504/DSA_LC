class Solution {
public:

    int solve(int i,vector<int>& arr,int k,vector<int>& dp) {

        int n = arr.size();

        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int sum=0;
        int ans= 0;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            sum = (len*maxi) + solve(j+1,arr,k,dp);
            ans = max(sum,ans);
        }
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();

        vector<int> dp(n, -1);

        return solve(0, arr, k, dp);
    }
};