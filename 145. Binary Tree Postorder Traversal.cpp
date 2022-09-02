/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:
The number of the nodes in the tree is in the range [0, 100].
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
  //1. Recursion
    // void postOrder(TreeNode* root, vector<int> &ans){
    //     if(root == NULL){
    //         return;
    //     }
    //     postOrder(root->left,ans);
    //     postOrder(root->right,ans);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     postOrder(root,ans);        
    //     return ans;
        
  //2. Iterative
        if(!root) 
            return {};
        vector<int> ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        
        while(s1.size()){
            auto node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(s2.size())
            ans.push_back(s2.top()->val), s2.pop();
        return ans ;
    }
};
