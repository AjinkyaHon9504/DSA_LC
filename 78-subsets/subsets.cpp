class Solution {
public:
    vector<vector<int>>result;
    void pairs(vector<int> &nums ,vector<int> &current , int index){
        result.push_back(current);        //declaring or printing
        int n=nums.size();
        for(int i=index;i<n;i++){
            current.push_back(nums[i]);
            pairs(nums,current,i+1);
            current.pop_back();
        }
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        pairs(nums,current,0);              //starting index from zero then increasing it 
        return result;
    }
};