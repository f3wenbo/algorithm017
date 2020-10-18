/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (50.59%)
 * Likes:    1739
 * Dislikes: 71
 * Total Accepted:    312.9K
 * Total Submissions: 562.7K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        combine(1, n, k, ans, tmp);
        return ans;
    }

private:
    void combine(int start, int n, int k, vector<vector<int>>& ans, vector<int>& tmp) {
        if (k == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int i = start; n - i + 1 >= k; ++i) {
            tmp.push_back(i);
            combine(i + 1, n, k - 1, ans, tmp);
            tmp.pop_back();
        }
        return;
    }
};
// @lc code=end

