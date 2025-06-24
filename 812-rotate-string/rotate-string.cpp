class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) return true;

        queue<char> q1, q2;

        for (char c : s) q1.push(c);
        for (char c : goal) q2.push(c);

        int n = s.size();
        while (n--) {
            // Rotate q1
            char front = q1.front();
            q1.pop();
            q1.push(front);

            // Compare q1 and q2 manually
            queue<char> temp1 = q1;
            queue<char> temp2 = q2;
            bool isSame = true;

            while (!temp1.empty()) {
                if (temp1.front() != temp2.front()) {
                    isSame = false;
                    break;
                }
                temp1.pop();
                temp2.pop();
            }

            if (isSame) return true;
        }

        return false;
    }
};
