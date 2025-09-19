class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);  // found a permutation
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // skip used numbers

            // choose
            used[i] = true;
            path.push_back(nums[i]);

            // explore
            backtrack(nums, used, path, result);

            // unchoose (backtrack)
            path.pop_back();
            used[i] = false;
        
    }}
};