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
    int findElement(vector<int>& inorder, int len, int element) {
        for(int i=0;i<len;i++) {
            if(inorder[i] == element) return i;
        }
        return -1;
    }
    TreeNode* convertFrom_PreOrder_and_inOrder(vector<int>& preorder, vector<int>& inorder, int len,
    int &preIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& mp) {
        if(preIndex >= len || inorderStart > inorderEnd) {
            return NULL;
        }

        // step 1:
        int element = preorder[preIndex++];
        // step 2:
        TreeNode* root = new TreeNode(element);
        // step 3:
        // int pos = findElement(inorder, len, element);
        int pos = mp[element];                              // red
        // step 4;
        root-> left = convertFrom_PreOrder_and_inOrder(preorder, inorder, len, preIndex, inorderStart,
        pos - 1, mp);
        root-> right = convertFrom_PreOrder_and_inOrder(preorder, inorder, len, preIndex, pos + 1,
        inorderEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        unordered_map<int, int> mp;
        for(int i=0;i<len;i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* ans = convertFrom_PreOrder_and_inOrder(preorder, inorder, len, preIndex, inorderStart,
        inorderEnd, mp);

        return ans; 
    }
};
