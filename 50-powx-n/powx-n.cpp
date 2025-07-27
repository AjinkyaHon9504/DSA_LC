

    class Solution {
public:
    double myPow(double x, int n) {
        // Base case
        if (n == 0) return 1;

        // Handle negative power safely using long
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N; // Convert to positive
        }

        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
