class Solution {
public:

    int iswavy(int num) {

        int cnt = 0;
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(digits.begin(), digits.end());

        if (digits.size() < 3) {
            return 0;
        }

        for (int i = 1; i < digits.size() - 1; i++) {

            if ((digits[i] > digits[i - 1] &&
                 digits[i] > digits[i + 1]) ||

                (digits[i] < digits[i - 1] &&
                 digits[i] < digits[i + 1])) {

                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {

        vector<int> arr;

        for (int x = num1; x <= num2; x++) {
            arr.push_back(x);
        }

        int n = arr.size();

        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            int waviness = iswavy(arr[i]);

            if (i == 0) {
                dp[i] = waviness;
            }
            else {
                dp[i] = dp[i - 1] + waviness;
            }
        }

        return dp[n - 1];
    }
};