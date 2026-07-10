class Solution {
public:
    int divisibleGame(vector<int>& nums) {

        const long long MOD = 1e9 + 7;

        unordered_set<int> ks;

        // k=2 is always a possible choice
        ks.insert(2);

        // Collect all possible useful k values (divisors > 1)
        for (int x : nums) {
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    ks.insert(d);

                    if (d != x / d)
                        ks.insert(x / d);
                }
            }

            if (x > 1)
                ks.insert(x);
        }


        long long maxScoreDiff = LLONG_MIN;
        int bestK = 2;


        // Try only candidate k values
        for (int k : ks) {

            long long curr = 0;
            long long best = LLONG_MIN;


            // Kadane's algorithm
            for (int x : nums) {

                if (x % k == 0)
                    curr += x;
                else
                    curr -= x;


                best = max(best, curr);

                if (curr < 0)
                    curr = 0;
            }


            // Update answer
            if (best > maxScoreDiff) {
                maxScoreDiff = best;
                bestK = k;
            }
            else if (best == maxScoreDiff) {
                bestK = min(bestK, k);
            }
        }


        long long ans = (maxScoreDiff * bestK) % MOD;

        if (ans < 0)
            ans += MOD;

        return ans;
    }
};