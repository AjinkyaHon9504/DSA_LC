class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int solve(int i, string &s, vector<int>& dp) {

        int n = s.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int j = i; j < n; j++) {

            if(isPalindrome(s, i, j)) {

                ans = min(ans,
                          1 + solve(j + 1, s, dp));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp) - 1;
    }
};