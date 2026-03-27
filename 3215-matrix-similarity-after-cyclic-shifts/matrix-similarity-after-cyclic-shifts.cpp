class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> oldmat = mat;

        k = k % m; // important optimization

        for(int step = 0; step < k; step++){
            for(int i = 0; i < n; i++){
                vector<int> temp = mat[i];

                if(i % 2 == 0){ // even row → left shift
                    for(int j = 0; j < m; j++){
                        mat[i][j] = temp[(j + 1) % m];
                    }
                }
                else{ // odd row → right shift
                    for(int j = 0; j < m; j++){
                        mat[i][j] = temp[(j - 1 + m) % m];
                    }
                }
            }
        }

        return mat == oldmat;
    }
};