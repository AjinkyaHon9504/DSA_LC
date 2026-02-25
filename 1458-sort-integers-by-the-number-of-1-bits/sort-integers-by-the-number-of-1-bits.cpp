class Solution {
public:
    int find1(int num) {
        int count = 0;
        while (num != 0) {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int countA = find1(a);
            int countB = find1(b);

            if (countA == countB)
                return a < b;
            return countA < countB;
        });
        return arr;
    }
};