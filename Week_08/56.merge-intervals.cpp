/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.12%)
 * Likes:    5748
 * Dislikes: 341
 * Total Accepted:    737K
 * Total Submissions: 1.8M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;

        sort(intervals.begin(), intervals.end(), compare);

        for(int i = 0; i < intervals.size(); i++) {
            if(result.empty()) result.push_back(intervals[i]);
            if(intervals[i].front() > result.back().back()) {
                result.push_back(intervals[i]);
            } else {
                result.back().back() = max(result.back().back(), intervals[i].back());
            }
        }
        return result;
    }

private:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a.front() < b.front();
    }
};
// @lc code=end

