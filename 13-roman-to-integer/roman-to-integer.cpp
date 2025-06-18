class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                if (i + 1 < n && (s[i+1] == 'V' || s[i+1] == 'X')) {
                    num -= 1;
                } else {
                    num += 1;
                }
            } else if (s[i] == 'V') {
                num += 5;
            } else if (s[i] == 'X') {
                if (i + 1 < n && (s[i+1] == 'L' || s[i+1] == 'C')) {
                    num -= 10;
                } else {
                    num += 10;
                }
            } else if (s[i] == 'L') {
                num += 50;
            } else if (s[i] == 'C') {
                if (i + 1 < n && (s[i+1] == 'D' || s[i+1] == 'M')) {
                    num -= 100;
                } else {
                    num += 100;
                }
            } else if (s[i] == 'D') {
                num += 500;
            } else if (s[i] == 'M') {
                num += 1000;
            }
        }

        return num;
    }
};
