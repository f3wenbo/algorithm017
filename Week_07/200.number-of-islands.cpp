/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.50%)
 * Likes:    4265
 * Dislikes: 158
 * Total Accepted:    564.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

#include <vector>

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                ans += grid[row][col] - '0';
                dfs(grid, row, col, m, n);
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n) {
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0') return;
        grid[row][col] = '0';
        dfs(grid, row + 1, col, m, n);
        dfs(grid, row - 1, col, m, n);
        dfs(grid, row, col + 1, m, n);
        dfs(grid, row, col - 1, m, n);
    }
};
// @lc code=end