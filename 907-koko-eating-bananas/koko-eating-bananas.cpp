class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int low = 1;
        int high = piles[n-1];
        long long ans=high;

        while(high>=low){
        long long hours=0;

        
        int mid = low + (high-low)/2;

        for(int i=0;i<n;i++){
            if(piles[i]<=mid){
                hours+=1;
            }
            else{
                hours += (piles[i] + mid - 1) / mid;            }
        }
        if(hours<=h){//return min hours and test with mid -1 
        ans = mid;
        high=mid-1;

        }
        else{
        //inc low by 1
        low=mid+1; 
        }
    }
    return ans;}
};