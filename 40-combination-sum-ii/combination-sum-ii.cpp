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
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        current.push_back(candidates[i]);                     // choose
        backtrack(candidates,current, i+1, remainingSum - candidates[i]);  // reuse same index
        current.pop_back();   

    }}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
           sort(candidates.begin(), candidates.end()); 
        vector<int> current;
        backtrack(candidates,current,0, target);
        return result;
    }
        
  
};