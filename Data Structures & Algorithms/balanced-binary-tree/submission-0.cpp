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
    int findDepth(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = findDepth(root-> left);
        int rightHeight = findDepth(root-> right);

        int ans = 1 + max(leftHeight, rightHeight);
        return ans; 
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight = findDepth(root-> left);
        int rightHeight = findDepth(root-> right);

        int diff = abs(leftHeight - rightHeight);

        bool ans = (diff <= 1);

        bool leftAns = isBalanced(root-> left);
        bool rightAns = isBalanced(root-> right);

        if(ans && leftAns && rightAns) return true;
        return false;
    }
};