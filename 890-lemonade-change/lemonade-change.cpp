class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten =0;
        int i =0;
        while( i<bills.size()){

        if(bills[i]==5){
            five++;
        }
        if(bills[i]==10){
            //change=5
            if(five>0){
                five--;
                ten++;
            }
            else{
                return false;
            }
        }
        if(bills[i]==20){
            //change 3 five or 1 ten and 1 five 
            if(ten>0 && five>0){
                five--;
                ten--;
            }
            else if(five>=3){
                five-=3;
            }
            else{
                return false;
            }
            

        }
        i++;
    }
    return true;}
};