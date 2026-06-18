class Solution {
public:
    double angleClock(int hour, int minutes) {
        //60 min per hour -> 1/2 degree per min (hour hand)
        //12 hour per clock -> 30 degree per hour(hour hand)
        //60 min per clock ->6 degree per hour (min hand)
        float mindegree = minutes * 6;
        float hourdeg = 0;
        if(hour<12){
            hourdeg = (hour * 30) + (0.5 * minutes); 
        }
        else{
            hourdeg = (0.5*minutes);
        }
        float ans = abs(mindegree - hourdeg);
        if(ans>180){
            ans = 360 - ans;
        }
        return ans;
    }
};