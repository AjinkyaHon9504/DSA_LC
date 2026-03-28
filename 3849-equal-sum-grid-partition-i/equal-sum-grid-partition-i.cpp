class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long>rowsum(n,0);
        vector<long long>colsum(m,0);

        long long totalSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                totalSum+=grid[i][j];
                rowsum[i]+=grid[i][j];
                colsum[j]+=grid[i][j];
            }
        }
        if(totalSum % 2 !=0){
            return false;
        }
        long long target = totalSum / 2;

        
        long long uppersum=0;
        long long rightsum=0;
        for(int i=0;i<n-1;i++){
           
                uppersum+=rowsum[i];

                if(uppersum==target){
                    return true;
                }}
                for(int j=0;j<m-1;j++){
                rightsum+=colsum[j];
                if(rightsum==target){
                    return true;
                }
            }
        
        return false;

    }
};