class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        stack<int> st;
        vector<bool> vis(n,false);
        st.push(0);
        vis[0]=true;

        while(!st.empty()){
            int room = st.top();
            st.pop();

            for(int key : rooms[room]){  // keys in current room
                if (!vis[key]) {           // if not visited
                    vis[key] = true;
                    st.push(key);          // push onto stack
                }
            }
        }for (bool v : vis) {
            if (!v) return false;
        }
        return true;
    }
};