
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        // Available server IDs
        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {freeTime, serverIndex}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        int n = arrival.size();

        for(int i = 0; i < n; i++) {

            // 1. Release servers that have finished
            while(!busy.empty() &&
                  busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // 2. If all servers are busy, drop request
            if(available.empty()) {
                continue;
            }

            // 3. Preferred server
            int start = i % k;

            // 4. Find next available server
            auto it = available.lower_bound(start);

            // Wrap around if necessary
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // 5. Assign request
            available.erase(it);

            count[server]++;

            // 6. Mark server as busy
            long long freeTime =
                (long long)arrival[i] + load[i];

            busy.push({freeTime, server});
        }

        // 7. Find maximum handled requests
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
