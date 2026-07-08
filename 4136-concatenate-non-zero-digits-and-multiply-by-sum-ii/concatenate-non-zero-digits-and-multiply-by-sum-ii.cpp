class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1e9 + 7;

        int n = s.size();

        vector<long long> prefixNum(n);
        vector<long long> prefixSum(n);
        vector<long long> cnt(n);

        long long num = 0;
        long long sum = 0;
        long long count = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] != '0') {
                int digit = s[i]-'0';

                num = (num * 10 + digit) % MOD;
                sum += digit;
                count++;
            }

            prefixNum[i] = num;
            prefixSum[i] = sum;
            cnt[i] = count;
        }


        // powers of 10
        vector<long long> pow10(n+1);
        pow10[0] = 1;

        for(int i=1;i<=n;i++)
            pow10[i] = (pow10[i-1] * 10) % MOD;


        vector<int> ans;


        for(auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long x = prefixNum[r];

            long long beforeNum = 0;
            long long beforeCnt = 0;

            if(l > 0) {
                beforeNum = prefixNum[l-1];
                beforeCnt = cnt[l-1];
            }


            long long digitsToRemove = cnt[r] - beforeCnt;


            // remove previous digits
            x = (prefixNum[r] - 
                (beforeNum * pow10[digitsToRemove]) % MOD 
                + MOD) % MOD;


            long long sumRange = prefixSum[r];

            if(l > 0)
                sumRange -= prefixSum[l-1];

            sumRange %= MOD;


            ans.push_back((x * sumRange) % MOD);
        }


        return ans;
    }
};