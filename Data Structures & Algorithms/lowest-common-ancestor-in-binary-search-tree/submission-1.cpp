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
    int ancestor(TreeNode* root , TreeNode*p, TreeNode* q, TreeNode *& ans, int & indicator)
    {
        if(root==nullptr)return 0;
        int a = ancestor(root->left,p,q,ans,indicator);
        int b = ancestor(root->right,p,q,ans,indicator);
        cout<<"a+b : "<<a+b<<endl;
        if((((a+b)==2)||((a==1 || b==1)&&(root==p || root==q)))&&(ans->val==-1000))
        {
            ans=root;
            cout<<"root->val : "<<root->val<<endl;
        }
        return a+b+(root==p || root==q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans =new TreeNode(-1000);
        int indicator=0;
        ancestor(root,p,q,ans,indicator);
        return ans;
    }
};
