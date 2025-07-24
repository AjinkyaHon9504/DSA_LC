class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int n = cardPoints.size();
         int total = 0;
         int left=0;
         int leftsum =0;

          for (int i = 0; i < k; i++) {
         leftsum += cardPoints[i];
    }

    int maxScore = leftsum;
    int rsum=0;

    for (int i = 1; i <= k; i++) {
       leftsum -= cardPoints[k-i];
       rsum += cardPoints[n-i]; 
       maxScore = max(maxScore, leftsum + rsum);
    }
    return maxScore;

    }
};