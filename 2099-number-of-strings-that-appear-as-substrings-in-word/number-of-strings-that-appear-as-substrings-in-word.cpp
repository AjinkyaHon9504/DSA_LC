class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.length();
        int m = patterns.size();
        int count=0;

        for(int i=0;i<m;i++){
        
               if (word.find(patterns[i]) != string::npos){
                count++;
               }
            
        }
        return count;
       
        
    }
};