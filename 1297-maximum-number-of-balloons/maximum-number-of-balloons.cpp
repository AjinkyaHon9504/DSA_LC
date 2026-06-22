class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int> mp;

        for(char ch : text)
            mp[ch]++;

        int count = 0;

        while(mp['b'] >= 1 &&
              mp['a'] >= 1 &&
              mp['l'] >= 2 &&
              mp['o'] >= 2 &&
              mp['n'] >= 1) {

            count++;

            mp['b']--;
            mp['a']--;
            mp['l'] -= 2;
            mp['o'] -= 2;
            mp['n']--;
        }

        return count;
    }
};