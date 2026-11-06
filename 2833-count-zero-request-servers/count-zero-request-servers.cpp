
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int left = 0, right = 0;
        int active = 0;

        for(auto &[time, idx] : q) {

            int start = time - x;

            // Add logs within the right boundary
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                int server = logs[right][0];

                if(freq[server] == 0)
                    active++;

                freq[server]++;
                right++;
            }

            // Remove logs outside the left boundary
            while(left < right &&
                  logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
