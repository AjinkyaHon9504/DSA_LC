class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int need = target - nums[i];

            
            if(map.count(need)){
                return{map[need],i};
            }
            map[nums[i]]=i;
        }

        return {};
    }
};