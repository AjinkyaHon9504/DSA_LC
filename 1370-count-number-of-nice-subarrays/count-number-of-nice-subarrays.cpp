class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);}
    int atMostK(vector<int>& nums, int k) {
        int left=0;int right=0;int maxnum = 0;
        int sum=0;
        int kcount=0;
        int count = 0;

           while (right < nums.size()) {
           // sum += nums[right];
           if(nums[right]%2!=0){
            //ODD
            kcount+=1;
           }

            while (kcount > k) {
            if(nums[left]%2!=0){
            //odd
             kcount-=1;
           }
           
                left++;
            }

            count += (right - left + 1); 
          right++;
        }
        return count;
    }
    
};