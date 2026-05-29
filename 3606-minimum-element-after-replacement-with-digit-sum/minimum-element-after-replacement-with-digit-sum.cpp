class Solution {
public:

    int sumdigits(int digits) {

        int newop = 0;

        while (digits != 0) {

            newop += digits % 10;
            digits = digits / 10;
        }

        return newop;
    }

    int minElement(vector<int>& nums) {

        int n = nums.size();

        vector<int> vecdigsum;

        for (int i = 0; i < n; i++) {

            vecdigsum.push_back(sumdigits(nums[i]));
        }

        sort(vecdigsum.begin(), vecdigsum.end());

        return vecdigsum[0];
    }
};