class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>s1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int>s2;
        for(int pairxor : s1){
            for(int &num : nums){
                s2.insert(num^pairxor);
            }
        }
        return s2.size();
    }
};