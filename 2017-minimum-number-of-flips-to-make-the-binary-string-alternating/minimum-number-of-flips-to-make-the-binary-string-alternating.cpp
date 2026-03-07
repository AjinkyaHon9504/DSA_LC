class Solution {
public:

    int minFlips(string s) {
        int n = s.size();
        string typ1 = s+s;
        int start0=0;
        int start1=0;
        int left = 0;
        int ans = INT_MAX;

        for(int right=0;right<typ1.size();right++){
            char exp0=(right%2==0) ? '0' : '1';
            char exp1=(right%2==0) ? '1' : '0';
            if(typ1[right]!=exp0)start0++;
            if(typ1[right]!=exp1)start1++;

            if(right-left+1 > n){
            char exp0_left=(left%2==0) ? '0' : '1';
            char exp1_left=(left%2==0) ? '1' : '0';
            if(typ1[left]!=exp0_left)start0--;
            if(typ1[left]!=exp1_left)start1--;
            left++;}
            if(right-left+1==n){
                ans=min(ans,min(start0,start1));
            }
            }
        

            return ans;

    }
};