class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            unordered_map<int, int> freq;
            map<int, int> freqCnt; // frequency -> count of values

            for (int r = l; r < n; r++) {
                int x = nums[r];

                if (freq.count(x)) {
                    int oldFreq = freq[x];

                    freqCnt[oldFreq]--;
                    if (freqCnt[oldFreq] == 0)
                        freqCnt.erase(oldFreq);
                }

                freq[x]++;
                freqCnt[freq[x]]++;

                bool ok = false;

                if (freq.size() == 1) {
                    ok = true;
                }
                else if (freqCnt.size() == 2) {
                    auto it1 = freqCnt.begin();
                    auto it2 = next(it1);

                    int f1 = it1->first;
                    int f2 = it2->first;

                    if (f2 == 2 * f1)
                        ok = true;
                }

                if (ok)
                    ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};