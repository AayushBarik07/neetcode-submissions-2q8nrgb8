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
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        // Both trees ended together
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        // Only one tree ended
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        // Node values are different
        if (root->val != subRoot->val) {
            return false;
        }

        bool left = sameTree(root-> left, subRoot-> left);
        bool right = sameTree(root-> right, subRoot-> right);

        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr) return false;
        bool ans = false;
        if(sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root-> left, subRoot) || isSubtree(root-> right, subRoot);
    }
};
