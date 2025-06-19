class Solution {
public:
    string removeOuterParentheses(string s) {
        string sum = "";
        int depth = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (depth > 0) {
                    sum += s[i]; 
                }
                depth++;
            } else if (s[i] == ')') {
                depth--;
                if (depth > 0) {
                    sum += s[i]; 
                }
            }
        }

        return sum;
    }
};
