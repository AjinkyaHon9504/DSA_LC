class Solution {
public:

    int solve(vector<int>& stones,int i,int target,vector<vector<int>>&dp){
        if(i==stones.size() || target==0)return 0;
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int notTake=solve(stones,i+1,target,dp);
        int take=0;
        if(stones[i]<=target){
            take=stones[i]+solve(stones,i+1,target-stones[i],dp);
        }
        return dp[i][target]=max(take,notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0);
        int target = total/2;
        vector<vector<int>>dp(stones.size(),vector<int>(target+1,-1));
        int best=solve(stones,0,target,dp);
        return total - 2*best;
    }
};