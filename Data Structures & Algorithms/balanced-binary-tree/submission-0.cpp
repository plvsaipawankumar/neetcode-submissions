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
    int balancedTree(TreeNode* root, bool & ans)
    {
        if(root==nullptr )
            return 0;
        int left = balancedTree(root->left,ans);
        int right = balancedTree(root->right,ans);
        ans = ans && (abs(left-right)<2);
        cout<<"root->val :"<<root->val<<" left : "<<left<<" right : "<<right<<" ans :"<<ans<<endl;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        bool ans;
        int x= balancedTree(root,ans);
        return ans;
    }
};
