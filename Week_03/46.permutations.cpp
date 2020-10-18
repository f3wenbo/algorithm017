/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (58.38%)
 * Likes:    4536
 * Dislikes: 112
 * Total Accepted:    670.8K
 * Total outputmissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

#include <vector>

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backTrace(ans, nums, 0, nums.size());
        return ans;
    }

private:
    void backTrace(vector<vector<int>>& ans, vector<int>& output, int first, int len) {
        if (first == len) {
            ans.push_back(output);
            return;
        }

        for (int i = first; i < len; ++i) {
            swap(output[first], output[i]);
            backTrace(ans, output, first + 1, len);
            swap(output[first], output[i]);
        }
        return;
    }
};
// @lc code=end

