class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int> sortedArr;

        for(int x : arr) {
            sortedArr.insert(x);
        }

        unordered_map<int,int> mp;

        int rank = 1;
        for(int x : sortedArr) {
            mp[x] = rank++;
        }

        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};