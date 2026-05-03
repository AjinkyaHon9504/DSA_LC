class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string ss = s+s;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(ss.substr(i,n)==goal){
                return true;
            }
            
        }
        return false;
    }
};