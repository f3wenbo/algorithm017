/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (53.06%)
 * Likes:    1750
 * Dislikes: 64
 * Total Accepted:    538.1K
 * Total Submissions: 956.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [1,2]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // T:O(N) S:O(N)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> preorder = [&](TreeNode* t) {
            if (!t) return;
            ans.push_back(t->val);
            preorder(t->left);
            preorder(t->right);
        };
        preorder(root);
        return ans;
    }
};
// @lc code=end

