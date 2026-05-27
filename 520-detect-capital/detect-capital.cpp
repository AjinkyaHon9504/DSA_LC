class Solution {
public:
    bool detectCapitalUse(string word) {
        unordered_set<char>lower;
        unordered_set<char>upper;
        int n  = word.length();
        for(char ch: word){
            if(islower(ch)) {
                lower.insert(ch);
                                }
            else {
                upper.insert(ch);
            }
        }
        int countu =0;
        int countl =0;

        for(int i=0;i<n;i++){
            
            if(upper.count(word[i])){
                countu++;
            }
            if(lower.count(word[i])){
                countl++;
            }
            
        }
        if(countl == n){
            return true;
        }
        else{
            if(upper.count(word[0]) && countu==1){
                return true;
            }
        }
        if(countu == n){
            return true;
        }
        return false;
    }
};