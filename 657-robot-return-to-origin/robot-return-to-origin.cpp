class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.length();
        vector<int> arr;
        int cntl=0;
        int cntr=0;
        int cntu=0;
        int cntd=0;
        for(int i=0;i<n;i++){
            
                
                    //equal left right or equal top down

                if(moves[i]=='L'){
                    cntl ++;
                }
                if(moves[i]=='U'){
                    cntu++;
                }
                if(moves[i]=='D'){
                    cntd++;

                }
                if(moves[i]=='R'){
                    cntr++;
                }
            
        }

        if((cntr == cntl) && (cntu == cntd)){
            return true;
        }
        return false;
    }
};