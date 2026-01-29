class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0] = -1;

        int count0=0;
        int count1=0;
        int maxlen =0;

        for(int i=0;i<nums.size();i++){
         if (nums[i] == 0) count0++;
            else count1++;

        int diff = count1 - count0;
        if (map.find(diff) != map.end()) {
                maxlen = max(maxlen, i - map[diff]);
            } else {
                map[diff] = i;
            }

        }
        return maxlen;
    }
};