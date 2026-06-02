class Solution {
public:
    
    int calc(vector<int>& firstStart,
             vector<int>& firstDur,
             vector<int>& secondStart,
             vector<int>& secondDur) {

        int minEnd = INT_MAX;

        // earliest finish among first category
        for (int i = 0; i < firstStart.size(); i++) {
            minEnd = min(minEnd, firstStart[i] + firstDur[i]);
        }

        int ans = INT_MAX;

        // try every ride of second category
        for (int i = 0; i < secondStart.size(); i++) {

            int startSecond = max(minEnd, secondStart[i]);

            ans = min(ans, startSecond + secondDur[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landThenWater =
            calc(landStartTime, landDuration,
                 waterStartTime, waterDuration);

        int waterThenLand =
            calc(waterStartTime, waterDuration,
                 landStartTime, landDuration);

        return min(landThenWater, waterThenLand);
    }
};