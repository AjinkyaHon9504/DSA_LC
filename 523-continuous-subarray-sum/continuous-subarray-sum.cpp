class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(mp.count(rem)){  //agar map me rem mila
            if(i-mp[rem]>=2){
                return true;
            }
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};