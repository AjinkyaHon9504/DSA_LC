class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int>ones;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ones.push_back(i);
            }
        }
        if(ones.size()<k){
            return "";
        }
        string ans="";
        for(int i=0;i+k-1<ones.size();i++){
            int start=ones[i];
            int end=ones[i+k-1];
            string candidate=s.substr(start,end-start+1);
            if(ans==""||candidate.size()<ans.size()||(candidate.size()==ans.size()&&candidate<ans)){
                ans=candidate;
            }}
            return ans;
        
    }
};