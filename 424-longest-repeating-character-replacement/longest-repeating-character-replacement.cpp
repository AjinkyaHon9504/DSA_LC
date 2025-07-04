class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int left=0;
        vector<int>count(26,0);
        int maxcount=0;
        int result=0;

           for(int right=0;right<s.size();right++){
            count[s[right]-'A']++;
            maxcount=max(maxcount,count[s[right]-'A']);

            int windowsize = right - left +1;
            int diffcnt = windowsize - maxcount;
            if (diffcnt > k) {
                count[s[left]-'A']--;
                left++;
            }

            result = max(result,right - left + 1); 
        }
        return result;

    }
};