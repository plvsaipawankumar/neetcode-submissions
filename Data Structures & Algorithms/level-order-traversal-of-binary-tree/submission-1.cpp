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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        if(root == nullptr)return ans;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode * top = qu.front();qu.pop();
                level.push_back(top->val);
                if(top->left!=nullptr)
                    qu.push(top->left);
                if(top->right!=nullptr)
                    qu.push(top->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
