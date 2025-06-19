class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;
        
        string trimmed = "";
        bool spaceFound = false;
        for (int i = start; i <= end; i++) {
            if (s[i] != ' ') {
                trimmed += s[i];
                spaceFound = false;
            } else if (!spaceFound) {
                trimmed += ' ';
                spaceFound = true;
            }
        }

        int n = trimmed.size();
        for (int i = 0; i < n / 2; i++) {
            swap(trimmed[i], trimmed[n - 1 - i]);
        }

        string result = "";
        int i = 0;
        while (i < n) {
            if (trimmed[i] != ' ') {
                int j = i;
                while (j < n && trimmed[j] != ' ') j++;

                for (int k = j - 1; k >= i; k--) {
                    result += trimmed[k];
                }

                if (j < n) result += ' ';
                i = j;
            } else {
                i++;
            }
        }

        return result;
    }
};
