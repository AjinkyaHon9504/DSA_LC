class Solution {
public:
    string greatestLetter(string s) {

        unordered_set<char> lower;
        unordered_set<char> upper;

        // store lowercase and uppercase letters
        for (char ch : s) {

            if (islower(ch)) {
                lower.insert(ch);
            }
            else {
                upper.insert(ch);
            }
        }

        // traverse from greatest to smallest
        for (char ch = 'Z'; ch >= 'A'; ch--) {

            if (upper.count(ch) && lower.count(tolower(ch))) {

                string ans = "";
                ans += ch;

                return ans;
            }
        }

        return "";
    }
};