/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (54.09%)
 * Likes:    1824
 * Dislikes: 150
 * Total Accepted:    633.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution {
public:
    // T:O(Nlog) S:O(1)
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    // T:O(N) S:O(1)
    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<int> alphas(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            alphas[s[i] - 'a']++;
            alphas[t[i] - 'a']--;
        }
        for (auto a : alphas) {
            if (a != 0) return false;
        }

        return true;
    }
};
// @lc code=end

