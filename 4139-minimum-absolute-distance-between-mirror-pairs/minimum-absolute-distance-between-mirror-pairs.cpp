class Solution {
public:

    int reverseNum(int num){
        int rev = 0;

        while(num > 0){
            int dig = num % 10;
            rev = rev * 10 + dig;
            num /= 10;
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<int,int> mp;

        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){

            int revNum = reverseNum(nums[i]);

            // Check if current number exists as reverse of earlier
            if(mp.find(nums[i]) != mp.end()){

                int diff = i - mp[nums[i]];
                ans = min(ans, diff);
            }

            // Store reversed number
            mp[revNum] = i;
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};