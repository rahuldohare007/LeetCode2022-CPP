/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
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
    int check(vector<int> ans, int k)   //normal two sum problem
    {
        int s = 0;
        int e = ans.size() - 1;
        while (s < e)
        {
            if ((ans[s] + ans[e]) == k)
            {
                return 1;
            }
            else if ((ans[s] + ans[e]) > k)
            {
                e--;
            }
            else s++;
        }
        return 0;
    }
    void inorderTraversal(TreeNode *root, vector<int> &ans)  // because it traverse in sorted order
    {
        if (root == NULL)
        {
            return;
        }
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> ans; //to store nodes in sorted array
        inorderTraversal(root, ans);
        if (check(ans, k))
        {
            return true;
        }
        else 
            return false;
    }
};

     
    
