class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+2,0);
        for(auto booking:bookings){
            int first=booking[0];
            int last=booking[1];
            int seats=booking[2];
            diff[first]+=seats;
            diff[last+1]-=seats;

        }
        vector<int>ans(n);
        int curr=0;
        for(int i=1;i<=n;i++){
            curr+=diff[i];
            ans[i-1]=curr;
        }
        return ans;

    }
};