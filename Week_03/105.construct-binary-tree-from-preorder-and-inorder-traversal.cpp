/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.99%)
 * Likes:    3965
 * Dislikes: 106
 * Total Accepted:    401.1K
 * Total Submissions: 805.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int pstart, int pend, int istart, int iend) {
        if (pstart > pend) return nullptr;

        TreeNode* root = new TreeNode(preorder[pstart]);
        int pos = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == root->val) {
                pos = i;
                break;
            }
        }

        root->left = buildTree(preorder, inorder, pstart + 1, pstart + pos - istart, istart, pos - 1);
        root->right = buildTree(preorder, inorder, pend - (iend - pos) + 1, pend, pos + 1, iend);
        return root;
    }
};
// @lc code=end

