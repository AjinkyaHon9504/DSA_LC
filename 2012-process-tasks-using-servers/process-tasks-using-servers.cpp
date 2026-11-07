
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // {freeTime, weight, index}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busy;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Initially all servers are available
        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that have become free
            while(!busy.empty() &&
                  get<0>(busy.top()) <= time) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is free, jump to earliest free time
            if(available.empty()) {

                time = get<0>(busy.top());

                // Release ALL servers free at this time
                while(!busy.empty() &&
                      get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;

            // Assign current task
            busy.push({
                time + tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};
