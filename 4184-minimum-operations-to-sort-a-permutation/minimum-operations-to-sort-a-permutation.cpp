#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Find the index of 0
        int pos0 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }

        // Check if nums is cyclically ascending
        bool isAscending = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 + i) % n] != i) {
                isAscending = false;
                break;
            }
        }

        // Check if nums is cyclically descending
        bool isDescending = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 - i + n) % n] != i) {
                isDescending = false;
                break;
            }
        }

        int ans = -1;

        if (isAscending) {
            int costAsc = (pos0 == 0) ? 0 : min(pos0, n - pos0 + 2);
            ans = (ans == -1) ? costAsc : min(ans, costAsc);
        }

        if (isDescending) {
            int costDesc = min(((pos0 + 1) % n) + 1, n - pos0);
            ans = (ans == -1) ? costDesc : min(ans, costDesc);
        }

        return ans;
    }
};