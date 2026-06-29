class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=0;
        int curmul=0;

        for(int i=n-1;i>=n-k;i--){
            if(mul>1){
                sum += 1LL * nums[i] * mul;
                mul--;
                }
            else{
                sum+=nums[i];
            }
        }
        return sum;
    }
};