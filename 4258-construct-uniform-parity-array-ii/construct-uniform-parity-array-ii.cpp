class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        int target = nums1[0] % 2;
        int minOdd = -1;

        for (int x : nums1) {

            // Wrong parity
            if (x % 2 != target) {

                // Need a smaller odd number
                if (minOdd == -1)
                    return false;
            }

            // Current number can become the odd number
            // available for future elements
            if (x % 2 == 1) {
                minOdd = x;
            }
        }

        return true;
    }
};