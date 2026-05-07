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
    int find(vector<int> inorder,int element,int l ,int r)
    {
        int i;
        for(i=l;i<=r;i++)
            if(inorder[i]==element)
                return i;
        return -1;
    }
    TreeNode* binaryTree(vector<int>& preorder,vector<int>& inorder,int l,int r,int & precount)
    {
        if(l>r)return nullptr;
        cout<<l<<" : "<<r<<" val : "<<preorder[l]<<endl;
        TreeNode* node = new TreeNode(preorder[precount]);
        precount++;
        if(r==l)
            return node;
        int x=find(inorder,preorder[precount-1],l,r);
        node->left = binaryTree(preorder,inorder,l,x-1,precount);
        node->right = binaryTree(preorder,inorder,x+1,r,precount);
        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=0,r=inorder.size()-1,precount=0;
        return binaryTree(preorder,inorder,l,r,precount);
    }
};
