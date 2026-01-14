class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int count = 0 ;
        int target = k * threshold;
        int left = 0;

        for(int right=0;right<n;right++){
            sum += arr[right];

            if(right - left + 1 == k){
                if(sum >= target){
                    count++;
                }
                    sum -= arr[left];
                    left++;
            }
} 
return count;   }
};