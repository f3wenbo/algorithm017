/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

#include <string>

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int first = 1;
        int second = s.at(0) != '0' ? 1 : 0;
        for(int i = 2; i <= s.size(); ++i) {
            int third = 0;
            if(s.at(i-1) != '0') third += second;
            if(isValid(s.at(i-2), s.at(i-1))) third += first;
            first = second;
            second = third;
        }
        return second;
    }
private:
    bool isValid(char a, char b){
        return (a == '1' && b <= '9') || (a == '2' && b <= '6');
    }
};
// @lc code=end