class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        int k =2;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(k+1,LLONG_MIN)));
        for(int a =0;a<=k;a++){
            dp[0][0][a]=coins[0][0];

            if(coins[0][0]<0 && a>0){
                dp[0][0][a]=0;
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int a=0;a<=k;a++){

                    if(i==0 && j==0) continue;
                    long long val = coins[i][j];

                    //top
                    if(i>0){
                        dp[i][j][a]=max(dp[i][j][a],dp[i-1][j][a]+val);

                        if(val<0 && a>0){
                            dp[i][j][a]=max(dp[i][j][a],dp[i-1][j][a-1]);
                        }
                    }

                    if(j>0){
                        dp[i][j][a]=max(dp[i][j][a],dp[i][j-1][a]+val);
                        if(val<0 && a>0){
                            dp[i][j][a] = max(dp[i][j][a],dp[i][j-1][a-1]);
                        }
                    }



                }
            }

        }
        long long ans=LLONG_MIN;
        for(int a=0;a<=k;a++){
            ans=max(ans,dp[n-1][m-1][a]);
        }
        
        return ans;
    }
};