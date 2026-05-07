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
    string traversal(TreeNode * root,bool &ans,string match="")
    {
        if(root==nullptr)return "";
        string left = traversal(root->left,ans,match);
        string right = traversal(root->right,ans,match);
        ans = ans || (match==(left+to_string(root->val)+right));
        return left+to_string(root->val)+right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans;
        string sub= traversal(subRoot,ans,"");
        
        string s =  traversal(root,ans,sub);
        return ans;
    }
};
