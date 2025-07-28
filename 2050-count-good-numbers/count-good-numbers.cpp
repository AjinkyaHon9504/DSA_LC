class Solution {
public:
   const long long MOD = 1e9 + 7;
long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
     


     // base case 5 for even no and 4 for odd num 
     //divide and conquer
 long long evenCount = (n + 1) / 2; // even positions (0-based)
        long long oddCount = n / 2;        // odd positions

        long long evenWays = modPow(5, evenCount);  // 5 choices for even
        long long oddWays = modPow(4, oddCount);    // 4 choices for odd

        return (evenWays * oddWays) % MOD;
        }
    
    
};