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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if(root->right==NULL && root->left==NULL){
            return 1;
        }
        int ans1=0,ans2=0;
        ans1=maxDepth(root->left);
        ans2=maxDepth(root->right);
        
        return max(ans1,ans2)+1;
    }
};
