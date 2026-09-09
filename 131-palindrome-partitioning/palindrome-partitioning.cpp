class Solution {
public:
    vector<vector<string>>ans;
    bool ispalindrome(string s,int start,int end){

        while(end>start){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        
        
        }

    void backtrack(string &s,vector<string>&curr,int index){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
            curr.push_back(s.substr(index,i-index+1));
            backtrack(s,curr,i+1);
            curr.pop_back();
        }
    }
    };
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        backtrack(s,curr,0);
        return ans;
    }
};