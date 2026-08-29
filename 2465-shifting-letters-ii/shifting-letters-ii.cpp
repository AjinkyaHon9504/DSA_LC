class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>diff(n+1,0);
        for(auto &quey:shifts){
            int start = quey[0];
            int end = quey[1];
            int dir = quey[2];
            int val = (dir==1)?1:-1;
            diff[start]+=val;
            diff[end+1]-=val;
        }
        int shift=0;
        for(int i=0;i<n;i++){
            shift+=(diff[i]);
            int current = s[i]-'a';
            current=(current+shift)%26;
            if(current<0){
                current+=26;
            }
            s[i]=char('a'+current);

        }
        return s;
    }
};