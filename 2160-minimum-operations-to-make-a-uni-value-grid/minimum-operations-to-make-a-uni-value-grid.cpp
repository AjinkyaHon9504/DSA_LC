class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int result =0;
        vector<int>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int L = vec.size();//m*n
        sort(vec.begin(),vec.end());
        int target = vec[L/2];

        for(int &num : vec){
            if(num%x != target%x){
                return -1;
            }
            else{
                result +=abs(target-num)/x;
            }

        }
        return result;
    }
};