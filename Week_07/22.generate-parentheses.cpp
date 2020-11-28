/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (63.85%)
 * Likes:    6502
 * Dislikes: 300
 * Total Accepted:    640.3K
 * Total Submissions: 996.3K
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, "", n, n, n);
        return ans;
    }

private:
    void generate(vector<string>& answer, string s, int &n, int open, int close) {
        if (s.size() == 2 * n) {
            answer.push_back(s);
            return;
        }

        if (open > 0) generate(answer, s + "(", n, open - 1, close);

        if (close > open) generate(answer, s + ")", n, open, close-1);
    }
};
// @lc code=end

