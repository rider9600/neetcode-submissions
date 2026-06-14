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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;

        invertTree(root->left);
        invertTree(root->right);
        if (root->left == NULL && root->right != NULL) {
               cout<<(root?root->val:-1)<<" 1"<<endl;
            TreeNode* temp = root->right;
            root->right = NULL;
            root->left = temp;
        }else
        if (root->left != NULL && root->right == NULL) {
                  cout<<(root?root->val:-1)<<" 2"<<endl;
            TreeNode* temp = root->left;
            root->right = temp;
            root->left = NULL;
        }else
        if (root->left == NULL && root->right == NULL) {
                cout<<(root?root->val:-1)<<" 3"<<endl;
            return root;
        }else
        if (root->left != NULL && root->right != NULL) {
             cout<<(root?root->val:-1)<<" 4"<<endl;
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        return root;
    }
};
