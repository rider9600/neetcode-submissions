
class Solution {
   public:
    int ans = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->right == NULL && root->left == NULL) {
            ans=max(ans,1);
            return 1;
        }
        int ans1 = 0, ans2 = 0;
        ans1 = maxDepth(root->left);
        ans2 = maxDepth(root->right);
        ans=max(ans,ans1+ans2+1);
        return max(ans1,ans2) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans-1;
    }
};
