/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (49.33%)
 * Likes:    3708
 * Dislikes: 70
 * Total Accepted:    467.6K
 * Total Submissions: 846.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
#include <vector>
#include <algorithm>
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int r = 1; r < m; ++r) dp[r][0] = dp[r-1][0] + grid[r][0];
        for (int c = 1; c < n; ++c) dp[0][c] = dp[0][c-1] + grid[0][c];

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[r][c] = std::min(dp[r-1][c], dp[r][c-1]) + grid[r][c];
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

