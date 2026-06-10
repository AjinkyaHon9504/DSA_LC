class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int v : nums){
            map[v]++;
        }
        for(auto &it : map){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
    }
};