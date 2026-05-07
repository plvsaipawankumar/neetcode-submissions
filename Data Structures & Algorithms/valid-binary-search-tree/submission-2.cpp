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
    void inorderTree(TreeNode * root,vector<int> &inorder)
    {
        if(root==nullptr)
        return ;
        if(root->left==nullptr && root->right==nullptr)
        {
            inorder.push_back(root->val);
            return ;
        }
        inorderTree(root->left,inorder);
        inorder.push_back(root->val);
        inorderTree(root->right,inorder);
        return ;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorderTree(root,inorder);
        int i,n=inorder.size();
        for(i=1;i<n;i++)
        {
            if(inorder[i-1]>=inorder[i])
                return false;
        }
        return true;
    }
};
