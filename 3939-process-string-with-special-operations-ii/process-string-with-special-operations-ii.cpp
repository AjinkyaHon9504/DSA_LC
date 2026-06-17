class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long INF = 1e18;

        vector<long long> len(n + 1, 0);

        // Compute lengths
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len[i + 1] = min(INF, len[i] + 1);
            } 
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            } 
            else if (c == '#') {
                len[i + 1] = min(INF, len[i] * 2);
            } 
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        // Work backwards
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (len[i] == k) return c;
            }
            else if (c == '*') {
                // Forward removed last char.
                // Backward: length increased by 1, k unchanged.
            }
            else if (c == '#') {
                long long half = len[i];
                if (k >= half) k -= half;
            }
            else { // '%'
                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};