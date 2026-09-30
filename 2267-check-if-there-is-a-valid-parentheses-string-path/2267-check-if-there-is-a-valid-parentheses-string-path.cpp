int dp[105][105][1005];

    bool fun(int i, int j, int open, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(open < 0) return false;

        if(j >= m || i >= n) return false;

        if(dp[i][j][open] != -1)
            return dp[i][j][open];

        if(grid[i][j] == '(')
            open++;
        else
            open--;

        if(open < 0) return false;
        
        if(dp[i][j][open] != -1)
            return dp[i][j][open];


        if(i == n - 1 && j == m - 1) return dp[i][j][open] = (open == 0);

        bool right = fun(i, j + 1, open, grid);
        bool down = fun(i + 1, j, open, grid);

        return dp[i][j][open] = right || down;
    }
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != '(')
            return false;

        if(grid[n-1][m-1] != ')')
            return false;

        memset(dp, -1, sizeof(dp));

        return fun(0, 0, 0, grid);
    }
};