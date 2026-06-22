class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            long long curr = 0;

            for(int j = i; j < n; j++) {
                curr += nums[j];

                long long temp = curr;

                int lastDigit = temp % 10;

                while(temp >= 10)
                    temp /= 10;

                int firstDigit = temp;

                if(firstDigit == x && lastDigit == x)
                    count++;
            }
        }

        return count;
    }
};