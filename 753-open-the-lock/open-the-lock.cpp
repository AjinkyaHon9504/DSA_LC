class Solution {
public:

    vector<string> getNeighbors(string s) {

        vector<string> res;

        for(int i = 0; i < 4; i++) {

            string temp = s;

            // increase wheel
            temp[i] = (s[i] - '0' + 1) % 10 + '0';
            res.push_back(temp);


            // decrease wheel
            temp = s;
            temp[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(temp);
        }

        return res;
    }


    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead;

        for(string s : deadends)
            dead.insert(s);


        // starting position is blocked
        if(dead.count("0000"))
            return -1;


        queue<string> q;

        unordered_set<string> visited;


        q.push("0000");
        visited.insert("0000");


        int steps = 0;


        while(!q.empty()) {

            int size = q.size();


            while(size--) {

                string curr = q.front();
                q.pop();


                if(curr == target)
                    return steps;


                for(string next : getNeighbors(curr)) {

                    if(!visited.count(next) && !dead.count(next)) {

                        visited.insert(next);
                        q.push(next);

                    }
                }
            }


            steps++;
        }


        return -1;
    }
};