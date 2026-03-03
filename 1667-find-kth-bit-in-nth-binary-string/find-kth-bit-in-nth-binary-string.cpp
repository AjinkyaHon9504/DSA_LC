class Solution {
public:
    char findKthBit(int n, int k) {
        string s ="0";
        for(int i=2;i<=n;i++){
            string rev = s;
            reverse(rev.begin(),rev.end());
        
        for(int j=0;j<rev.size();j++){
            if(rev[j]=='0'){
                rev[j]='1';
            }
            else{
                rev[j]='0';
            }
            
        }
        s=s+"1"+rev;}
        return s[k-1];
    }
};