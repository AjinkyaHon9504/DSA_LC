class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {

        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    int solve(int i, string &s, vector<int>& dp) {

        int n = s.size();

        if (i == n) {
            return -1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int mincost = INT_MAX;

        for (int j = i; j < n; j++) {

            if (isPalindrome(s, i, j)) {

                int cost = 1 + solve(j + 1, s, dp);

                mincost = min(mincost, cost);
            }
        }

        return dp[i] = mincost;
    }

    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};