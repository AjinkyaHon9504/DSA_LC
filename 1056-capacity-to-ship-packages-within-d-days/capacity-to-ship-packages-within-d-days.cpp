class Solution {
public:

    bool possible(vector<int>& weights, int &days,int &capacity){
        int daysused =1;
        int curr =0;

        for(int w : weights){
            if(curr + w <= capacity){
                curr +=w;
            }
            else{
                daysused++;
                curr =w;
            }
        }
        return daysused <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        vector<int>newv(n);
        newv = weights;
        sort(newv.begin(),newv.end());
        int low = newv[n-1];
        int sum = 0;
        for(int i=0;i<n;i++){
        sum+=weights[i];}
        
        int high = sum;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (possible(weights, days, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
        
    }
};