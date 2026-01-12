class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        visited[row][col] = true;

        for(int i=0; i<4; i++){
            int nx = row + dx[i];
            int ny = col + dy[i];

            if(nx<0 || ny<0 || nx>=heights.size() || ny>=heights[0].size()) continue;

            if(visited[nx][ny]) continue;

            if(heights[nx][ny] >= heights[row][col]) dfs(nx, ny, heights, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        // base cases
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific_visited(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic_visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            if(!pacific_visited[i][0]){
                dfs(i, 0, heights, pacific_visited);
            }
        }
        for(int i=0; i<m; i++){
            if(!pacific_visited[0][i]){
                dfs(0, i, heights, pacific_visited);
            }
        }
        for(int i=0; i<n; i++){
            if(!atlantic_visited[i][m-1]){
                dfs(i, m-1, heights, atlantic_visited);
            }
        }
        for(int i=0; i<m; i++){
            if(!atlantic_visited[n-1][i]){
                dfs(n-1, i, heights,atlantic_visited);
            }
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlantic_visited[i][j] && pacific_visited[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};