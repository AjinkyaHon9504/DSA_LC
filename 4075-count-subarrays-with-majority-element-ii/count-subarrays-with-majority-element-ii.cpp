class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>map;
        map[0]=1;
        int cursum=0;
        long long validleftpoints=0;
        long long result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validleftpoints+=map[cursum];
                cursum+=1;
            }
            else{
                cursum-=1;
                validleftpoints-=map[cursum];
            }
            map[cursum]+=1;
             result+=validleftpoints;
        }
        return result;
            }
};