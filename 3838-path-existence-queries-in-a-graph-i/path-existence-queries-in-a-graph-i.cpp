class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<bool> answer(queries.size(), false);
        vector<int> comp(n);
        int id=0;
        comp[0]=id;

        for(int i = 1; i <n; i++) {
            if(nums[i]-nums[i-1]>maxDiff){
                id++;
            }
            comp[i]=id;
                }

        for(int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if(comp[u]==comp[v]) {
                answer[i] = true;
            }
        }

        return answer;
    }
};