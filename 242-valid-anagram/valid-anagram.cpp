class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        for (char c : t) {
            count[c]--;
        }

        for (auto pair : count) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true; 
    }
};
