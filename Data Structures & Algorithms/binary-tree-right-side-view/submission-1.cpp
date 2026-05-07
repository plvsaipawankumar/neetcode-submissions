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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp;
        queue<TreeNode*> q;
        int i,n;
        if(root==nullptr)return ans;
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            for(i=0;i<n;i++)
            {   
                temp=q.front();q.pop();
                if(temp->left!=nullptr)q.push(temp->left);
                if(temp->right!=nullptr)q.push(temp->right);
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};
