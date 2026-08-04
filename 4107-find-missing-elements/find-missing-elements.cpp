class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int mn = nums[0];
        int mx = nums.back();
        vector<int>ans;

        for(int i=mn;i<mx;i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
        

    }
};