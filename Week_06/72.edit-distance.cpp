/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (40.07%)
 * Likes:    4537
 * Dislikes: 60
 * Total Accepted:    305.9K
 * Total Submissions: 671.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
      if (word1.empty() && word2.empty()) return 0;
      int m = word1.size() + 1, n = word2.size() + 1;
      vector<vector<int>> d(m, vector<int>(n));

      for (int i = 0; i < m; ++i)
        d[i][0] = i;
      for (int j = 0; j < n; ++j)
        d[0][j] = j;

      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          if (word1[i-1] == word2[j-1]) {
            d[i][j] = d[i-1][j-1];
          } else {
            d[i][j] = min(d[i-1][j], min(d[i][j-1], d[i-1][j-1])) + 1;
          }
        }
      }
      return d[m-1][n-1];
    }
};
// @lc code=end

