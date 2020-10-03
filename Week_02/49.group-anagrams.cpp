/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (50.48%)
 * Likes:    4128
 * Dislikes: 198
 * Total Accepted:    757.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // T:O(N*KlogK) S:O(N)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int idx = 0;
        unordered_map<string, int> group;
        string tmp;
        for (auto str : strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (group.count(tmp)) {
                ans[group[tmp]].push_back(str);
            } else {
                vector<string> sub(1, str);
                ans.push_back(sub);
                group[tmp] = idx++;
            }
        }
        return ans;
    }
};
// @lc code=end

