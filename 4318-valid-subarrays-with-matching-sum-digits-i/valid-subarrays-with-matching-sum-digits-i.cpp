class Solution {
public:

    
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count=0;
        vector<long long> sums;

        for(int i = 0; i < n; i++) {
          long long curr = 0;

         for(int j = i; j < n; j++) {
          curr += nums[j];
          sums.push_back(curr);
          }
         }

        
        for(int i=0;i<sums.size();i++){
        long long target = sums[i];
        long long temp = abs(target);

        int lastDigit = temp % 10;

        while(temp >= 10)
        temp /= 10;

            int firstDigit = temp;

        if(firstDigit == x && lastDigit == x)
        count++;
        }
       
        return count;


    }
};