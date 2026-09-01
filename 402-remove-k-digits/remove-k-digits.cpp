class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        for(char ch:num){
            while(k>0 && !st.empty() && st.back()>ch){
                st.pop_back();
                k--;
            }
            st.push_back(ch);}
            while(k>0){
                st.pop_back();
                k--;
            }
            string ans(st.begin(),st.end());
            int i=0;
            while(i<ans.size() && ans[i]=='0'){
                i++;
            }
            
            
        
        ans = ans.substr(i);
        if(ans.empty()){
                return "0";
            }
        return ans;
    }
};