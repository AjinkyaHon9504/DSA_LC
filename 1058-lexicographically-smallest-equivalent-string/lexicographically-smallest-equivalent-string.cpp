class Solution {
public:

    void dfs(unordered_map<char, vector<char>>& adj,
             char curr,
             vector<int>& visited,
             char& minchar) {

        visited[curr - 'a'] = 1;

        minchar = min(minchar, curr);

        for (char v : adj[curr]) {

            if (!visited[v - 'a']) {
                dfs(adj, v, visited, minchar);
            }
        }
    }

    string smallestEquivalentString(string s1,
                                    string s2,
                                    string baseStr) {

        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < s1.size(); i++) {

            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        vector<char> smallest(26);

        for (char c = 'a'; c <= 'z'; c++) {

            vector<int> visited(26, 0);

            char mn = c;

            dfs(adj, c, visited, mn);

            smallest[c - 'a'] = mn;
        }

        string ans;

        for (char ch : baseStr) {
            ans.push_back(smallest[ch - 'a']);
        }

        return ans;
    }
};