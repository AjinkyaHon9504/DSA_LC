class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int low=1;
        int high=piles[n-1];
        long long ans = high;

        while(low<=high){
            long long hours=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<n;i++){
                if(piles[i]<=mid){
                    hours+=1;
                }
                else{
                    hours+=(piles[i]+mid-1)/mid;
                }
            }
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;



        }
};