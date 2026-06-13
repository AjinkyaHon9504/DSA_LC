class Solution {
public:
    
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        vector<int>sum(n,0);
            string result(n, ' ');        
            for(int i=0;i<n;i++){
            
            for(char &ch : words[i]){
                sum[i]+=weights[ch-'a'];
            }
            sum[i]=sum[i]%26;
            int x =(25-sum[i]);
            char ch = 'a' + x;
            result[i]=ch;
        }
        return result;
    }
};