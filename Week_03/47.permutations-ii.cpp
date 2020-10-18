/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (42.90%)
 * Likes:    2231
 * Dislikes: 65
 * Total Accepted:    379.9K
 * Total Submissions: 804.5K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        backTrace(ans, nums, 0);
        return ans;
    }

private:
    void backTrace(vector<vector<int>>& ans, vector<int> output, int first) {
        int n = output.size();
        if (first == n) {
            ans.push_back(output);
            return;
        }

        for (int i = first; i < n; ++i) {
            if ((i != first) && (output[i] == output[first])) continue;
            swap(output[first], output[i]);
            backTrace(ans, output, first + 1);
        }
        return;
    }
};
// @lc code=end

