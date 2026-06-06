class Solution {
public:
    int sum(int start, int end, vector<int>& nums){

    int total = 0;

    for(int i = start; i < end; i++){
        total += nums[i];
    }

    return total;
}
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftsum(n);
        vector<int>rightsum(n);
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            leftsum[i]=sum(0,i,nums);        //i=0 to i=i-1
            rightsum[i]=sum(i+1,n,nums); 
            ans[i]=abs(leftsum[i]-rightsum[i]);      //i=i+1 to i=n
        }
        return ans;

    }
};