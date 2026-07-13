class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {

        vector<int> answer;

        string s = "123456789";

        for(int len = 2; len <= 9; len++) {

            for(int start = 0; start + len <= 9; start++) {

                string temp = s.substr(start, len);

                int num = stoi(temp);

                if(num >= low && num <= high) {
                    answer.push_back(num);
                }
            }
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};