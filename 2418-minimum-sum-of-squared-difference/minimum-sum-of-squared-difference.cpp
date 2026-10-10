
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;

        vector<int> freq(100001, 0);
        int maxDiff = 0;
        long long totalDiff = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);

            freq[diff]++;
            maxDiff = max(maxDiff, diff);
            totalDiff += diff;
        }

        // Enough operations to make all differences zero
        if (k >= totalDiff) {
            return 0;
        }

        // Reduce differences from largest to smallest
        while (k > 0 && maxDiff > 0) {
            int count = freq[maxDiff];

            if (k >= count) {
                // Reduce every occurrence of maxDiff by 1
                k -= count;
                freq[maxDiff] = 0;
                freq[maxDiff - 1] += count;
                maxDiff--;
            } else {
                // Reduce only k occurrences by 1
                freq[maxDiff] -= k;
                freq[maxDiff - 1] += k;
                k = 0;
            }
        }

        long long answer = 0;

        

for (int d = 1; d <= 100000; d++) {
    answer += 1LL * d * d * freq[d];
}

return answer;
    }
};
