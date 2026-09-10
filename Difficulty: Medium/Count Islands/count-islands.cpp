class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& vis){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size(); 

        while(!q.empty()){
            int ro = q.front().first;
            int co = q.front().second;
            q.pop(); 

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int nrow = ro + delrow;
                    int ncol = co + delcol;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                       && !vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                        vis[nrow][ncol] = 1; 
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    cnt++;
                    bfs(grid, i, j, vis);
                }
            }
        }

        return cnt;     
    }
};