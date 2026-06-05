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
    int ans=0;
    int lenght(TreeNode * root)
    {
        if(root==nullptr)
            return 0;
        
        int left = lenght(root->left);
        int right = lenght(root->right);
        ans = max(ans,right+left);
        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int temp = lenght(root);
        return ans;
    }
};
