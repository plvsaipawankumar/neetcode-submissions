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
    TreeNode * invert(TreeNode* root)
    {

        if(root==nullptr ||(root->left==nullptr && root->right==nullptr))
            return root;
        TreeNode * temp;
        temp = root->right;
        root->right = invert(root->left);
        root->left = invert(temp);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
