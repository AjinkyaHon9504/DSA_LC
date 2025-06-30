class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};  // to track frequency of each character
        int left = 0, right = 0;
        int maxLen = 0;
        int n = s.length();


        while(right<n){
            char curr = s[right];
            //freq inc of current char ki count badhega
            freq[curr]++;
             while (freq[curr] > 1) {
                freq[s[left]]--;
                left++;
            }
             maxLen = max(maxLen, right - left + 1);
            right++;
        
        }
        return maxLen;
    }
};