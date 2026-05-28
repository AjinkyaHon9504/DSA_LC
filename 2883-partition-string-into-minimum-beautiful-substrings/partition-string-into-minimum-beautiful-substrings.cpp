class Solution {
public:

    bool isbeautiful(string str){
        if(str[0]=='0'){
            return false;
        }
        long long num = 0;
        for(char ch : str){
            num = 2*num+(ch - '0');
        }
        while(num%5==0){
            num/=5;
        }
        return num==1;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<int>dp(n+1,INT_MAX);

        dp[0]=0;
        for(int i=0;i<n;i++){
            if(dp[i]==INT_MAX){
                continue;
            }
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isbeautiful(temp)){
                    dp[j+1]= min(dp[j+1],dp[i]+1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};