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
    void del(TreeNode* prev, TreeNode* root) {
          if (root == NULL) return;
        if (root->right == NULL && root->left != NULL) {
            if (prev->right == root) {
                prev->right = root->left;
            } else if (prev->left == root) {
                prev->left = root->left;
            }
        } else if (root->right != NULL && root->left == NULL) {
            if (prev->right == root) {
                prev->right = root->right;
            } else if (prev->left == root) {
                prev->left = root->right;
            }
        } else if (root->right != NULL && root->left != NULL) {
            if (prev->right == root) {
                TreeNode* tt = root->left;
                while (tt->right != NULL) {
                    tt = tt->right;
                };
                tt->right = root->right;
                prev->right = root->left;
            } else if (prev->left == root) {
                TreeNode* tt = root->left;
                while (tt->right != NULL) {
                    tt = tt->right;
                };
                tt->right = root->right;
                prev->left = root->left;
            }
        } else if (root->right == NULL && root->left == NULL) {
            if (prev->right == root) {
                prev->right = NULL;
            } else if (prev->left == root) {
                prev->left = NULL;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = NULL;
        TreeNode* temp = root;
        while (temp != NULL) {
            if (temp->val == key) {
                break;
            } else if (temp->val > key) {
                prev = temp;
                temp = temp->left;
            } else {
                prev = temp;
                temp = temp->right;
            }
        }
        if (temp == NULL) return root;

        // root deletion
        if (prev == NULL) {
            TreeNode dummy(0);
            dummy.left = root;

            del(&dummy, root);

            return dummy.left;
        }

        del(prev, temp);
        return root;

        
    }
};
