class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx=0;
        int maxidx=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[minidx]){
                minidx=i;
            }
            if(nums[i]>nums[maxidx]){
                maxidx=i;
            }

        }
        int left = min(minidx,maxidx);
        int right = max(minidx,maxidx);

        int c1=right+1;
        int c2=n-left;
        int c3=(left+1)+(n-right);
        return min({c1,c2,c3});
    }
};