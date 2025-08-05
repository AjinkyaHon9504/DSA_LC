class Solution {
public:
    vector<string> result;
    vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(string &digits,string &current,int index) {
        if(current.size()== digits.size()){
            result.push_back(current);
            return;
        }
        if(current.size()<0){
            return;
        }
        int digit = digits[index] - '0';
        for(char c : keypad[digit]){
        current.push_back(c);
        backtrack(digits, current, index + 1);
        current.pop_back(); // backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string current;
        backtrack(digits,current,0);
        return result;
    }
};