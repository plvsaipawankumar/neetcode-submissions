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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
            return "N,";
        string right = serialize(root->right);
        string left = serialize(root->left);
        return right+left+to_string(root->val)+",";
    }

    TreeNode* createTree(string data,int &pos)
    {
        if((data.size()==0 )|| (pos>=data.size()))return nullptr;
        int i,j,n=data.size(),val;
        for(i=pos;i<n;i++)
            if(data[i]==',')
                break;
        string value= data.substr(pos,i-pos);
        reverse(value.begin(),value.end());
        cout<<"value : "<<value<<" pos : "<<pos<<endl;
        pos=i+1;
        if(value=="N")
            return nullptr;
        else
            val = stoi(value);

        
        TreeNode* node= new TreeNode(val);
        node->left=createTree(data,pos);
        node->right=createTree(data,pos);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        reverse(data.begin(),data.end());
        cout<<"data : "<<data<<endl;
        int pos=1;
        return createTree(data,pos);
    }
};
