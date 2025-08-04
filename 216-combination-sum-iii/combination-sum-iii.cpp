class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int k, int n, vector<int>& current, int start) {
        if (n == 0 && current.size() == k) {
            result.push_back(current);
            return;
        }

        if (n < 0 || current.size() > k) return;

        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            backtrack(k, n - i, current, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        backtrack(k, n, current, 1); // Start from 1 to 9
        return result;
    }
};
