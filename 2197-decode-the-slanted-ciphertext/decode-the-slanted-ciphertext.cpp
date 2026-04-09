class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if(n == 0) return "";

        int cols = n / rows;

        vector<vector<char>> grid(rows, vector<char>(cols));

        // fill matrix row-wise
        int idx = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                grid[i][j] = encodedText[idx++];
            }
        }

        string result = "";

        // traverse diagonally
        for(int start = 0; start < cols; start++){
            int i = 0, j = start;

            while(i < rows && j < cols){
                result += grid[i][j];
                i++;
                j++;
            }
        }

        // remove trailing spaces
        while(!result.empty() && result.back() == ' '){
            result.pop_back();
        }

        return result;
    }
};