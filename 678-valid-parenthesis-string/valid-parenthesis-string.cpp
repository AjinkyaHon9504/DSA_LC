class Solution {
public:
    bool checkValidString(string s) {
   int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;  // treat '(' as required open
                high++; // max open
            } else if (c == ')') {
                if (low > 0) low--;  // one open is matched
                high--;              // max open reduced
            } else { // c == '*'
                if (low > 0) low--;  // use * as ')'
                high++;              // or * as '('
            }

            if (high < 0) return false;  // too many ')'
        }

        return low == 0;  
    }



      
       
    
};