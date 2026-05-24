class Solution {
public:

    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>>que;
        que.push({entrance[0],entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps=0;

        while(!que.empty()){
            int N = que.size();

            while(N--){
                pair<int,int>temp = que.front();
                que.pop();

                int i = temp.first;
                int j = temp.second;

                if(temp!=make_pair(entrance[0],entrance[1]) && (i==0 || j==0 || i==n-1 || j==m-1)){
                    return steps;
                }

                for(auto &d : dir){
                    int newi = i + d[0];
                    int newj = j + d[1];

                    if(newi >= 0 && newi < n && newj>=0 && newj< m && maze[newi][newj]!= '+'){
                        que.push(make_pair(newi,newj));
                        maze[newi][newj]='+';
                    }
                }
                
            }
            steps++;
        }
        return -1;
    }
};