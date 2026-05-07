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
    int ans=-3000000;
    int maxPath(TreeNode* root )
    {
        if(root==nullptr)
            return -3000000;
        int left=maxPath(root->left);
        int right = maxPath(root->right);
        int curr= root->val;
        int maximum = max(max(left+curr,right+curr),curr);
        ans= max(max((curr+left+right),maximum),ans);
        cout<<"left : "<<left<<" right : "<<right<<" curr : "<<curr<<" maximum : "<<maximum<<" total : "<<curr+left+right<<" ans : "<<ans<<endl;
        return maximum;        
    }
    int maxPathSum(TreeNode* root) {
        int x=maxPath(root);
        return ans;
    }
};
