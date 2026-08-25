class Solution {
public:

    bool cansplit(vector<int>& nums, int k,int limit){
        int subarrays=1;
        long long cursum=0;
        for(int num:nums){
            if(cursum+num>limit){
                subarrays++;
                cursum=num;
            }
            else{
                cursum+=num;
            }

        }
        return subarrays<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long left =*max_element(nums.begin(),nums.end());
        long long right = 0;
        for(int num:nums){
            right+=num;
        }
        long long ans = right;
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(cansplit(nums,k,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};