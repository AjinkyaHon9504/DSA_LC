class Solution {
public:
    vector<vector<int>> result;
     void backtrack(vector<int>& candidates,vector<int>& current, int index, int remainingSum){

        if(remainingSum ==0){
            result.push_back(current);
            return;
        }
        if(remainingSum<0){
            return;
        } 
        for(int i = index; i < candidates.size(); i++) {
        current.push_back(candidates[i]);                     // choose
        backtrack(candidates,current, i, remainingSum - candidates[i]);  // reuse same index
        current.pop_back();                     
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        backtrack(candidates,current,0, target);
        return result;
    }
};