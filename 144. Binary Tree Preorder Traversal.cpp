/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

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
    void preOrder(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
      
      //1. Recursive
        vector<int> ans;
        preOrder(root,ans);        
        return ans;
      
      //2. Iterative
      vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode * curr = root;
        while(st.empty() == false){
            TreeNode * curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            if(curr->right != NULL) st.push(curr->right);
            if(curr->left != NULL) st.push(curr->left);
        }
        return ans;
    }
};
