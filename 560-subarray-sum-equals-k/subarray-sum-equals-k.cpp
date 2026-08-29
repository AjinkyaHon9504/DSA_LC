class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        freq[0]=1;
        int cnt=0;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(freq.count(sum-k)){
                cnt+=freq[sum-k];
            }
            freq[sum]++;
            
        }
        return cnt;
    }
};