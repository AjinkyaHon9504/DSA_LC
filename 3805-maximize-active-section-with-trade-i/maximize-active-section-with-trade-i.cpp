class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
      int n = s.size();

        // Count initial active sections ('1's)
        int ones = 0;
        for(char c : s)
            if(c == '1')
                ones++;

        // Augment the string
        string t = "1" + s + "1";

        // Run Length Encoding
        vector<pair<char,int>> runs;

        for(char c : t) {
            if(runs.empty() || runs.back().first != c)
                runs.push_back({c,1});
            else
                runs.back().second++;
        }

        int gain = 0;

        // Look for 0 - 1 - 0 pattern
        for(int i = 1; i + 1 < runs.size(); i++) {

            if(runs[i].first == '1' &&
               runs[i-1].first == '0' &&
               runs[i+1].first == '0') {

                gain = max(gain,
                           runs[i-1].second + runs[i+1].second);
            }
        }

        return ones + gain;
    }
};