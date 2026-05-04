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
    bool solve(TreeNode* root, long long int lb, long long int ub) {
        if(!root) return true;

        if(lb < root-> val && root-> val < ub) {
            int leftAns = solve(root-> left, lb, root-> val);
            int rightAns = solve(root-> right, root-> val, ub);
            return leftAns && rightAns;
        }
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int lb = -4294967296;
        long long int ub = 4294967296;
        bool result = solve(root, lb, ub);
        return result;
    }
};
