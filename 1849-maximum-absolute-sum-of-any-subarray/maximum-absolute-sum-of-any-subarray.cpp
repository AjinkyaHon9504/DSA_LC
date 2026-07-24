class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxend=0;
        int minend=0;
        int maxsum=0;
        int minsum = 0;
        for(int x : nums){
            maxend = max(x,maxend+x);
            maxsum = max(maxsum,maxend);
            minend = min(x,minend+x);
            minsum = min(minsum,minend);
        }
        return max(maxsum,-minsum);
    }
};