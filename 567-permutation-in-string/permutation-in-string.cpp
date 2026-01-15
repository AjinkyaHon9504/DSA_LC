class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //s2 permutation of s1
        if(s1.size()>s2.size()) return false;
        vector<int> freq(26,0);
        for(char c : s1){
            freq[c-'a']++;
        }
        int left =0;
        int right=0;
        int count = s1.size();

        while(right<s2.size()){
            if(freq[s2[right]-'a' ]> 0){
                count--;
            }
            freq[s2[right]-'a']--;
            right++;

            if(count==0){
                return true;
            }

            if(right - left == s1.size()){
                if(freq[s2[left]-'a'] >= 0){
                    count++;

                }
                freq[s2[left]-'a']++;
                left++;
            }
        }

return false;
    }
};