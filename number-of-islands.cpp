class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == '2' or grid[i][j] == '0') return;

        grid[i][j] = '2';

        // up
        helper(grid, i - 1, j);
        // down
        helper(grid, i + 1, j);
        // left
        helper(grid, i, j - 1);
        // right
        helper(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    helper(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
